#include "ProgressiveText.hpp"

ProgressiveText::ProgressiveText()
{
    createObjects();
    createConnexions();
}

//Organisers
void ProgressiveText::createObjects()
{
    mCharCount  = 0;
    mLoopSound  = new QSoundEffect;
    mCharTimer  = new QTimer;
}
void ProgressiveText::createConnexions()
{
    connect(mCharTimer, SIGNAL(timeout()), this, SLOT(appendCharToText()));
}

//Methods
void ProgressiveText::setProgressiveText(QString text)
{
    mString = text;

    mLoopSound->setSource(QUrl("qrc:snds/chat"));
    mLoopSound->setLoopCount(QSoundEffect::Infinite);
    mLoopSound->play();

    this->clear();
    this->appendCharToText();
}

//Slots
void ProgressiveText::appendCharToText()
{
    if (mCharCount < mString.length()) {
        this->moveCursor(QTextCursor::End);
        this->insertPlainText(mString.at(mCharCount++));

        mCharTimer->start(25);
    } else {
        mCharTimer->stop();
        mLoopSound->setLoopCount(0);
        mCharCount=0;
    }
}
