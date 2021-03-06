#include "MessageDialog.hpp"

MessageDialog::MessageDialog(QWidget *parent) : QDialog(parent)
{
    createObjects();
    createInterface();
    createSettings();
}

//Organisers
void MessageDialog::createObjects()
{
    mMessageLabel       = new QLabel;
    mMessageTextEdit    = new ProgressiveText;
    mMessageHBox        = new QHBoxLayout;
}
void MessageDialog::createInterface()
{
    mMessageTextEdit->setReadOnly(true);
    mMessageTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    mMessageTextEdit->viewport()->setCursor(Qt::ArrowCursor);

    mMessageHBox->addWidget(mMessageLabel, 1, Qt::AlignVCenter);
    mMessageHBox->addWidget(new QHSpace(20));
    mMessageHBox->addWidget(mMessageTextEdit, Qt::AlignVCenter | Qt::AlignLeft);
    mMessageHBox->setContentsMargins(30, 11, 11, 11);
}
void MessageDialog::createSettings()
{
    this->setLayout(mMessageHBox);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);//Qt::Window block events on modal box.
}

//Methods
void MessageDialog::setType(BoxType type)
{
    mType = type;
}
void MessageDialog::setDialogSize(QSize size)
{
    this->setFixedSize(size);
}
void MessageDialog::setDialogText(QString text, int speed)
{
    mMessageTextEdit->setProgressiveText(text, speed);
}
void MessageDialog::setDialogSound(QUrl url, bool play)
{
    mMessageTextEdit->setSoundSource(url, play);
}
void MessageDialog::setDialogPixmap(QPixmap pixmap)
{
    mMessageLabel->setPixmap(pixmap);
}

//Events
void MessageDialog::keyPressEvent(QKeyEvent *event)
{
    if (mMessageTextEdit->isFinish()) {
        if (mType == BoxType::Choice) {
            if (event->key() == Qt::Key_Y) {
                accept();
                close();
            }
            if (event->key() == Qt::Key_N) {
                reject();
                close();
            }
        } else if (mType == BoxType::Confirm) {
            if (event->key() == Qt::Key_Return) {
                accept();
                close();
            }
        }
    }
}
void MessageDialog::closeEvent(QCloseEvent *event)
{
    //Accept only internal closing events
    event->setAccepted(!event->spontaneous());
}
