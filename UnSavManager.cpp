#include "UnSavManager.hpp"

UnSavManager::UnSavManager()// : QMainWindow(parent)
{
    createObjects();
    createConnexions();
    createInterface();
    createObjectName();
    createSettings();

    loadBackupSaves();
    loadCurrentSave();
}
UnSavManager::~UnSavManager()
{
}

//Organisers
void UnSavManager::createObjects()
{
    mGameProcess    = new QProcess;
    mAboutDialog    = new About;
    mSetgsDialog    = new Settings(this);
    mMesgsDialog    = new MessageDialog(this);
    mBannerHbox     = new QHBoxLayout;
    mTButtonHBox    = new QHBoxLayout;
    mActButGroup    = new QGridLayout;
    mRightVBox      = new QVBoxLayout;
    mSavListHBox    = new QHBoxLayout;
    mBannerPixmap   = new QLabel;
    mBannerTButton  = new TPushButton(this);//this = The movable Window
    mAbtButton      = new QPushButton;
    mMinButton      = new QPushButton;
    mClozButton     = new QPushButton;
    mLoadButton     = new QPushButton;
    mSaveButton     = new QPushButton;
    mStigButton     = new QPushButton;
    mLachButton     = new QPushButton;
    mSavListLeft    = new SaveListWidget;
    mParentVbox     = new QVBoxLayout;
    mSavListRight   = new SaveListWidget;
}
void UnSavManager::createConnexions()
{
    connect(mAbtButton,     SIGNAL(clicked()),  mAboutDialog,   SLOT(exec()));
    connect(mMinButton,     SIGNAL(clicked()),  this,           SLOT(minimiseManager()));
    connect(mClozButton,    SIGNAL(clicked()),  this,           SLOT(close()));

    connect(mSaveButton,    SIGNAL(clicked()),  this,           SLOT(moveLeft()));
    connect(mLoadButton,    SIGNAL(clicked()),  this,           SLOT(moveRight()));
    connect(mStigButton,    SIGNAL(clicked()),  mSetgsDialog,   SLOT(exec()));
    connect(mLachButton,    SIGNAL(clicked()),  this,           SLOT(launchGame()));

    connect(mSavListLeft,   SIGNAL(saveFolderDelete(QString)),  this,   SLOT(deleteSave(QString)));
}
void UnSavManager::createInterface()
{
    //Header
    mBannerHbox->addWidget(mAbtButton,  1, Qt::AlignRight | Qt::AlignTop);
    mBannerHbox->addWidget(mMinButton,  0, Qt::AlignRight | Qt::AlignTop);
    mBannerHbox->addWidget(mClozButton, 0, Qt::AlignRight | Qt::AlignTop);

    mBannerPixmap->setPixmap(QPixmap(":imgs/ban"));
    mBannerPixmap->setAlignment(Qt::AlignCenter);
    mBannerPixmap->setLayout(mBannerHbox);
    mBannerPixmap->setContentsMargins(-7, -7, -7, -7);

    mTButtonHBox->addWidget(mBannerPixmap,1);

    mBannerTButton->setLayout(mTButtonHBox);
    mBannerTButton->setFixedHeight(90);
    mBannerTButton->setContentsMargins(-11, -11, -11, -11);
    //End Header

    mSavListLeft->setFixedHeight(368);

    mSavListRight->setFixedHeight(90);

    mActButGroup->addWidget(mLoadButton, 0, 0, 1, 1);
    mActButGroup->addWidget(mSaveButton, 1, 0, 1, 1);
    mActButGroup->addWidget(mStigButton, 0, 1, 1, 1);
    mActButGroup->addWidget(mLachButton, 1, 1, 1, 1);
    mActButGroup->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    mRightVBox->addWidget(mSavListRight);
    mRightVBox->addLayout(mActButGroup);
    mRightVBox->setAlignment(Qt::AlignTop);

    mSavListHBox->addWidget(mSavListLeft, 0, Qt::AlignTop);
    mSavListHBox->addWidget(new QHSpace(10));
    mSavListHBox->addLayout(mRightVBox);

    mParentVbox->addWidget(mBannerTButton);
    mParentVbox->addLayout(mSavListHBox);
}
void UnSavManager::createObjectName()
{
    mAbtButton->setObjectName("Button_About");
    mMinButton->setObjectName("Button_Minimize");
    mClozButton->setObjectName("Button_Close");
    mBannerTButton->setObjectName("Button_Banner");
    mBannerPixmap->setObjectName("Label_Banner");
    mLoadButton->setObjectName("Button_LOAD");
    mSaveButton->setObjectName("Button_SAVE");
    mStigButton->setObjectName("Button_SETTINGS");
    mLachButton->setObjectName("Button_LAUNCH");
    mSavListLeft->setObjectName("ListWidget_Saves");
    mSavListRight->setObjectName("ListWidget_Saves");
    mMesgsDialog->setObjectName("Dialog_MessBox");
    mAboutDialog->setObjectName("Dialog_About");
    mSetgsDialog->setObjectName("Dialog_Settings");
    this->setObjectName("Widget_Parent");
}
void UnSavManager::createSettings()
{
    this->setFixedSize(800, 486);
    this->setLayout(mParentVbox);
    this->setWindowTitle("UNDERTALE Save Manager");
    this->setWindowFlags(Qt::FramelessWindowHint);
    qApp->setStyleSheet(mSetgsDialog->currentTheme());
}

