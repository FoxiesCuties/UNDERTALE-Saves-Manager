#ifndef PROGRESSIVETEXT_HPP
#define PROGRESSIVETEXT_HPP

#include <QtWidgets>
#include <QSoundEffect>

#include "Settings.hpp"

class ProgressiveText : public QTextEdit
{
    Q_OBJECT

public:

    ProgressiveText();

    void createObjects();
    void createConnexions();

    bool isFinish();
    void setProgressiveText(QString text);

public slots:

    void appendCharToText();

private:

    Settings        *mTextSettings;

    bool            mSoundBool;
    int             mCharCount;
    int             mTextSpeed;

    QString         mString;
    QTimer          *mCharTimer;
    QSoundEffect    *mLoopSound;
};

#endif // PROGRESSIVETEXT_HPP
