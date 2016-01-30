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

    bool soundEnabled();
    int textSpeed();
    void initSettings();
    QString storageSaves();
    QString currentSave();
    QString currentTheme();
    QString gameDirectory();

    //Events
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:

    void setSoundEnabled(bool senb);
    void setTextSpeed(int pos);
    void setStorageSaves();
    void setCurrentSave();
    void setPathToGame();

private:

    QString         mDocumentsData;
    QString         mCSSTheme;
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

    //
    QGroupBox       *mPathsGroup;
    QVBoxLayout     *mGroupsVBox;
    //
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
    QVBoxLayout     *mTSettingsVBox;
    QLabel          *mSettingsTitle;
};

#endif // SETTINGS_HPP
