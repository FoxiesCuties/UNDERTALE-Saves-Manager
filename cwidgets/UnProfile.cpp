#include "UnProfile.hpp"

UnProfile::UnProfile()
{
    createObjects();
    createConnexions();
    createInterface();
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
    mSaveDetails    = new SaveDetails;
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
            mRoomValue->setText("Snowdin - town");
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
            mRoomValue->setText("N/A");
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
QVariant UnProfile::file0()
{
    return mFile0Variant;
}

//TODO Move to SaveDetails
QVariant UnProfile::getValue(QString file, int line)
{
        QFile pfile(file);
        if (!pfile.open(QIODevice::ReadOnly | QIODevice::Text))
           return "";

        QTextStream in(&pfile);

        for(int p=1; p<=line; p++)
        {
            if (p == line) {

                QVariant tmp = in.readLine();

                pfile.flush();
                pfile.close();

                return tmp;
            } else {
                in.readLine();
            }
        }
}
QVariant UnProfile::getNxExp(int lvl, int cexp)
{
    switch (lvl) {
    case 1:
        return QString::number(10-cexp);
        break;
    case 2:
        return QString::number(30-cexp);
        break;
    case 3:
        return QString::number(70-cexp);
        break;
    case 4:
        return QString::number(120-cexp);
        break;
    case 5:
        return QString::number(200-cexp);
        break;
    case 6:
        return QString::number(300-cexp);
        break;
    case 7:
        return QString::number(500-cexp);
        break;
    case 8:
        return QString::number(800-cexp);
        break;
    case 9:
        return QString::number(1200-cexp);
        break;
    case 10:
        return QString::number(1700-cexp);
        break;
    case 11:
        return QString::number(2500-cexp);
        break;
    case 12:
        return QString::number(3500-cexp);
        break;
    case 13:
        return QString::number(5000-cexp);
        break;
    case 14:
        return QString::number(7000-cexp);
        break;
    case 15:
        return QString::number(10000-cexp);
        break;
    case 16:
        return QString::number(15000-cexp);
        break;
    case 17:
        return QString::number(25000-cexp);
        break;
    case 18:
        return QString::number(50000-cexp);
        break;
    case 19:
        return QString::number(99999-cexp);
        break;
    default:
        break;
    }
}
QVariant UnProfile::getWeapon(int idWeapon)
{
    switch (idWeapon) {
    case 3:
        return "Stick";
        break;
    case 13:
        return "Toy Knife";
        break;
    case 14:
        return "Tough Glove";
        break;
    case 45:
        return "Torn Notebook";
        break;
    case 47:
        return "Burnt Pan";
        break;
    case 49:
        return "Empty Gun";
        break;
    case 51:
        return "Worn Dagger";
        break;
    case 52:
        return "Real Knife";
        break;
    default:
        break;
    }
}
QVariant UnProfile::getArmor(int idArmor)
{
    switch (idArmor) {
    case 4:
        return "Bandage";
        break;
    case 12:
        return "Faded Ribbon";
        break;
    case 15:
        return "Manly Bandanna";
        break;
    case 24:
        return "Old Tutu";
        break;
    case 44:
        return "Butty Glasses";
        break;
    case 46:
        return "Stained Apron";
        break;
    case 48:
        return "Cowboy Hat";
        break;
    case 50:
        return "Heart Locket";
        break;
    case 53:
        return "The Locket";
        break;
    case 64:
        return "Temy Armor";
        break;
    default:
        break;
    }
}

//Events
void UnProfile::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mSaveDetails->setGameNameVal("\""+getValue( file0().toString(), 1 ).toString()+"\"");
        mSaveDetails->setGameLoveVal(getValue( file0().toString(), 2 ).toString());
        mSaveDetails->setGameHealthVal(getValue( file0().toString(), 3 ).toString());
        mSaveDetails->setGameExpVal(getValue( file0().toString(), 10 ).toString());
        mSaveDetails->setGameNExpVal(getNxExp(getValue(file0().toString(),2).toInt(), getValue( file0().toString(), 10 ).toInt()).toString());
        mSaveDetails->setGameWeapVal(getWeapon(getValue( file0().toString(), 29 ).toInt()).toString());
        mSaveDetails->setGameArmrVal(getArmor(getValue( file0().toString(), 30 ).toInt()).toString());
        mSaveDetails->setGameGoldVal(getValue( file0().toString(), 11 ).toString());
        //------------------------
        mSaveDetails->setRoomNumber(mRoomNumber);
        mSaveDetails->exec();
    }
}

//Slots
void UnProfile::deleteSave()
{
    emit deleteSaveID(identifier());
}
