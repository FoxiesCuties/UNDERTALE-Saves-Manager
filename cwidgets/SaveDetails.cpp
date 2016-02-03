#include "SaveDetails.hpp"

SaveDetails::SaveDetails()
{
    createObjects();
    createInterface();
}

void SaveDetails::createObjects()
{
    mGameTypeLab    = new QLabel;
    mGameTypeVal    = new QLabel;
    mGameGoldLab    = new QLabel;
    mGameGoldVal    = new QLabel;
    mDetailsHbox    = new QHBoxLayout;
    mRoomPixLab     = new QLabel;
    mDetailsGrid    = new QGridLayout;
    mAstPath        = qApp->applicationDirPath()+"/assets/imgs/pixmaps/rooms/";
}
void SaveDetails::createInterface()
{
    mGameTypeLab->setText("TYPE :");
    mGameTypeVal->setText("GENOCID");
    mGameGoldLab->setText("GOLD :");
    mGameGoldVal->setText("742");

    mDetailsGrid->addWidget(mGameTypeLab, 0, 0, 1, 1);
    mDetailsGrid->addWidget(mGameTypeVal, 0, 1, 1, 1);
    mDetailsGrid->addWidget(mGameGoldLab, 1, 0, 1, 1);
    mDetailsGrid->addWidget(mGameGoldVal, 1, 1, 0, 0);

    mDetailsHbox->addWidget(mRoomPixLab);
    mDetailsHbox->addLayout(mDetailsGrid);

    this->setLayout(mDetailsHbox);
    this->setStyleSheet("QDialog{background: black;}");

    mRoomPixLab->setStyleSheet("border: 3px solid white;");
    mGameGoldVal->setStyleSheet("color: white;");
}

//Slots
void SaveDetails::setRoomNumber(int room)
{
    mRoomPixmap.load(":imgs/rooms/" + QString::number(room));

    mRoomPixLab->setPixmap(mRoomPixmap.scaled(320, 240));

    this->setFixedHeight(this->sizeHint().height());
}
