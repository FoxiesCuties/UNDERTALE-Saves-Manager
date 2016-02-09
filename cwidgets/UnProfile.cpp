#include "UnProfile.hpp"

UnProfile::UnProfile()
{
    createObjects();
    createConnexions();
    createInterface();
    createObjectName();
    createSettings();
}

void UnProfile::createObjects()
{
    mNameValue      = new QLabel;
    mLoveValue      = new QLabel;
    mTimeValue      = new QLabel;
    mRoomValue      = new QLabel;
    mDeleteBut      = new QPushButton;
    mProfileGrid    = new QGridLayout;
    mSaveDetails    = new SaveDetails(this);
    mSaveFile0      = new USaveFile;
}
void UnProfile::createConnexions()
{
    connect(mDeleteBut, SIGNAL(clicked()), this, SLOT(deleteSave()));
}
void UnProfile::createInterface()
{
    mProfileGrid->addWidget(mNameValue, 0,0,1,2, Qt::AlignLeft  | Qt::AlignTop);
    mProfileGrid->addWidget(mLoveValue, 0,2,1,1, Qt::AlignLeft  | Qt::AlignTop);
    mProfileGrid->addWidget(mTimeValue, 0,3,1,1, Qt::AlignRight | Qt::AlignTop);
    mProfileGrid->addWidget(mRoomValue, 2,0,1,4, Qt::AlignLeft  | Qt::AlignBottom);
    mProfileGrid->addWidget(mDeleteBut, 2,3,1,1, Qt::AlignRight | Qt::AlignBottom);
}
void UnProfile::createObjectName()
{
    mDeleteBut->setObjectName("Button_DeleteSave");
}
void UnProfile::createSettings()
{
    //Profile Property
    mNameValue->setProperty("Title", 1);
    mLoveValue->setProperty("Title", 1);
    mTimeValue->setProperty("Title", 1);
    mRoomValue->setProperty("Title", 2);

    //Profile Settings
    this->setFixedHeight(90);
    this->setCheckable(true);
    this->setLayout(mProfileGrid);
    this->setContentsMargins(6,0,6,6);
    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored);
}

//Setters
void UnProfile::setIdentifier(int id)
{
    mSaveIdInt = id;
}
void UnProfile::setName(QVariant name)
{
    mNameVariant = name;

    mNameValue->setText(mNameVariant.toString());
}
void UnProfile::setLove(QVariant love)
{
    mLoveVariant = love;

    mLoveValue->setText("LV"+mLoveVariant.toString().section(".",0,0));
}
void UnProfile::setTime(QVariant frms)
{
    mTimeVariant = frms;

    double frames = mTimeVariant.toString().section(".",0,0).toDouble();

    //convert frames to secondes
    double seconde = frames / 30;

    int secondes = seconde;

    //if double is superior to .49xxx...
    if (QString::number(seconde).section(".",1,1) >= "5") {
        secondes += 1;
    }

    if (secondes % 60 < 10) {
        mTimeValue->setText(QString::number(secondes/60)+":0"+QString::number(secondes%60));
    } else {
        mTimeValue->setText(QString::number(secondes/60)+":"+QString::number(secondes%60));
    }
}
void UnProfile::setRoom(QVariant room)
{
    mRoomVariant    = room;
    mRoomNumber     = mRoomVariant.toString().section(".", 0, 0).toInt();

    //Convert room number to room name
    switch (mRoomNumber) {
        case 6:
            mRoomValue->setText("Ruins - Entrance");
                break;
        case 12:
            mRoomValue->setText("Ruins - Leaf Pile");
                break;
        case 18:
            mRoomValue->setText("Ruins - Mouse Hole");
                break;
        case 31:
            mRoomValue->setText("Ruins - Home");
                break;
        case 46:
            mRoomValue->setText("Snowdin - Box Road");
                break;
        case 56:
            mRoomValue->setText("Snowdin - Spaghetti");
                break;
        case 61:
            mRoomValue->setText("Snowdin - Dog House");
                break;
        case 68:
            mRoomValue->setText("Snowdin - Town");
                break;
        case 83:
            mRoomValue->setText("Waterfall - Checkpoint");
                break;
        case 94:
            mRoomValue->setText("Waterfall - Crystal");
                break;
        case 110:
            mRoomValue->setText("Waterfall - Bridge");
                break;
        case 114:
            mRoomValue->setText("Waterfall - Trash Zone");
                break;
        case 116:
            mRoomValue->setText("Waterfall - Quiet Area");
                break;
        case 128:
            mRoomValue->setText("Waterfall - Temmie Village");
                break;
        case 134:
            mRoomValue->setText("Waterfall - Undyne Arena");
                break;
        case 139:
            mRoomValue->setText("Hotland - Laboratory Entrance");
                break;
        case 145:
            mRoomValue->setText("Hotland - Magma Chamber");
                break;
        case 155:
            mRoomValue->setText("Hotland - Core View");
                break;
        case 164:
            mRoomValue->setText("Hotland - Bad Opinion Zone");
                break;
        case 176:
            mRoomValue->setText("Hotland - Spider Entrance");
                break;
        case 183:
            mRoomValue->setText("Hotland - Hotel Lobby");
                break;
        case 196:
            mRoomValue->setText("Hotland - Core Branch");
                break;
        case 210:
            mRoomValue->setText("Hotland - Core End");
                break;
        case 216:
            mRoomValue->setText("Castle Elevator");
                break;
        case 219:
            mRoomValue->setText("New Home");
                break;
        case 231:
            mRoomValue->setText("Last Corridor");
                break;
        case 232:
            mRoomValue->setText("Throne Entrance");
                break;
        case 235:
            mRoomValue->setText("Throne Room");
                break;
        case 236:
            mRoomValue->setText("The End");
                break;
        case 246:
            mRoomValue->setText("True Laboratory");
                break;
        case 251:
            mRoomValue->setText("True Lab - Bedroom");
                break;
        default:
            mRoomValue->setText("");
                break;
    }
}
void UnProfile::setFile0(QVariant file)
{
    mFile0Variant = file;
}

