#ifndef UNSAVMANAGER_HPP
#define UNSAVMANAGER_HPP

#include <QtWidgets>

#include "About.hpp"
#include "Settings.hpp"
#include "cwidgets/QHSpace.hpp"
#include "cwidgets/UnProfile.hpp"
#include "cwidgets/TPushButton.hpp"
#include "cwidgets/MessageDialog.hpp"
#include "cwidgets/SaveListWidget.hpp"

class UnSavManager : public QWidget
{
    Q_OBJECT

public:

    UnSavManager();
    ~UnSavManager();

    //Organisers
    void createObjects();
    void createConnexions();
    void createInterface();
    void createObjectName();
    void createSettings();

    //Functions
    void loadBackupSaves();
    void loadCurrentSave();
    bool copySave(QString from, QString dest);
    bool alreadyExist(QString from, QString dest);

public slots:

    void moveRight();
    void moveLeft();
    void minimiseManager();
    void launchGame();

private:

    QProcess        *mGameProcess;
    QLabel          *mBannerPixmap;
    QHBoxLayout     *mTButtonHBox;
    QGridLayout     *mActButGroup;
    QVBoxLayout     *mRightVBox;
    QHBoxLayout     *mSavListHBox;
    QHBoxLayout     *mBannerHbox;
    TPushButton     *mBannerTButton;
    QPushButton     *mLoadButton;
    QPushButton     *mSaveButton;
    QPushButton     *mStigButton;
    QPushButton     *mLachButton;
    QPushButton     *mAbtButton;
    QPushButton     *mMinButton;
    QPushButton     *mClozButton;
    QVBoxLayout     *mParentVbox;
    SaveListWidget  *mSavListLeft;
    SaveListWidget  *mSavListRight;

    //External Dialogs
    About           *mAboutDialog;
    Settings        *mSetgsDialog;
    MessageDialog   *mMesgsDialog;
};

#endif // UNSAVMANAGER_HPP
