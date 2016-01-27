#include "Settings.hpp"

Settings::Settings(QWidget *parent) : QDialog(parent)
{
    createObjects();
    createConnexions();
    createInterface();
    createObjectName();
    createSettings();
}

//Organizers
void Settings::createObjects()
{
    //Declaration Only
    mCSSFile            = new QFile;
    mGameLab            = new QLabel;
    mGameLin            = new QLineEdit;
    mGameBut            = new QPushButton;
    mStorLab            = new QLabel;
    mStorLin            = new QLineEdit;
    mStorBut            = new QPushButton;
    mExecLab            = new QLabel;
    mExecLin            = new QLineEdit;
    mExecBut            = new QPushButton;
    mSettingsGrid       = new QGridLayout;
    mSettingsCButton    = new QPushButton;
    mSettingsTHbox      = new QHBoxLayout;
    mSettingsTButton    = new TPushButton(this);
    mSettingsVbox       = new QVBoxLayout;
    mSettingsPixmap     = new QLabel;
    mTSettingsVBox      = new QVBoxLayout;
    mSettingsTitle      = new QLabel;

    mAppDataLocal   = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
    mDocumentsData  = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    mCFGSettings    = new QSettings(QCoreApplication::applicationDirPath()+"/config.cfg", QSettings::IniFormat);
    mCSSFile->setFileName(":themes/thmD");
    mCSSFile->open(QIODevice::ReadOnly | QIODevice::Text);
}
void Settings::createConnexions()
{
    connect(mGameBut,               SIGNAL(clicked()),  this,   SLOT(setCurrentSave()));
    connect(mStorBut,               SIGNAL(clicked()),  this,   SLOT(setStorageSaves()));
    connect(mExecBut,               SIGNAL(clicked()),  this,   SLOT(setPathToGame()));
    connect(mSettingsCButton,       SIGNAL(clicked()),  this,   SLOT(close()));
}
void Settings::createInterface()
{
    mSettingsTitle->setText("Settings");

    mSettingsTHbox->addWidget(mSettingsCButton, 1, Qt::AlignRight | Qt::AlignTop);
    mSettingsTHbox->setContentsMargins(0, 22, 9, 0);

    mSettingsPixmap->setPixmap(QPixmap(":imgs/settings/setBan"));
    mSettingsPixmap->setAlignment(Qt::AlignCenter);
    mSettingsPixmap->setLayout(mSettingsTHbox);
    mSettingsPixmap->setContentsMargins(0, -15, -7, -25);

    mTSettingsVBox->addWidget(mSettingsPixmap,1);
    mTSettingsVBox->addWidget(mSettingsTitle, 0, Qt::AlignHCenter);

    mSettingsTButton->setLayout(mTSettingsVBox);
    mSettingsTButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
    mSettingsTButton->setFixedHeight(90);

    mGameLab->setText("Game save directory");

    mGameLin->setReadOnly(true);

    mGameBut->setText(". . .");

    mStorLab->setText("Backup saves directory");

    mStorLin->setReadOnly(true);

    mStorBut->setText(". . .");

    mExecLab->setText("Game executable path");

    mExecLin->setReadOnly(true);

    mExecBut->setText(". . .");

    mSettingsGrid->addWidget(mGameLab,  0,0,1,1);
    mSettingsGrid->addWidget(mGameLin,  1,0,1,1);
    mSettingsGrid->addWidget(mGameBut,  1,1,1,1);
    mSettingsGrid->addWidget(mStorLab,  2,0,1,1);
    mSettingsGrid->addWidget(mStorLin,  3,0,1,1);
    mSettingsGrid->addWidget(mStorBut,  3,1,1,1);
    mSettingsGrid->addWidget(mExecLab,  4,0,1,1);
    mSettingsGrid->addWidget(mExecLin,  5,0,1,1);
    mSettingsGrid->addWidget(mExecBut,  5,1,1,1);
    mSettingsGrid->setContentsMargins(11, 7, 11, 11);
    mSettingsGrid->setAlignment(Qt::AlignBottom | Qt::AlignLeft);

    mSettingsVbox->addWidget(mSettingsTButton);
    mSettingsVbox->addLayout(mSettingsGrid);
}
void Settings::createObjectName()
{
    mSettingsTitle->setObjectName("Label_Settings_Title");
    mSettingsTButton->setObjectName("Button_Settings_Title");
    mSettingsCButton->setObjectName("Button_Settings_Close");
    mGameBut->setObjectName("Button_Settings_FileDialog");
    mStorBut->setObjectName("Button_Settings_FileDialog");
    mExecBut->setObjectName("Button_Settings_FileDialog");
    mGameLab->setObjectName("Label_Settings_Tip");
    mStorLab->setObjectName("Label_Settings_Tip");
    mExecLab->setObjectName("Label_Settings_Tip");
}
void Settings::createSettings()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    this->setContentsMargins(-8, -8, -8, -8);
    this->setLayout(mSettingsVbox);
    this->initSettings();
    this->setFixedSize(500, 270);
    this->setWindowTitle("UNDERTALE Save Manager - " + mSettingsTitle->text());
}

//Methods
void Settings::initSettings()
{
    if (!mCFGSettings->contains("SaveFolder")) {
        mCFGSettings->setValue("SaveFolder", mAppDataLocal+"/UNDERTALE");
    }
    if (!mCFGSettings->contains("StoreFolder")) {
        mCFGSettings->setValue("StoreFolder", mDocumentsData+"/UNDERTALE_BACKUPS");
    }

    mCSSTheme = mCSSFile->readAll();
    mGameLin->setText(currentSave());
    mStorLin->setText(storageSaves());
    mExecLin->setText(gameDirectory());
}
QString Settings::storageSaves()
{
    return mCFGSettings->value("StoreFolder").toString();
}
QString Settings::currentSave()
{
    return mCFGSettings->value("SaveFolder").toString();
}
QString Settings::currentTheme()
{
    return mCSSTheme;
}
QString Settings::gameDirectory()
{
    return mCFGSettings->value("GameFolder").toString();
}

//Slots
void Settings::setStorageSaves()
{
    QString storDir = QFileDialog::getExistingDirectory(this, tr("Locate your UNDERTALE directory"));

    if (!storDir.isEmpty()) {
        mGameLin->setText(storDir);
        mCFGSettings->setValue("StoreFolder", storDir);
    }
}
void Settings::setCurrentSave()
{
    QString unDir = QFileDialog::getExistingDirectory(this, tr("Locate your UNDERTALE %APPDATA% directory"));

    if (!unDir.isEmpty()) {
        mGameLin->setText(unDir);
        mCFGSettings->setValue("SaveFolder", unDir);
    }
}
void Settings::setPathToGame()
{
    QDir    gameDir(mCFGSettings->value("GameFolder").toString());
            gameDir.cdUp();

    QString gameDirStr = QFileDialog::getOpenFileName(this, tr("Locate your UNDERTALE Program directory"),gameDir.path(),"Game (UNDERTALE.exe)");

    if (!gameDirStr.isEmpty()) {
        mExecLin->setText(gameDirStr);
        mCFGSettings->setValue("GameFolder", gameDirStr);
    }
}

//Events
void Settings::keyPressEvent(QKeyEvent *event)
{
    event->ignore();
}
void Settings::closeEvent(QCloseEvent *event)
{
    //Accept only internal closing events
    event->setAccepted(!event->spontaneous());
}
