QT       += core gui widgets multimedia

TEMPLATE = app

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
            cwidgets/ProgressiveText.cpp

HEADERS  += About.hpp                       \
            Settings.hpp                    \
            UnSavManager.hpp                \
            cwidgets/QHSpace.hpp            \
            cwidgets/UnProfile.hpp          \
            cwidgets/TPushButton.hpp        \
            cwidgets/MessageDialog.hpp      \
            cwidgets/SaveListWidget.hpp     \
            cwidgets/ProgressiveText.hpp

RESOURCES +=                                \
            assets.qrc
