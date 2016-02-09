#include "ItemsTab.hpp"

ItemsTab::ItemsTab()
{
    createObjects();
    createConnexions();
    createInterface();
    createObjectsName();
}

//Regions
void ItemsTab::createObjects()
{
    mItemsList          = new QListWidget;
    mItemInfoTextEdit   = new QTextEdit;
    mDetailsItemsVBox   = new QVBoxLayout;
}
void ItemsTab::createConnexions()
{
    connect(mItemsList,         SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)), this,
                                SLOT(changeUnItem(QListWidgetItem*, QListWidgetItem*)));
}
void ItemsTab::createInterface()
{
    mItemsList->setFixedHeight(170);
    mItemsList->setCurrentRow(0);

    mDetailsItemsVBox->addWidget(mItemsList, 1, Qt::AlignTop);
    mDetailsItemsVBox->addWidget(mItemInfoTextEdit, 0, Qt::AlignBottom);

    mItemInfoTextEdit->setFocusPolicy(Qt::NoFocus);
    mItemInfoTextEdit->setFixedHeight(50);
    mItemInfoTextEdit->setReadOnly(true);
    mItemInfoTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    mItemInfoTextEdit->viewport()->setCursor(Qt::ArrowCursor);

    this->setLayout(mDetailsItemsVBox);
}
void ItemsTab::createObjectsName()
{
    mItemsList->setObjectName("ListWidget_Items");
    mItemInfoTextEdit->setObjectName("TextEdit_Items");
}

//Methods
QListWidget* ItemsTab::itemsList()
{
    return mItemsList;
}

//Slots
void ItemsTab::setUnItem(QString name, QString info)
{
    if (mItemsList->count() == 0) {
        mItemsList->addItem(new QListWidgetItem(QIcon(":imgs/heart"),""));
    } else {
        mItemsList->addItem(new QListWidgetItem(QIcon(":imgs/noheart"),""));
    }

    QStringList strList;
        strList.append(name);
        strList.append(info);

    mItemDetails.append(strList);

    mItemsList->item(mItemsList->count() - 1)->setText(name);
}
void ItemsTab::changeUnItem(QListWidgetItem* cur, QListWidgetItem* pre)
{
    if (cur != 0) {
        cur->setIcon(QIcon(":imgs/heart"));
        mItemInfoTextEdit->setText(mItemDetails.at(mItemsList->currentRow()).at(1));
    }

    if (pre != 0) {
        pre->setIcon(QIcon(":imgs/noheart"));
    }
}
