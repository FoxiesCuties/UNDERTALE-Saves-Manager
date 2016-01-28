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

    mSavesList2.clear();
}
void SaveListWidget::addSave(UnProfile *save)
{
    UnProfile *s = new UnProfile;
        s->setName(save->name());
        s->setLove(save->love());
        s->setTime(save->time());
        s->setRoom(save->room());
        s->setIdentifier(mSavesList2.count());

        connect(s, SIGNAL(deleteSaveID(int)), this, SLOT(delSaveFolder(int)));

    mSavesList2.append(s);

    mSavesGroup->addButton(mSavesList2.last(), mSavesList2.length()-1);

    QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(item->sizeHint().width(), mSavesList2.last()->height()+2));

    addItem(item);
    setItemWidget(item, mSavesList2.last());
}
void SaveListWidget::loadSave(QAbstractButton *save)
{
    this->clear();
    mSavesList2.clear();

    UnProfile *h = qobject_cast<UnProfile *>(save);

    UnProfile *s = new UnProfile;
        s->setName(h->name());
        s->setLove(h->love());
        s->setTime(h->time());
        s->setRoom(h->room());

    mSavesList2.append(s);

    QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(item->sizeHint().width(), mSavesList2.last()->height()+2));

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
