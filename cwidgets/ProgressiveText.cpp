#include "ProgressiveText.hpp"

ProgressiveText::ProgressiveText()
{
    createObjects();
    createConnexions();

    mLoopSound->setSource(QUrl("qrc:snds/chat"));

}

//Organisers
void ProgressiveText::createObjects()
{
    mCharCount      = 0;
    mLoopSound      = new QSoundEffect;
    mCharTimer      = new QTimer;
    mTextSettings   = new Settings;
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
void ProgressiveText::setProgressiveText(QString text)
{
    mString     = text;
    mSoundBool  = mTextSettings->soundEnabled();
    mTextSpeed  = mTextSettings->textSpeed();

    if (mTextSettings->textSpeed() == 0)
    {
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
