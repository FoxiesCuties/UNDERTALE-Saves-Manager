#include "Settings.hpp"

Settings::Settings(QWidget *parent) : QDialog(parent)
{
    createObjects();
    createConnexions();
    createInterface();
    createLangCombo();
    createThemCombo();
    createObjectName();
    createSettings();
}

//Organizers
void Settings::createObjects()
{
    mTranslator         = new QTranslator;
    mLangCombo          = new QComboBox;
    mThemeLabel         = new QLabel;
    mLangLabel          = new QLabel;
    mMiscGroup          = new QGroupBox;
    mCSSFile            = new QFile;
    mThemeCombo         = new QComboBox;
    mMiscGrid           = new QGridLayout;
    mTopGroups          = new QHBoxLayout;
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
    mExecStm            = new QLabel;
    mSteamChk           = new QCheckBox;
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
    mApplyBut           = new QPushButton;
    mCancelBut          = new QPushButton;
    mBotButHBox         = new QHBoxLayout;
    mSettingsVbox       = new QVBoxLayout;
    //General
    mAppDataLocal       = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
    mDocumentsData      = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    mCFGSettings        = new QSettings(QCoreApplication::applicationDirPath()+"/config.cfg", QSettings::IniFormat);

    mCSSFile->setFileName(":themes/thmD");
}
void Settings::createConnexions()
{
    connect(mGameBut,           SIGNAL(clicked()),                  this,   SLOT(setCurrentSave()));
    connect(mStorBut,           SIGNAL(clicked()),                  this,   SLOT(setBackupSaves()));
    connect(mExecBut,           SIGNAL(clicked()),                  this,   SLOT(setPathToGame()));
    connect(mSettingsCButton,   SIGNAL(clicked()),                  this,   SLOT(cancelOnClose()));
    connect(mSoundChk,          SIGNAL(toggled(bool)),              this,   SLOT(setSoundEnabled(bool)));
    connect(mSpeedSld,          SIGNAL(valueChanged(int)),          this,   SLOT(setTextSpeed(int)));
    connect(mSteamChk,          SIGNAL(toggled(bool)),              this,   SLOT(setSteamEnabled(bool)));
    connect(mApplyBut,          SIGNAL(clicked()),                  this,   SLOT(saveSettings()));
    connect(mCancelBut,         SIGNAL(clicked()),                  this,   SLOT(loadSettings()));
    connect(mLangCombo,         SIGNAL(currentIndexChanged(int)),   this,   SLOT(slotLanguageChanged(int)));
    connect(mThemeCombo,        SIGNAL(currentIndexChanged(int)),   this,   SLOT(slotThemeChanged(int)));
}
void Settings::createLangCombo()
{
    mLangCombo->addItem(QIcon(":i18n/en_US"), "en_US", "en_US");//Add default value

    QString i18nPath = QApplication::applicationDirPath()+"/i18n";
    QDir i18nDir(i18nPath);

    foreach (QString lang, i18nDir.entryList(QDir::NoDotAndDotDot|QDir::AllDirs)) {
        mLangCombo->addItem(QIcon(i18nPath+"/"+lang+"/icon.png"), lang, lang);
    }
}
void Settings::createThemCombo()
{
    mThemeCombo->addItem(tr("Default"), "native");//Add default value

    QString themePath = QApplication::applicationDirPath()+"/themes";
    QDir themeDir(themePath);

    foreach (QString them, themeDir.entryList(QDir::Files)) {
        mThemeCombo->addItem(them.section(".",0,0), them);
    }
}
void Settings::createInterface()
{
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
    mSpeedSld->setOrientation(Qt::Horizontal);
    mSpeedSld->setRange(0, 3);
    mSpeedSld->setFixedWidth(30);

    mMesBoxGrid->addWidget(mSoundLab,0,0,1,1, Qt::AlignRight);
    mMesBoxGrid->addWidget(mSoundChk,0,1,1,1, Qt::AlignLeft);
    mMesBoxGrid->addWidget(mSpeedLab,1,0,1,1, Qt::AlignRight);
    mMesBoxGrid->addWidget(mSpeedSld,1,1,1,1, Qt::AlignLeft);
    mMesBoxGrid->addWidget(mSpValLab,1,3,1,1, Qt::AlignRight);

    mMesBoxGroup->setLayout(mMesBoxGrid);
    mMesBoxGroup->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);
    /**/
    mGameLin->setReadOnly(true);

    mGameBut->setText(". . .");

    mStorLin->setReadOnly(true);

    mStorBut->setText(". . .");

    mExecLin->setReadOnly(true);

    mExecBut->setText(". . .");

    mSettingsGrid->addWidget(mGameLab,  0,0,1,1);
    mSettingsGrid->addWidget(mGameLin,  1,0,1,6);
    mSettingsGrid->addWidget(mGameBut,  1,7,1,1);
    mSettingsGrid->addWidget(mStorLab,  2,0,1,1);
    mSettingsGrid->addWidget(mStorLin,  3,0,1,6);
    mSettingsGrid->addWidget(mStorBut,  3,7,1,1);
    mSettingsGrid->addWidget(mExecLab,  4,0,1,1);
    mSettingsGrid->addWidget(mSteamChk, 4,1,1,1, Qt::AlignRight);
    mSettingsGrid->addWidget(mExecStm,  4,2,1,1, Qt::AlignLeft);
    mSettingsGrid->addWidget(mExecLin,  5,0,1,6);
    mSettingsGrid->addWidget(mExecBut,  5,7,1,1);
    mSettingsGrid->setContentsMargins(11, 15, 11, 11);

    mPathsGroup->setLayout(mSettingsGrid);
    /**/

    mMiscGrid->addWidget(mLangLabel,0,0);
    mMiscGrid->addWidget(mLangCombo,0,1);
    mMiscGrid->addWidget(mThemeLabel,1,0);
    mMiscGrid->addWidget(mThemeCombo,1,1);

    mMiscGroup->setLayout(mMiscGrid);

    mTopGroups->addWidget(mMesBoxGroup);
    mTopGroups->addWidget(mMiscGroup);
    mTopGroups->setSpacing(11);

    mGroupsVBox->addLayout(mTopGroups);
    /**/
    mGroupsVBox->addWidget(mPathsGroup);
    mGroupsVBox->setContentsMargins(11, 7, 11, 11);

    mBotButHBox->addWidget(mApplyBut);
    mBotButHBox->addWidget(mCancelBut);
    mBotButHBox->setContentsMargins(11,0,11,11);

    mSettingsVbox->addWidget(mSettingsTButton);
    mSettingsVbox->addLayout(mGroupsVBox);
    mSettingsVbox->addLayout(mBotButHBox);
}
void Settings::createObjectName()
{
    mSoundLab->setObjectName("Label_Settings_Header");
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
    mExecStm->setObjectName("Label_Settings_Tip");
    mThemeLabel->setObjectName("Label_Settings_Tip");
    mLangLabel->setObjectName("Label_Settings_Tip");
    mApplyBut->setObjectName("Button_Settings_Apply");
    mCancelBut->setObjectName("Button_Settings_Cancel");
}
void Settings::createSettings()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    this->setContentsMargins(-8, -8, -8, -8);
    this->setLayout(mSettingsVbox);
    this->initSettings();
    this->setFixedSize(500, 450);
    this->setWindowTitle("UNDERTALE Save Manager - " + mSettingsTitle->text());
}

