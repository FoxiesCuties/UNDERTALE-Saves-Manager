#include "SaveListWidget.hpp"

SaveListWidget::SaveListWidget()
{
    createObjects();
    createSettings();
}

void SaveListWidget::createObjects()
{
    mSavesGroup = new QButtonGroup;
}
void SaveListWidget::createSettings()
{
    mSavesGroup->setExclusive(true);
}

int SaveListWidget::currentSaveID()
{
    return mSavesGroup->checkedId();
}
QString SaveListWidget::currentSaveFolder()
{
    return mSavesFolder.value(mSavesGroup->checkedId());
}
QString SaveListWidget::saveFolder(int lID)
{
    return mSavesFolder.value(lID);
}
void SaveListWidget::setSaveFolder(int lID, QString lFolder)
{
    mSavesFolder.insert(lID, lFolder);
}

void SaveListWidget::clearAll()
{
    this->clear();

    mProfileSavesList.clear();
}
void SaveListWidget::addSave(UnProfile *save)
{
    UnProfile *aProfile = new UnProfile;
        aProfile->setName(save->name());
        aProfile->setLove(save->love());
        aProfile->setTime(save->time());
        aProfile->setRoom(save->room());
        aProfile->setIdentifier(mProfileSavesList.count());

        connect(aProfile, SIGNAL(deleteSaveID(int)), this, SLOT(delSaveFolder(int)));

    mProfileSavesList.append(aProfile);

    mSavesGroup->addButton(mProfileSavesList.last(), mProfileSavesList.length()-1);

    QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(item->sizeHint().width(), mProfileSavesList.last()->height()+2));

    addItem(item);
    setItemWidget(item, mProfileSavesList.last());
}
void SaveListWidget::loadSave(QAbstractButton *save)
{
    this->clear();
    mProfileSavesList.clear();

    UnProfile *tempProfile = qobject_cast<UnProfile *>(save);

    UnProfile *lProfile = new UnProfile;
        lProfile->setName(tempProfile->name());
        lProfile->setLove(tempProfile->love());
        lProfile->setTime(tempProfile->time());
        lProfile->setRoom(tempProfile->room());

    mProfileSavesList.append(lProfile);

    QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(item->sizeHint().width(), mProfileSavesList.last()->height()+2));

    addItem(item);
    setItemWidget(item, s);
}

QAbstractButton * SaveListWidget::currentSave()
{
    return mSavesGroup->button(mSavesGroup->checkedId());
}

//Slots
void SaveListWidget::delSaveFolder(int id)
{
    emit saveFolderDelete(saveFolder(id));
}
