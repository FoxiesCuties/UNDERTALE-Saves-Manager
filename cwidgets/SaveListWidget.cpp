#include "SaveListWidget.hpp"

SaveListWidget::SaveListWidget()
{
    createObjects();
    createSettings();
}

//Organisers
void SaveListWidget::createObjects()
{
    mSavesGroup = new QButtonGroup;
}
void SaveListWidget::createSettings()
{
    mSavesGroup->setExclusive(true);
}

//Methods
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
        aProfile->setFile0(save->file0());
        aProfile->setIdentifier(mProfileSavesList.count());

        connect(aProfile, SIGNAL(deleteSaveID(int)), this, SLOT(delSaveFolder(int)));

    mProfileSavesList.append(aProfile);

    mSavesGroup->addButton(mProfileSavesList.last(), mProfileSavesList.length()-1);

    QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(item->sizeHint().width(), mProfileSavesList.last()->height()+2));

    addItem(item);
    setItemWidget(item, mProfileSavesList.last());
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
