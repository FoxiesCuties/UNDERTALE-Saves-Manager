QT       += core gui widgets multimedia

TEMPLATE = app

TRANSLATIONS =  assets/i18n/fr_FR/lang.ts \

VERSION = 0.7

DEFINES += APP_VERSION=\\\"$$VERSION\\\"

CONFIG += c++11

TARGET = UNDERTALE-Saves-Manager

SOURCES +=  main.cpp                            \
            About.cpp                           \
            Settings.cpp                        \
            UnSavManager.cpp                    \
            cwidgets/QHSpace.cpp                \
            cwidgets/UnProfile.cpp              \
            cwidgets/USaveFile.cpp              \
            cwidgets/SaveDetails.cpp            \
            cwidgets/TPushButton.cpp            \
            cwidgets/MessageDialog.cpp          \
            cwidgets/SaveListWidget.cpp         \
            cwidgets/ProgressiveText.cpp        \
            cwidgets/SaveDetails/StatsTab.cpp   \
            cwidgets/SaveDetails/ItemsTab.cpp   \

HEADERS  += About.hpp                           \
            Settings.hpp                        \
            UnSavManager.hpp                    \
            cwidgets/QHSpace.hpp                \
            cwidgets/UnProfile.hpp              \
            cwidgets/USaveFile.hpp              \
            cwidgets/SaveDetails.hpp            \
            cwidgets/TPushButton.hpp            \
            cwidgets/MessageDialog.hpp          \
            cwidgets/SaveListWidget.hpp         \
            cwidgets/ProgressiveText.hpp        \
            cwidgets/SaveDetails/StatsTab.hpp   \
            cwidgets/SaveDetails/ItemsTab.hpp   \

RESOURCES +=                                    \
            assets.qrc                          \


RC_ICONS = toriel.ico

QMAKE_TARGET_DESCRIPTION = "UNDERTALE Save Manager"
QMAKE_TARGET_COPYRIGHT = "FoxiesCuties"

#------------------------------------------------#
#   You need to add "install" arg to make step   #
#------------------------------------------------#

#Assets
roomsmng.path       =   $$OUT_PWD/release/assets/imgs/pixmaps/rooms/
    roomsmng.files  +=  $$PWD/assets/imgs/pixmaps/rooms/*.mng

themes.path         =   $$OUT_PWD/release/assets/themes/
    themes.files    +=  $$PWD/assets/themes/*

sounds.path         =   $$OUT_PWD/release/assets/sounds/
    sounds.files    +=  $$PWD/assets/sounds/*

i18n.path           =   $$OUT_PWD/release/assets/i18n/fr_FR/
    i18n.files      +=  $$PWD/assets/i18n/fr_FR/lang.qm
    i18n.files      +=  $$PWD/assets/i18n/fr_FR/icon.png

#Library
mnglib.path         =   $$OUT_PWD/release/imageformats/
    mnglib.files    +=  $$[QT_INSTALL_DATA]/plugins/imageformats/qmng.dll

qtlib.path          =   $$OUT_PWD/release/
    qtlib.files     +=  $$[QT_INSTALL_BINS]/Qt5Core.dll
    qtlib.files     +=  $$[QT_INSTALL_BINS]/Qt5Gui.dll
    qtlib.files     +=  $$[QT_INSTALL_BINS]/Qt5Multimedia.dll
    qtlib.files     +=  $$[QT_INSTALL_BINS]/Qt5Network.dll
    qtlib.files     +=  $$[QT_INSTALL_BINS]/Qt5Widgets.dll
    qtlib.files     +=  $$[QT_INSTALL_BINS]/libgcc_s_dw2-1.dll
    qtlib.files     +=  $$[QT_INSTALL_BINS]/libwinpthread-1.dll
    qtlib.files     +=  $$[QT_INSTALL_BINS]/libstd~1.dll#CF libstdc++-6.dll

qwindows.path       =   $$OUT_PWD/release/platforms/
    qwindows.files  +=  $$[QT_INSTALL_DATA]/plugins/platforms/qwindows.dll

INSTALLS += roomsmng    \
            themes      \
            sounds      \
            i18n        \
            mnglib      \
            qtlib       \
            qwindows    \
