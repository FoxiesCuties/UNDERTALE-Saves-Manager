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

    bool isAccepted();
    void setDialogSize(QSize size);
    void setDialogText(QString text);
    void setDialogPixmap(QPixmap pixmap);

    void setType(BoxType type);

    //Events
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);
    
private:

    BoxType         mType;
    bool            mValue;

    QLabel          *mMessageLabel;
    ProgressiveText *mMessageTextEdit;
    QHBoxLayout     *mMessageHBox;
};

#endif // MESSAGEDIALOG_HPP
