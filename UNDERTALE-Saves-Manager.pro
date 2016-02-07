QT       += core gui widgets multimedia

TEMPLATE = app

RC_ICONS = toriel.ico

TRANSLATIONS =  assets/i18n/fr_FR/lang.ts \
                assets/i18n/en_US/lang.ts \

VERSION = 0.4
QMAKE_TARGET_DESCRIPTION = "An Save Manager for the UNDERTALE game"
QMAKE_TARGET_COPYRIGHT = "FoxiesCuties"

DEFINES += APP_VERSION=\\\"$$VERSION\\\"

CONFIG += c++11

TARGET = UNDERTALE-Saves-Manager

SOURCES +=  main.cpp                        \
            About.cpp                       \
            Settings.cpp                    \
            UnSavManager.cpp                \
            cwidgets/QHSpace.cpp            \
            cwidgets/UnProfile.cpp          \
            cwidgets/TPushButton.cpp        \
            cwidgets/MessageDialog.cpp      \
            cwidgets/SaveListWidget.cpp     \
            cwidgets/ProgressiveText.cpp    \
            cwidgets/SaveDetails.cpp        \
            cwidgets/USaveFile.cpp          \

HEADERS  += About.hpp                       \
            Settings.hpp                    \
            UnSavManager.hpp                \
            cwidgets/QHSpace.hpp            \
            cwidgets/UnProfile.hpp          \
            cwidgets/TPushButton.hpp        \
            cwidgets/MessageDialog.hpp      \
            cwidgets/SaveListWidget.hpp     \
            cwidgets/ProgressiveText.hpp    \
            cwidgets/SaveDetails.hpp        \
            cwidgets/USaveFile.hpp          \

RESOURCES +=                                \
            assets.qrc
