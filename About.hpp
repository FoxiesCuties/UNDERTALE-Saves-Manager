#ifndef ABOUT_HPP
#define ABOUT_HPP

#include <QtWidgets>

#include "cwidgets/TPushButton.hpp"

class About : public QDialog
{
    Q_OBJECT

public:

    About();

    void createObjects();
    void createConnexions();
    void createInterface();
    void createObjectName();
    void createSettings();

    //Events
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:

    void openGitHubProject();

private:

    QVBoxLayout     *mAboutVBox;
    QPushButton     *mAboutCButton;
    QHBoxLayout     *mAboutTHbox;
    TPushButton     *mAboutTButton;
    QVBoxLayout     *mAboutVbox;
    QLabel          *mAboutPixmap;
    QVBoxLayout     *mTAboutVBox;
    QLabel          *mAboutTitle;
    QLabel          *mAboutDev;
    QLabel          *mAboutAst;
    QPushButton     *mAboutGButton;
};

#endif // ABOUT_HPP
