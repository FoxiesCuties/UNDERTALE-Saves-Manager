#include "SaveDetails.hpp"

SaveDetails::SaveDetails(QWidget *parent) : QDialog(parent)
{
    createObjects();
    createConnexions();
    createObjectNames();
    createInterface();
    createSettings();
}

void SaveDetails::createObjects()
{
    mGameNameVal        = new QLabel;
    mGameLoveVal        = new QLabel;
    mGameHealthVal      = new QLabel;
    mGameAtkVal         = new QLabel;
    mGameBnxAtkVal      = new QLabel;
    mGameExpVal         = new QLabel;
    mGameDefVal         = new QLabel;
    mGameBnxDefVal      = new QLabel;
    mGameNExpVal        = new QLabel;
    mGameWeapVal        = new QLabel;
    mGameArmrVal        = new QLabel;
    mGameGoldVal        = new QLabel;
    mGameKillLab        = new QLabel;
    mGameKillVal        = new QLabel;
    mRoomPixLab         = new QLabel;
    mNameHBox           = new QHBoxLayout;
    mLoveHBox           = new QHBoxLayout;
    mHPHBox             = new QHBoxLayout;
    mAtExpHBox          = new QHBoxLayout;
    mDfNxtHBox          = new QHBoxLayout;
    mWeapHBox           = new QHBoxLayout;
    mArmorHBox          = new QHBoxLayout;
    mGoldHBox           = new QHBoxLayout;
    mDetailsVbox        = new QVBoxLayout;
    mDetailsHbox        = new QHBoxLayout;
    mDetCloseBut        = new QPushButton;
    mStatsTab           = new QWidget;
    mBagTab             = new QWidget;
    mTabWidgetHBox      = new QHBoxLayout;
    mDetailsTabWidget   = new QTabWidget;
}
void SaveDetails::createConnexions()
{
    connect(mDetCloseBut, SIGNAL(clicked()), this, SLOT(close()));
}
void SaveDetails::createInterface()
{
    mNameHBox->addWidget(mGameNameVal);
    mNameHBox->setAlignment(Qt::AlignTop);

    mLoveHBox->addWidget(new QLabel("LV "));
    mLoveHBox->addWidget(mGameLoveVal,1);
    mLoveHBox->setAlignment(Qt::AlignBottom);

    mHPHBox->addWidget(new QLabel("HP "));
    mHPHBox->addWidget(mGameHealthVal,1);
    mHPHBox->setAlignment(Qt::AlignTop);

    mAtExpHBox->addWidget(new QLabel("AT "));
    mAtExpHBox->addWidget(mGameAtkVal);
    mAtExpHBox->addWidget(mGameBnxAtkVal);
    mAtExpHBox->addWidget(new QLabel("   EXP:"),0,Qt::AlignRight);
    mAtExpHBox->addWidget(mGameExpVal,1);
    mAtExpHBox->setAlignment(Qt::AlignBottom);

    mDfNxtHBox->addWidget(new QLabel("DF "));
    mDfNxtHBox->addWidget(mGameDefVal);
    mDfNxtHBox->addWidget(mGameBnxDefVal);
    mDfNxtHBox->addWidget(new QLabel("    NEXT:"),0,Qt::AlignRight);
    mDfNxtHBox->addWidget(mGameNExpVal,1);
    mDfNxtHBox->setAlignment(Qt::AlignTop);

    mWeapHBox->addWidget(new QLabel("WEAPON:"));
    mWeapHBox->addWidget(mGameWeapVal,1);
    mWeapHBox->setAlignment(Qt::AlignBottom);

    mArmorHBox->addWidget(new QLabel("ARMOR:"));
    mArmorHBox->addWidget(mGameArmrVal,1);
    mArmorHBox->setAlignment(Qt::AlignTop);

    mGoldHBox->addWidget(new QLabel("GOLD:"));
    mGoldHBox->addWidget(mGameGoldVal,1);
    mGoldHBox->addWidget(mGameKillLab);
    mGoldHBox->addWidget(mGameKillVal,1);

    mDetailsVbox->addLayout(mNameHBox,0);
    mDetailsVbox->addLayout(mLoveHBox,0);
    mDetailsVbox->addLayout(mHPHBox,0);
    mDetailsVbox->addLayout(mAtExpHBox,0);
    mDetailsVbox->addLayout(mDfNxtHBox,0);
    mDetailsVbox->addLayout(mWeapHBox,0);
    mDetailsVbox->addLayout(mArmorHBox,0);
    mDetailsVbox->addLayout(mGoldHBox);
    mDetailsVbox->setContentsMargins(5,5,0,0);
    mDetailsVbox->setSpacing(0);

    mStatsTab->setLayout(mDetailsVbox);

    mTabWidgetHBox->addWidget(mDetCloseBut,1,Qt::AlignRight | Qt::AlignTop);
    mTabWidgetHBox->setContentsMargins(0,0,0,0);

    mDetailsTabWidget->setTabPosition(QTabWidget::North);
    mDetailsTabWidget->addTab(mStatsTab, "STATS");
    mDetailsTabWidget->addTab(new QWidget, "");
    mDetailsTabWidget->addTab(mBagTab, "BAG");//WIP soon
    mDetailsTabWidget->setTabEnabled(1, false);
    mDetailsTabWidget->setLayout(mTabWidgetHBox);

    mDetailsHbox->addWidget(mRoomPixLab);
    mDetailsHbox->addWidget(mDetailsTabWidget);
    mDetailsHbox->setContentsMargins(10,10,15,10);

    mGameKillLab->setText("  KILLS:");
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
    this->setContentsMargins(5,5,0,5);
}

