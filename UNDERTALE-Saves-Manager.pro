QT       += core gui widgets multimedia

TEMPLATE = app

RC_ICONS = toriel.ico

TRANSLATIONS =  assets/i18n/fr_FR/lang.ts \

VERSION = 0.7
QMAKE_TARGET_DESCRIPTION = "UNDERTALE Save Manager"
QMAKE_TARGET_COPYRIGHT = "FoxiesCuties"

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


#------------------------------------------------#
#   You need to add "install" arg to make step   #
#------------------------------------------------#

assets.path = $$OUT_PWD/release/assets/imgs/pixmaps/rooms/
assets.files += $$PWD/assets/imgs/pixmaps/rooms/*

INSTALLS += assets
