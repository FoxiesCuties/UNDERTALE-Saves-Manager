#ifndef PROGRESSIVETEXT_HPP
#define PROGRESSIVETEXT_HPP

#include <QtWidgets>
#include <QSoundEffect>

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

    int             mCharCount;
    QString         mString;
    QTimer          *mCharTimer;
    QSoundEffect    *mLoopSound;
};

#endif // PROGRESSIVETEXT_HPP