//Methods
int     Settings::textSpeed()
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
bool    Settings::soundEnabled()
{
    return mCFGSettings->value("MessageBox/SoundEffect").toBool();
}
bool    Settings::steamEnabled()
{
    return mCFGSettings->value("Paths/SteamVersion").toBool();
}
QString Settings::backupSaves()
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
QString Settings::currentLang()
{
    return mCurrentLang;
}
QString Settings::gameDirectory()
{
    return mCFGSettings->value("Paths/GameExecutable").toString();
}

//Slots
void Settings::setTextSpeed(int speed)
{
    switch (speed) {
    case 0:
        mSoundChk->setChecked(mTmpSndEnabled);
        mSoundChk->setEnabled(true);
        mSpValLab->setText("Slow");
        break;
    case 1:
        mSoundChk->setChecked(mTmpSndEnabled);
        mSoundChk->setEnabled(true);
        mSpValLab->setText("Normal");
        break;
    case 2:
        mSoundChk->setChecked(mTmpSndEnabled);
        mSoundChk->setEnabled(true);
        mSpValLab->setText("Fast");
        break;
    case 3:
        mSoundChk->setChecked(false);
        mSoundChk->setEnabled(false);
        mSpValLab->setText("Instant");
        break;
    default:
        setTextSpeed(2);
        break;
    }
}
void Settings::setSoundEnabled(bool isEnabled)
{
    if (mSpeedSld->value() != 3) {//Prevent statut erasing
        mTmpSndEnabled = isEnabled;
    }
}
void Settings::setSteamEnabled(bool isSteam)
{
    mSteamChk->setChecked(isSteam);
}
void Settings::setBackupSaves()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Locate your backup saves directory"));

    if (!path.isEmpty()) {
        mStorLin->setText(path);
    }
}
void Settings::setCurrentSave()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Locate your game save directory"));

    if (!path.isEmpty()) {
        mGameLin->setText(path);
    }
}
void Settings::setPathToGame()
{
    QDir    gameDir(mCFGSettings->value("Paths/GameExecutable").toString());
            gameDir.cdUp();

    QString path = QFileDialog::getOpenFileName(this, tr("Locate your UNDERTALE game directory"),gameDir.path(),"Game (UNDERTALE.exe)");

    if (!path.isEmpty()) {
        mExecLin->setText(path);
    }
}

