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

    void initSettings();
    QString storageSaves();
    QString currentSave();
    QString currentTheme();
    QString gameDirectory();

    //Events
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:

    void setStorageSaves();
    void setCurrentSave();
    void setPathToGame();

private:

    QString         mDocumentsData;
    QString         mCSSTheme;
    QString         mAppDataLocal;

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
