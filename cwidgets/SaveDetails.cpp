#include "SaveDetails.hpp"

SaveDetails::SaveDetails()
{
    createObjects();
    createConnexions();
    createInterface();
    createSettings();
}

void SaveDetails::createObjects()
{
    mGameNameVal    = new QLabel;
    mGameLoveVal    = new QLabel;
    mGameHealthVal  = new QLabel;
    mGameAtkVal     = new QLabel;
    mGameExpVal     = new QLabel;
    mGameDefVal     = new QLabel;
    mGameNExpVal    = new QLabel;
    mGameWeapVal    = new QLabel;
    mGameArmrVal    = new QLabel;
    mGameGoldVal    = new QLabel;
    mRoomPixLab     = new QLabel;
    mNameHBox       = new QHBoxLayout;
    mLoveHBox       = new QHBoxLayout;
    mHPHBox         = new QHBoxLayout;
    mAtExpHBox      = new QHBoxLayout;
    mDfNxtHBox      = new QHBoxLayout;
    mWeapHBox       = new QHBoxLayout;
    mArmorHBox      = new QHBoxLayout;
    mGoldHBox       = new QHBoxLayout;
    mDetailsVbox    = new QVBoxLayout;
    mDetailsHbox    = new QHBoxLayout;
    mDetCloseBut    = new QPushButton;
}
void SaveDetails::createConnexions()
{
    connect(mDetCloseBut, SIGNAL(clicked()), this, SLOT(close()));
}
void SaveDetails::createInterface()
{
    mNameHBox->addWidget(mGameNameVal);
    mNameHBox->setAlignment(Qt::AlignTop);

    mLoveHBox->addWidget(new QLabel("LV"));
    mLoveHBox->addWidget(mGameLoveVal,1);
    mLoveHBox->setAlignment(Qt::AlignBottom);

    mHPHBox->addWidget(new QLabel("HP"));
    mHPHBox->addWidget(mGameHealthVal,1);
    mHPHBox->setAlignment(Qt::AlignTop);

    mAtExpHBox->addWidget(new QLabel("AT"));
    mAtExpHBox->addWidget(mGameAtkVal,1);
    mAtExpHBox->addWidget(new QLabel("EXP :"),0,Qt::AlignRight);
    mAtExpHBox->addWidget(mGameExpVal,1);
    mAtExpHBox->setAlignment(Qt::AlignBottom);

    mDfNxtHBox->addWidget(new QLabel("DF"));
    mDfNxtHBox->addWidget(mGameDefVal,1);
    mDfNxtHBox->addWidget(new QLabel("NEXT:"),0,Qt::AlignRight);
    mDfNxtHBox->addWidget(mGameNExpVal,1);
    mDfNxtHBox->setAlignment(Qt::AlignTop);

    mWeapHBox->addWidget(new QLabel("WEAPON:"));
    mWeapHBox->addWidget(mGameWeapVal,1);
    mWeapHBox->setAlignment(Qt::AlignBottom);

    mArmorHBox->addWidget(new QLabel("ARMOR :"));
    mArmorHBox->addWidget(mGameArmrVal,1);
    mArmorHBox->setAlignment(Qt::AlignTop);

    mGoldHBox->addWidget(new QLabel("GOLD:"));
    mGoldHBox->addWidget(mGameGoldVal,1);
    mGoldHBox->addWidget(mDetCloseBut,1,Qt::AlignRight);

    mDetailsVbox->addLayout(mNameHBox,0);
    mDetailsVbox->addLayout(mLoveHBox,0);
    mDetailsVbox->addLayout(mHPHBox,0);
    mDetailsVbox->addLayout(mAtExpHBox,0);
    mDetailsVbox->addLayout(mDfNxtHBox,0);
    mDetailsVbox->addLayout(mWeapHBox,0);
    mDetailsVbox->addLayout(mArmorHBox,0);
    mDetailsVbox->addLayout(mGoldHBox);
    mDetailsVbox->setContentsMargins(5,0,0,0);

    mDetailsHbox->addWidget(mRoomPixLab);
    mDetailsHbox->addLayout(mDetailsVbox);

    mDetCloseBut->setText("CLOSE");

    mRoomPixLab->setStyleSheet("border: 1px solid #8ec8fa;"
                               "border-left:none;");
}
void SaveDetails::createSettings()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    this->setLayout(mDetailsHbox);
    this->setContentsMargins(5,5,0,5);
    this->setStyleSheet("QDialog{background: black; border: 5px Solid white;}"
                        "QLabel{color: white; font-weight: bold;"
                        "font-family: Determination Mono;"
                        "font-size: 12pt;"
                        "font-weight: bold;}"
                        "QPushButton{margin-right: 3px; border: none; color: #e61; padding: 1 5 1 5;"
                        "border: 1px solid #e61;"
                        "font-family: Determination Mono;"
                        "font-size: 12pt;}"
                        "QPushButton:hover{border-color:#f6e100; color: #f6e100;}");
}

//Slots
void SaveDetails::setRoomNumber(int room)
{
    mRoomInt = room;

    this->setWindowTitle("Save Details - Room " + QString::number(mRoomInt));

    mRoomPixmap.load(":imgs/rooms/" + QString::number(mRoomInt));

    mRoomPixLab->setPixmap(mRoomPixmap.scaled(320, 240));

    this->setFixedHeight(this->sizeHint().height());
    this->setFixedWidth(600);
}
void SaveDetails::setPoint(QPoint point)
{
    //move(point - rect().center());
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
    mGameHealthVal->setText(val+"/ "+val);
}
void SaveDetails::setGameAtkVal(QString val)
{
    mGameAtkVal->setText(val);
}
void SaveDetails::setGameExpVal(QString val)
{
    mGameExpVal->setText(val);
}
void SaveDetails::setGameDefVal(QString val)
{
    mGameDefVal->setText(val);
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
