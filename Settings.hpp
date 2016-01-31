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
    void createInterface();
    void createObjectName();
    void createSettings();

    int     textSpeed();
    bool    soundEnabled();
    bool    steamEnabled();
    QString storageSaves();
    QString currentSave();
    QString currentTheme();
    QString gameDirectory();

    //Events
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:

    void setTextSpeed(int speed);
    void setSoundEnabled(bool isEnabled);
    void setSteamEnabled(bool isSteam);
    void setStorageSaves();
    void setCurrentSave();
    void setPathToGame();

    void initSettings();
    void loadSettings();
    void saveSettings();

private:

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