//Getters
int UnProfile::identifier()
{
    return mSaveIdInt;
}
QVariant UnProfile::name()
{
    return mNameVariant;
}
QVariant UnProfile::love()
{
    return mLoveVariant;
}
QVariant UnProfile::time()
{
    return mTimeVariant;
}
QVariant UnProfile::room()
{
    return mRoomVariant;
}
QString  UnProfile::file0()
{
    return mFile0Variant.toString();
}

//Events
void UnProfile::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

        mSaveFile0->setSaveFile(file0());

        mSaveDetails->setGameNameVal(mSaveFile0->charName());
        mSaveDetails->setGameLoveVal(mSaveFile0->charLV());
        mSaveDetails->setGameHealthVal(mSaveFile0->charHP());
        mSaveDetails->setGameAtkVal(mSaveFile0->charBaseAtk());
        mSaveDetails->setGameBnxAtkVal(mSaveFile0->charWeaponAtk());
        mSaveDetails->setGameExpVal(mSaveFile0->charEXP());
        mSaveDetails->setGameDefVal(mSaveFile0->charBaseDef());
        mSaveDetails->setGameBnxDefVal(mSaveFile0->charArmorDef());
        mSaveDetails->setGameNExpVal(mSaveFile0->charNextLV());
        mSaveDetails->setGameWeapVal(mSaveFile0->charWeapon());
        mSaveDetails->setGameArmrVal(mSaveFile0->charArmor());
        mSaveDetails->setGameGoldVal(mSaveFile0->charGold());
        mSaveDetails->setGameKillVal(mSaveFile0->charKills());

        for (int i = 13; i <= 27; i += 2)
        {
            int itemID = mSaveFile0->charValue(i).toInt();

            if (itemID != 0) {
                mSaveDetails->setUnItem(    mSaveFile0->getItem(itemID).at(0).toString(),
                                            mSaveFile0->getItem(itemID).at(1).toString());
            }
        }

        mSaveDetails->setRoomNumber(mRoomNumber);
        mSaveDetails->exec();
    }
}

//Slots
void UnProfile::deleteSave()
{
    emit deleteSaveID(identifier());
}
