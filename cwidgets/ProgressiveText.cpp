#include "ProgressiveText.hpp"

ProgressiveText::ProgressiveText()
{
    createObjects();
    createConnexions();
}

//Organisers
void ProgressiveText::createObjects()
{
    mCharCount      = 0;
    mLoopSound      = new QSoundEffect;
    mCharTimer      = new QTimer;
}
void ProgressiveText::createConnexions()
{
    connect(mCharTimer, SIGNAL(timeout()), this, SLOT(appendCharToText()));
}

//Methods
bool ProgressiveText::isFinish()
{
    if (mCharCount == 0)
        return true;
    else
        return false;
}
void ProgressiveText::setProgressiveText(QString text, int speed)
{
    mString     = text;
    mTextSpeed  = speed;

    if (mTextSpeed == 0) {
        this->setText(mString);
    } else {
        this->clear();
        this->appendCharToText();

        if (mSoundBool) {
            mLoopSound->setLoopCount(QSoundEffect::Infinite);
            mLoopSound->play();
        }
    }
}
void ProgressiveText::setSoundSource(QUrl url, bool play)
{
    mLoopSound->setSource(url);
    mSoundBool = play;
}

//Slots
void ProgressiveText::appendCharToText()
{
    if (mCharCount < mString.length()) {
        this->moveCursor(QTextCursor::End);
        this->insertPlainText(mString.at(mCharCount++));

        mCharTimer->start(mTextSpeed);
    } else {
        mCharTimer->stop();
        mLoopSound->setLoopCount(0);
        mCharCount = 0;
    }
}
