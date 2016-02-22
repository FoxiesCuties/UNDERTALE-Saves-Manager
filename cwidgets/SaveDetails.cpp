#include "SaveDetails.hpp"

SaveDetails::SaveDetails(QWidget *parent) : QDialog(parent)
{
    createObjects();
    createConnexions();
    createObjectNames();
    createInterface();
    createSettings();
}

//Regions
void SaveDetails::createObjects()
{
    mStatsTab           = new StatsTab;
    mItemsTab           = new ItemsTab;
    mTabWidgetHBox      = new QHBoxLayout;
    mDetailsTabWidget   = new QTabWidget;
    mDetCloseBut        = new QPushButton;

    mDetailsHbox        = new QHBoxLayout;
    mRoomPixMovie       = new QMovie;
    mRoomPixLab         = new QLabel;
}
void SaveDetails::createConnexions()
{
    connect(mDetailsTabWidget,  SIGNAL(currentChanged(int)), this, SLOT(setCurentTab(int)));
    connect(mDetCloseBut,       SIGNAL(clicked()), this, SLOT(closeSaveDetails()));
}
void SaveDetails::createInterface()
{
    mTabWidgetHBox->addWidget(mDetCloseBut,1,Qt::AlignRight | Qt::AlignTop);
    mTabWidgetHBox->setContentsMargins(0,0,0,0);

    mDetailsTabWidget->setTabPosition(QTabWidget::North);
    mDetailsTabWidget->addTab(mStatsTab, "STATS");
    mDetailsTabWidget->addTab(new QWidget, "");
    mDetailsTabWidget->addTab(mItemsTab, "ITEMS");
    mDetailsTabWidget->setTabEnabled(1, false);
    mDetailsTabWidget->setLayout(mTabWidgetHBox);

    mDetailsHbox->addWidget(mRoomPixLab);
    mDetailsHbox->addWidget(mDetailsTabWidget);
    mDetailsHbox->setContentsMargins(10,10,15,10);
}
void SaveDetails::createObjectNames()
{
    this->setObjectName("Dialog_Details");
    mDetCloseBut->setObjectName("Button_Details_Close");
    mRoomPixLab->setObjectName("Label_Details_Room");
    mDetailsTabWidget->setObjectName("TabWidget_Details");
}
void SaveDetails::createSettings()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    this->setLayout(mDetailsHbox);
    this->setContentsMargins(5, 5, 0, 5);
    this->setFixedSize(720, 364);
}

//Methods
StatsTab*   SaveDetails::statsTab()
{
    return mStatsTab;
}
ItemsTab*   SaveDetails::itemsTab()
{
    return mItemsTab;
}

void SaveDetails::setRoomNumber(int room)
{
    mRoomInt = room;

    this->setWindowTitle("Save Details - Room " + QString::number(mRoomInt));

    QString mngPath = qApp->applicationDirPath()+"/assets/imgs/pixmaps/rooms/"+QString::number(mRoomInt)+".mng";

    if (QFile::exists(mngPath)) {
        mRoomPixMovie->setFileName(mngPath);
    } else {
        mRoomPixMovie->setFileName(":imgs/rooms/" + QString::number(0));
    }

    mRoomPixMovie->setScaledSize(QSize(440, 330));

    mRoomPixLab->setMovie(mRoomPixMovie);
}

//Slots
void SaveDetails::setCurentTab(int tab)
{
    if (tab == 2) {
        mItemsTab->itemsList()->setFocus();
    }
}
void SaveDetails::openSaveDetails()
{
    mRoomPixMovie->start();
    this->exec();
}
void SaveDetails::closeSaveDetails()
{
    mRoomPixMovie->stop();
    this->close();
}

//Events
void SaveDetails::keyPressEvent(QKeyEvent *event)
{
    event->ignore();
}
void SaveDetails::closeEvent(QCloseEvent *event)
{
    //Accept only internal closing events
    event->setAccepted(!event->spontaneous());
}
