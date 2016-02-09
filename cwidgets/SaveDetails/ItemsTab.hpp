#ifndef ITEMSTAB_HPP
#define ITEMSTAB_HPP

#include <QtWidgets>

class ItemsTab : public QWidget
{
    Q_OBJECT

public:

    ItemsTab();

    //Regions
    void createObjects();
    void createConnexions();
    void createInterface();
    void createObjectsName();

    //Methods
    QListWidget*    itemsList();
    void setUnItem(QString name, QString info);

public slots:

    void changeUnItem(QListWidgetItem* cur, QListWidgetItem* pre);

private:

    QList<QStringList>  mItemDetails;
    QListWidget         *mItemsList;
    QTextEdit           *mItemInfoTextEdit;
    QVBoxLayout         *mDetailsItemsVBox;
};

#endif // ITEMSTAB_HPP
