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
    mCSSFile            = new QFile;

    //SettingsTitle
    mSettingsCButton    = new QPushButton;
    mSettingsTHbox      = new QHBoxLayout;
    mSettingsPixmap     = new QLabel;
    mSettingsTitle      = new QLabel;
    mTSettingsVBox      = new QVBoxLayout;
    mSettingsTButton    = new TPushButton(this);
    //End_SettingsTitle

    //MessageBox
    mSoundLab           = new QLabel;
    mSoundChk           = new QCheckBox;
    mSpeedLab           = new QLabel;
    mSpeedSld           = new QSlider;
    mSpValLab           = new QLabel;
    mMesBoxGrid         = new QGridLayout;
    mMesBoxGroup        = new QGroupBox;
    //End_MessageBox

    //PathsDefine
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
    mPathsGroup         = new QGroupBox;
    //End_PathsDefine

    mGroupsVBox         = new QVBoxLayout;
    mSettingsVbox       = new QVBoxLayout;

    //General
    mAppDataLocal       = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
    mDocumentsData      = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    mCFGSettings        = new QSettings(QCoreApplication::applicationDirPath()+"/config.cfg", QSettings::IniFormat);
    mCSSFile->setFileName(":themes/thmD");
    mCSSFile->open(QIODevice::ReadOnly | QIODevice::Text);
}
void Settings::createConnexions()
{
    connect(mGameBut,               SIGNAL(clicked()),          this,   SLOT(setCurrentSave()));
    connect(mStorBut,               SIGNAL(clicked()),          this,   SLOT(setStorageSaves()));
    connect(mExecBut,               SIGNAL(clicked()),          this,   SLOT(setPathToGame()));
    connect(mSettingsCButton,       SIGNAL(clicked()),          this,   SLOT(close()));
    connect(mSoundChk,              SIGNAL(toggled(bool)),      this,   SLOT(setSoundEnabled(bool)));
    connect(mSpeedSld,              SIGNAL(valueChanged(int)),  this,   SLOT(setTextSpeed(int)));
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

    /**/
    mSoundLab->setText("Sound : ");

    mSpeedLab->setText("Text speed : ");

    mSpeedSld->setOrientation(Qt::Horizontal);
    mSpeedSld->setRange(0, 3);
    mSpeedSld->setFixedWidth(30);

    mMesBoxGrid->addWidget(mSoundLab,0,0,1,1, Qt::AlignRight);
    mMesBoxGrid->addWidget(mSoundChk,0,1,1,1, Qt::AlignLeft);
    mMesBoxGrid->addWidget(mSpeedLab,1,0,1,1, Qt::AlignRight);
    mMesBoxGrid->addWidget(mSpeedSld,1,1,1,1, Qt::AlignLeft);
    mMesBoxGrid->addWidget(mSpValLab,1,3,1,1, Qt::AlignRight);

    mMesBoxGroup->setTitle("Message Boxes");
    mMesBoxGroup->setLayout(mMesBoxGrid);
    mMesBoxGroup->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);
    mMesBoxGroup->setFixedWidth(240);
    /**/

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
    mSettingsGrid->setContentsMargins(11, 15, 11, 11);
    mSettingsGrid->setAlignment(Qt::AlignBottom | Qt::AlignLeft);

    mPathsGroup->setTitle("Paths Define");
    mPathsGroup->setLayout(mSettingsGrid);

    mGroupsVBox->addWidget(mMesBoxGroup);
    mGroupsVBox->addWidget(mPathsGroup);
    mGroupsVBox->setContentsMargins(11,7,11,11);

    mSettingsVbox->addWidget(mSettingsTButton);
    mSettingsVbox->addLayout(mGroupsVBox);
}
void Settings::createObjectName()
{
    mSoundLab->setObjectName("Label_Settings_Header");
    mSoundChk->setObjectName("CheckBox_Settings");
    mSpeedLab->setObjectName("Label_Settings_Header");
    mSpeedSld->setObjectName("Slider_Settings");
    mSpValLab->setObjectName("Label_Settings_Value");
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
    this->setFixedSize(500, 400);
    this->setWindowTitle("UNDERTALE Save Manager - " + mSettingsTitle->text());
}

