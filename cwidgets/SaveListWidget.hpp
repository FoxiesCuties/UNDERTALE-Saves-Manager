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

    void clearAll();
    void addSave(UnProfile *save);
    void loadSave(QAbstractButton *save);

    QAbstractButton * currentSave();

private:

    QButtonGroup                *mSavesGroup;
    QList<QAbstractButton*>     mSavesList;
    QList<UnProfile *>          mSavesList2;
};

#endif // SAVELISTWIDGET_HPP