//Slots
void SaveDetails::setRoomNumber(int room)
{
    mRoomInt = room;

    this->setWindowTitle("Save Details - Room " + QString::number(mRoomInt));

    mRoomPixmap.load(":imgs/rooms/" + QString::number(mRoomInt));

    mRoomPixLab->setPixmap(mRoomPixmap.scaled(380, 300));

    this->setFixedHeight(this->sizeHint().height());
    this->setFixedWidth(660);
}

void SaveDetails::setGameNameVal(QString val)
{
    mGameNameVal->setText(val);
}
void SaveDetails::setGameLoveVal(QString val)
{
    mGameLoveVal->setText(val);
}
void SaveDetails::setGameHealthVal(QString val)
{
    QString charHP = val.section(" ",0,0);//WIP tiny hack for remove space.

    mGameHealthVal->setText(charHP+"/"+charHP);
}
void SaveDetails::setGameAtkVal(QString val)
{
    mGameAtkVal->setText(val);
}
void SaveDetails::setGameBnxAtkVal(QString val)
{
    mGameBnxAtkVal->setText("("+val+")");
}
void SaveDetails::setGameExpVal(QString val)
{
    mGameExpVal->setText(val);
}
void SaveDetails::setGameDefVal(QString val)
{
    mGameDefVal->setText(val);
}
void SaveDetails::setGameBnxDefVal(QString val)
{
    mGameBnxDefVal->setText("("+val+")");
}
void SaveDetails::setGameNExpVal(QString val)
{
    mGameNExpVal->setText(val);
}
void SaveDetails::setGameWeapVal(QString val)
{
    mGameWeapVal->setText(val);
}
void SaveDetails::setGameArmrVal(QString val)
{
    mGameArmrVal->setText(val);
}
void SaveDetails::setGameGoldVal(QString val)
{
    mGameGoldVal->setText(val);
}
void SaveDetails::setGameKillVal(QString val)
{
    if(val.toInt() > 0){
        mGameKillLab->show();
        mGameKillVal->setText(val);
    } else {
        mGameKillLab->hide();
    }
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