//Methods
void UnSavManager::loadBackupSaves()
{
    mSavListLeft->clearAll();

    QDir storDir (mSetgsDialog->storageSaves());

    foreach (QString folder, storDir.entryList(QDir::NoDotAndDotDot|QDir::AllDirs))
    {
        mSavListLeft->setSaveFolder(mSavListLeft->count(), folder);

        QSettings *settings = new QSettings(storDir.path()+"/"+folder+"/undertale.ini", QSettings::IniFormat);

        //Check if ini contains values
        if( settings->contains("Name") && settings->contains("Love") &&
            settings->contains("Time") && settings->contains("Room"))
        {
            UnProfile *profile = new UnProfile;
                profile->setName(settings->value("Name"));
                profile->setLove(settings->value("Love"));
                profile->setTime(settings->value("Time"));
                profile->setRoom(settings->value("Room"));

            mSavListLeft->addSave(profile);
        }
    }
}
void UnSavManager::loadCurrentSave()
{
    mSavListRight->clearAll();

    QSettings  *setting = new QSettings(mSetgsDialog->currentSave()+"/undertale.ini", QSettings::IniFormat);

    //Check if ini contains values
    if (setting->contains("Name") && setting->contains("Love") && setting->contains("Time") && setting->contains("Room")) {
        UnProfile *profile = new UnProfile;
            profile->setName(setting->value("Name"));
            profile->setLove(setting->value("Love"));
            profile->setTime(setting->value("Time"));
            profile->setRoom(setting->value("Room"));

        mSavListRight->addSave(profile);
    }
}
bool UnSavManager::copySave(QString from, QString dest)
{
    QDir dirF (from);
    QDir dirD (dest);

    if (!dirD.exists()) {
        dirD.mkpath(dest);
    }

    from += QDir::separator();
    dest += QDir::separator();

    foreach (QString file, dirF.entryList(QDir::Files)) {
        QString cFrom = from + file;
        QString cDest = dest + file;

        if (!QFile::copy(cFrom, cDest)) {
            return false;
        }
    }
    return true;
}
bool UnSavManager::alreadyExist(QString from, QString dest)
{
    QFile fromFile(from+"/undertale.ini");
    QFile destFile(dest+"/undertale.ini");

    QByteArray fromHash;
    QByteArray destHash;

    if (fromFile.open(QIODevice::ReadOnly)) {
        QByteArray fromByte = fromFile.readAll();
        fromHash = QCryptographicHash::hash(fromByte, QCryptographicHash::Md5);
    }

    if (destFile.open(QIODevice::ReadOnly)) {
        QByteArray destByte = destFile.readAll();
        destHash = QCryptographicHash::hash(destByte, QCryptographicHash::Md5);
    }

    if (destHash.toHex() == fromHash.toHex()) {
        return true;
    }
    else {
        return false;
    }
}