void Settings::initSettings()
{
    if (!mCFGSettings->contains("MessageBox/TextSpeed")) {
        mCFGSettings->setValue("MessageBox/TextSpeed", 2);
    }

    if (!mCFGSettings->contains("MessageBox/SoundEffect")) {
        mCFGSettings->setValue("MessageBox/SoundEffect", true);
    }

    if (!mCFGSettings->contains("Paths/SteamVersion")) {
        mCFGSettings->setValue("Paths/SteamVersion", false);
    }

    if (!mCFGSettings->contains("Paths/CurrentSave")) {
        mCFGSettings->setValue("Paths/CurrentSave", mAppDataLocal+"/UNDERTALE");
    }

    if (!mCFGSettings->contains("Paths/BackupsSaves")) {
        mCFGSettings->setValue("Paths/BackupsSaves", mDocumentsData+"/UNDERTALE_BACKUPS");
    }

    if (!mCFGSettings->contains("Miscs/Language")) {
        mCFGSettings->setValue("Miscs/Language", QLocale::system().name());
    }

    if (!mCFGSettings->contains("Miscs/Theme")) {
        mCFGSettings->setValue("Miscs/Theme", "native");
    }

    mCurrentLang = mCFGSettings->value("Miscs/Language").toString();

    mCurrentTranslator = QApplication::applicationDirPath()+"/i18n/"+mCurrentLang+"/lang.qm";

    loadTranslator();
    loadTheme();
    loadSettings();
}
void Settings::loadSettings()
{
    if (!mCSSFile->isOpen()) {
        mCSSFile->open(QIODevice::ReadOnly | QIODevice::Text);
        mCSSTheme = mCSSFile->readAll();
    }

    mSpeedSld->setValue(mCFGSettings->value("MessageBox/TextSpeed").toInt());
    mSoundChk->setChecked(mCFGSettings->value("MessageBox/SoundEffect").toBool());
    mSteamChk->setChecked(mCFGSettings->value("Paths/SteamVersion").toBool());
    mGameLin->setText(mCFGSettings->value("Paths/CurrentSave").toString());
    mStorLin->setText(mCFGSettings->value("Paths/BackupsSaves").toString());
    mExecLin->setText(mCFGSettings->value("Paths/GameExecutable").toString());
    mLangCombo->setCurrentIndex(mLangCombo->findText(mCFGSettings->value("Miscs/Language").toString()));
    mThemeCombo->setCurrentIndex(mThemeCombo->findData(mCFGSettings->value("Miscs/Theme").toString()));

    translateUi();
}
void Settings::loadTranslator()
{
    qApp->removeTranslator(mTranslator);

    if (mTranslator->load(mCurrentTranslator)) {
        qApp->installTranslator(mTranslator);
    }
}
void Settings::loadTheme()
{
    qApp->setStyleSheet(mCSSTheme);
}

void Settings::saveSettings()
{
    mCFGSettings->setValue("MessageBox/TextSpeed",      mSpeedSld->value());
    mCFGSettings->setValue("MessageBox/SoundEffect",    mSoundChk->isChecked());
    mCFGSettings->setValue("Paths/SteamVersion",        mSteamChk->isChecked());
    mCFGSettings->setValue("Paths/CurrentSave",         mGameLin->text());
    mCFGSettings->setValue("Paths/BackupsSaves",        mStorLin->text());
    mCFGSettings->setValue("Paths/GameExecutable",      mExecLin->text());
    mCFGSettings->setValue("Miscs/Language",            mLangCombo->currentText());
    mCFGSettings->setValue("Miscs/Theme",               mThemeCombo->currentData());

    loadTranslator();
    loadTheme();
    translateUi();
}
void Settings::translateUi()
{
    mSettingsTitle->setText(tr("Settings"));
    mSoundLab->setText(tr("Sound : "));
    mMesBoxGroup->setTitle(tr("Message Boxes"));
    mSpeedLab->setText(tr("Text speed : "));
    mGameLab->setText(tr("Game save directory"));
    mStorLab->setText(tr("Backup saves directory"));
    mExecLab->setText(tr("Game executable path"));
    mPathsGroup->setTitle(tr("Paths Define"));
    mExecStm->setText(tr("Steam version"));
    mMiscGroup->setTitle(tr("Misc"));
    mApplyBut->setText(tr("APPLY"));
    mCancelBut->setText(tr("CANCEL"));
    mThemeLabel->setText(tr("Theme"));
    mLangLabel->setText(tr("Language"));
}
void Settings::cancelOnClose()
{
    this->loadSettings();
    this->close();
}
void Settings::slotLanguageChanged(int index)
{
    mCurrentLang = mLangCombo->itemData(index).toString();

    if (mLangCombo->currentIndex() == 0) {
        mCurrentTranslator = ":i18n/en_US_QM";
    } else {
        mCurrentTranslator = QApplication::applicationDirPath()+"/i18n/"+mCurrentLang+"/lang.qm";
    }
}
void Settings::slotThemeChanged(int index)
{
    QString str = mThemeCombo->itemData(index).toString();

    mCSSFile->close();

    if (mThemeCombo->currentIndex() == 0) {
        mCSSFile->setFileName(":themes/thmD");
    } else {
        mCSSFile->setFileName(QCoreApplication::applicationDirPath()+"/themes/"+str);
    }

    if(mCSSFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        mCSSTheme = mCSSFile->readAll();
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
