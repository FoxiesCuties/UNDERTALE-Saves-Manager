#ifndef SAVELISTWIDGET_HPP
#define SAVELISTWIDGET_HPP

#include <QtWidgets>

#include "cwidgets/UnProfile.hpp"

class SaveListWidget : public QListWidget
{

public:

    SaveListWidget();

    void createObjects();
    void createSettings();

    int currentSaveID();
    QString currentSaveFolder();
    void setSaveFolder(int lID, QString lFolder);

    void clearAll();
    void addSave(UnProfile *save);
    void loadSave(QAbstractButton *save);

    QAbstractButton * currentSave();

private:

    QList<QAbstractButton*>     mSavesList;
    QList<UnProfile *>          mSavesList2;
    QHash<int, QString>         mSavesFolder;
    QButtonGroup                *mSavesGroup;
};

#endif // SAVELISTWIDGET_HPP
