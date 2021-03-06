#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QtWidgets>

#include "cwidgets/TPushButton.hpp"

class Settings : public QDialog
{
    Q_OBJECT

public:

    Settings(QWidget * parent = 0);

    void createObjects();
    void createConnexions();
    void createLangCombo();
    void createThemCombo();
    void createInterface();
    void createObjectName();
    void createSettings();

    int     textSpeed();
    bool    soundEnabled();
    bool    steamEnabled();
    QString themeName();
    QString backupSaves();
    QString currentSave();
    QString currentTheme();
    QString currentLang();
    QString gameDirectory();

    //Events
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:

    void setTextSpeed(int speed);
    void setSoundEnabled(bool isEnabled);
    void setSteamEnabled(bool isSteam);
    void setBackupSaves();
    void setCurrentSave();
    void setPathToGame();

    void initSettings();
    void loadSettings();
    void saveSettings();
    void translateUi();
    void cancelOnClose();

    void loadTranslator();
    void loadTheme();

    void slotLanguageChanged(int index);
    void slotThemeChanged(int index);

private:

    QString         mCurrentLang;
    QString         mCurrentTranslator;

    QTranslator     *mTranslator;
    QLabel          *mThemeLabel;
    QLabel          *mLangLabel;
    QComboBox       *mLangCombo;
    QGroupBox       *mMiscGroup;
    QComboBox       *mThemeCombo;
    QGridLayout     *mMiscGrid;
    QHBoxLayout     *mTopGroups;
    //
    bool            mTmpSndEnabled;
    QString         mCSSTheme;
    QString         mDocumentsData;
    QString         mAppDataLocal;
    //MessageBox
    QLabel          *mSoundLab;
    QCheckBox       *mSoundChk;
    QLabel          *mSpeedLab;
    QSlider         *mSpeedSld;
    QLabel          *mSpValLab;
    QGridLayout     *mMesBoxGrid;
    QGroupBox       *mMesBoxGroup;
    //End_MessageBox
    QGroupBox       *mPathsGroup;
    QVBoxLayout     *mGroupsVBox;
    QCheckBox       *mSteamChk;
    QLabel          *mExecStm;
    QFile           *mCSSFile;
    QLabel          *mGameLab;
    QLabel          *mStorLab;
    QLabel          *mExecLab;
    QPushButton     *mGameBut;
    QPushButton     *mStorBut;
    QPushButton     *mExecBut;
    QLineEdit       *mGameLin;
    QLineEdit       *mStorLin;
    QLineEdit       *mExecLin;
    QGridLayout     *mSettingsGrid;
    QSettings       *mCFGSettings;
    QPushButton     *mSettingsCButton;
    QHBoxLayout     *mSettingsTHbox;
    TPushButton     *mSettingsTButton;
    QVBoxLayout     *mSettingsVbox;
    QLabel          *mSettingsPixmap;
    QPushButton     *mApplyBut;
    QPushButton     *mCancelBut;
    QHBoxLayout     *mBotButHBox;
    QVBoxLayout     *mTSettingsVBox;
    QLabel          *mSettingsTitle;
};

#endif // SETTINGS_HPP
