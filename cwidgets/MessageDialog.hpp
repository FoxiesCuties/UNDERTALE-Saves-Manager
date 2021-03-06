#ifndef MESSAGEDIALOG_HPP
#define MESSAGEDIALOG_HPP

#include <QtWidgets>

#include "cwidgets/QHSpace.hpp"
#include "cwidgets/ProgressiveText.hpp"

class MessageDialog : public QDialog
{
    Q_OBJECT

public:

    enum class BoxType : int {Choice = 0, Confirm = 1};

    MessageDialog(QWidget * parent = 0);

    void createObjects();
    void createInterface();
    void createSettings();

    void setDialogSize(QSize size);
    void setDialogText(QString text, int speed);
    void setDialogSound(QUrl url, bool play);
    void setDialogPixmap(QPixmap pixmap);

    void setType(BoxType type);

    //Events
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);
    
private:

    BoxType         mType;

    QLabel          *mMessageLabel;
    ProgressiveText *mMessageTextEdit;
    QHBoxLayout     *mMessageHBox;
};

#endif // MESSAGEDIALOG_HPP
