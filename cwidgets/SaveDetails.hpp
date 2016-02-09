#ifndef SAVEDETAILS_HPP
#define SAVEDETAILS_HPP

#include <QtWidgets>

#include "cwidgets/SaveDetails/StatsTab.hpp"
#include "cwidgets/SaveDetails/ItemsTab.hpp"

class SaveDetails : public QDialog
{
    Q_OBJECT

public:

    SaveDetails(QWidget * parent = 0);

    //Regions
    void createObjects();
    void createConnexions();
    void createInterface();
    void createObjectNames();
    void createSettings();

    //Methods
    StatsTab*    statsTab();
    ItemsTab*    itemsTab();

    void setRoomNumber(int room);

    //Events
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

public slots:

    void setCurentTab(int tab);

private:

    int                 mRoomInt;
    QPoint              mGamePoint;
    QPixmap             mRoomPixmap;
    QLabel              *mRoomPixLab;
    StatsTab            *mStatsTab;
    ItemsTab            *mItemsTab;
    QHBoxLayout         *mTabWidgetHBox;
    QTabWidget          *mDetailsTabWidget;
    QHBoxLayout         *mDetailsHbox;
    QPushButton         *mDetCloseBut;
};

#endif // SAVEDETAILS_HPP
