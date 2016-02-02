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
    void setProgressiveText(QString text, int speed);
    void setSoundSource(QUrl url, bool play);

public slots:

    void appendCharToText();

private:

    bool            mSoundBool;
    int             mCharCount;
    int             mTextSpeed;

    QString         mString;
    QTimer          *mCharTimer;
    QSoundEffect    *mLoopSound;
};

#endif // PROGRESSIVETEXT_HPP