//Slots
void UnSavManager::moveRight()
{
    QString fromString = mSetgsDialog->storageSaves()+"/"+mSavListLeft->currentSaveFolder();
    QString destString = mSetgsDialog->currentSave();

    bool saveExist = QFile::exists(mSetgsDialog->currentSave()+"/undertale.ini");

    if (mSavListLeft->currentSaveID() >= 0) {
        QDir dirF (mSetgsDialog->storageSaves());

        bool isBackup = false;

        foreach (QString file, dirF.entryList(QDir::NoDotAndDotDot|QDir::AllDirs))
        {
            QString curFile = mSetgsDialog->storageSaves()+"/"+file;

            if (alreadyExist(curFile, mSetgsDialog->currentSave())) {
                isBackup = true;
            }
        }

        if (saveExist && !isBackup) {//If current save 'exist' AND 'doesn't backup'
                mMesgsDialog->setDialogPixmap(QPixmap(":imgs/avatars/sans"));
                mMesgsDialog->setDialogSize(QSize(600, 140));
                mMesgsDialog->setType(MessageDialog::BoxType::Choice);
                mMesgsDialog->setDialogText("* This save are no backup.\n\n"
                                            "* Do you really want replacing ?\n\n"
                                            "  Y for Yes / N for No");
                mMesgsDialog->exec();

                if (mMesgsDialog->isAccepted()) {
                    QDir dir(mSetgsDialog->currentSave());

                    if (dir.removeRecursively()) {
                        mSavListRight->clearAll();
                    }

                    copySave(fromString, destString);
                    loadCurrentSave();
                }
        }
        else {
            if (alreadyExist(fromString, destString)) {
                mMesgsDialog->setDialogPixmap(QPixmap(":imgs/avatars/toriel"));
                mMesgsDialog->setDialogSize(QSize(600, 140));
                mMesgsDialog->setType(MessageDialog::BoxType::Confirm);
                mMesgsDialog->setDialogText("* This save aready exist.\n\n"
                                            "* You can't load this save\n\n"
                                            "  ENTER for closing this box");
                mMesgsDialog->exec();
            } else {
                QDir dir(mSetgsDialog->currentSave());

                if (dir.removeRecursively()) {
                    mSavListRight->clearAll();
                }

                copySave(fromString, destString);

                loadCurrentSave();
            }
        }
    }
}
void UnSavManager::moveLeft()
{
    QDir dirF (mSetgsDialog->storageSaves());

    bool exist = false;

    foreach (QString file, dirF.entryList(QDir::NoDotAndDotDot|QDir::AllDirs))
    {
        QString curFile = mSetgsDialog->storageSaves()+"/"+file;

        if (alreadyExist(curFile, mSetgsDialog->currentSave())) {
            exist = true;
        }
    }

    if (exist) {//If current save already exist
            mMesgsDialog->setDialogPixmap(QPixmap(":imgs/avatars/toriel"));
            mMesgsDialog->setDialogSize(QSize(600, 140));
            mMesgsDialog->setType(MessageDialog::BoxType::Confirm);
            mMesgsDialog->setDialogText("* This save aready exist.\n\n"
                                        "* You can't backup this save\n\n"
                                        "  ENTER for closing this box");
            mMesgsDialog->exec();
    }
    else {
        copySave(mSetgsDialog->currentSave(), mSetgsDialog->storageSaves()+"/UNDERTALE_"+QString::number(mSavListLeft->count()+1));

        loadBackupSaves();
    }
}
void UnSavManager::minimiseManager()
{
    this->setWindowState(Qt::WindowMinimized);
}
void UnSavManager::launchGame()
{
    if (mSetgsDialog->gameDirectory().isEmpty()) {

        mMesgsDialog->setDialogPixmap(QPixmap(":imgs/avatars/flowey"));
        mMesgsDialog->setDialogSize(QSize(600, 140));
        mMesgsDialog->setType(MessageDialog::BoxType::Confirm);
        mMesgsDialog->setDialogText("* Path to the game not initialised.\n\n"
                                    "* Please define it in 'SETTINGS'\n\n"
                                    "  ENTER for closing this box");
        mMesgsDialog->exec();
    } else {
        mGameProcess->start(mSetgsDialog->gameDirectory());
    }
}
void UnSavManager::deleteSave(QString folder)
{
    if (!folder.isEmpty()) {
        mMesgsDialog->setDialogPixmap(QPixmap(":imgs/avatars/sans"));
        mMesgsDialog->setDialogSize(QSize(640, 140));
        mMesgsDialog->setType(MessageDialog::BoxType::Choice);
        mMesgsDialog->setDialogText("* This awesome save will be removed.\n\n"
                                    "* Are you really sure you want do this ?\n\n"
                                    "  Y for Yes / N for No");
        mMesgsDialog->exec();

        if (mMesgsDialog->isAccepted()) {
            QDir dir(mSetgsDialog->storageSaves()+"/"+folder);

            if (dir.removeRecursively()) {
                mSavListRight->clearAll();
            }

            loadBackupSaves();
            loadCurrentSave();
        }
    }
}