//Methods
int Settings::textSpeed()
{
    int gTextSpeed = mCFGSettings->value("MessageBox/TextSpeed").toInt();

    switch (gTextSpeed) {
    case 0:
        return 30;
        break;
    case 1:
        return 20;
        break;
    case 2:
        return 10;
        break;
    case 3:
        return 0;
        break;
    default:
        return 20;
        break;
    }
}
bool Settings::soundEnabled()
{
    return mCFGSettings->value("MessageBox/SoundEffect").toBool();
}
void Settings::initSettings()
{
    if (!mCFGSettings->contains("MessageBox/TextSpeed")) {
        mCFGSettings->setValue("MessageBox/TextSpeed", 2);
    }

    if (!mCFGSettings->contains("MessageBox/SoundEffect")) {
        mCFGSettings->setValue("MessageBox/SoundEffect", true);
    }

    if (!mCFGSettings->contains("Paths/CurrentSave")) {
        mCFGSettings->setValue("Paths/CurrentSave", mAppDataLocal+"/UNDERTALE");
    }

    if (!mCFGSettings->contains("Paths/BackupsSaves")) {
        mCFGSettings->setValue("Paths/BackupsSaves", mDocumentsData+"/UNDERTALE_BACKUPS");
    }

    mCSSTheme = mCSSFile->readAll();
    setTextSpeed(mCFGSettings->value("MessageBox/TextSpeed").toInt());
    setSoundEnabled(mCFGSettings->value("MessageBox/SoundEffect").toBool());
    mGameLin->setText(currentSave());
    mStorLin->setText(storageSaves());
    mExecLin->setText(gameDirectory());
}
QString Settings::storageSaves()
{
    return mCFGSettings->value("Paths/BackupsSaves").toString();
}
QString Settings::currentSave()
{
    return mCFGSettings->value("Paths/CurrentSave").toString();
}
QString Settings::currentTheme()
{
    return mCSSTheme;
}
QString Settings::gameDirectory()
{
    return mCFGSettings->value("Paths/GameExecutable").toString();
}

//Slots
void Settings::setTextSpeed(int speed)
{
    mCFGSettings->setValue("MessageBox/TextSpeed", speed);

    switch (speed) {
    case 0:
        mSoundChk->setEnabled(true);
        mSpeedSld->setValue(0);
        mSpValLab->setText("Slow");
        break;
    case 1:
        mSoundChk->setEnabled(true);
        mSpeedSld->setValue(1);
        mSpValLab->setText("Normal");
        break;
    case 2:
        mSoundChk->setEnabled(true);
        mSpeedSld->setValue(2);
        mSpValLab->setText("Fast");
        break;
    case 3:
        mSoundChk->setEnabled(false);
        mSpeedSld->setValue(3);
        mSpValLab->setText("Instant");
        break;
    default:
        setTextSpeed(2);
        break;
    }
}
void Settings::setSoundEnabled(bool senb)
{
    mCFGSettings->setValue("MessageBox/SoundEffect", senb);
    mSoundChk->setChecked(senb);
}
void Settings::setStorageSaves()
{
    QString storDir = QFileDialog::getExistingDirectory(this, tr("Locate your UNDERTALE directory"));

    if (!storDir.isEmpty()) {
        mGameLin->setText(storDir);
        mCFGSettings->setValue("Paths/BackupsSaves", storDir);
    }
}
void Settings::setCurrentSave()
{
    QString unDir = QFileDialog::getExistingDirectory(this, tr("Locate your UNDERTALE %APPDATA% directory"));

    if (!unDir.isEmpty()) {
        mGameLin->setText(unDir);
        mCFGSettings->setValue("Paths/CurrentSave", unDir);
    }
}
void Settings::setPathToGame()
{
    QDir    gameDir(mCFGSettings->value("Paths/GameExecutable").toString());
            gameDir.cdUp();

    QString gameDirStr = QFileDialog::getOpenFileName(this, tr("Locate your UNDERTALE Program directory"),gameDir.path(),"Game (UNDERTALE.exe)");

    if (!gameDirStr.isEmpty()) {
        mExecLin->setText(gameDirStr);
        mCFGSettings->setValue("Paths/GameExecutable", gameDirStr);
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
