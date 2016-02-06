#include "USaveFile.hpp"

USaveFile::USaveFile()
{

}

void USaveFile::setSaveFile(QString file0)
{
    mFilename = file0;
}

QVariant USaveFile::charValue(int line)
{
    QFile pfile(mFilename);
    if (!pfile.open(QIODevice::ReadOnly | QIODevice::Text))
       return "";

    QTextStream mSaveStream(&pfile);

    for(int p=1; p<=line; p++)
    {
        if (p == line) {

            QVariant tmp = mSaveStream.readLine();

            pfile.flush();
            pfile.close();

            return tmp;
        } else {
            mSaveStream.readLine();
        }
    }
}

QString USaveFile::charName()
{
    return "\""+charValue(1).toString()+"\"";
}
QString USaveFile::charLV()
{
    return charValue(2).toString();
}
QString USaveFile::charHP()
{
    return charValue(3).toString();
}
QString USaveFile::charBaseAtk()
{
    return getStats(charValue(2).toInt()).at(0).toString();
}
QString USaveFile::charWeaponAtk()
{
    return getWeapon(charValue(29).toInt()).at(1).toString();
}
QString USaveFile::charEXP()
{
    return charValue(10).toString();
}
QString USaveFile::charBaseDef()
{
    return getStats(charValue(2).toInt()).at(1).toString();
}
QString USaveFile::charArmorDef()
{
    return getArmor(charValue(30).toInt()).at(1).toString();
}
QString USaveFile::charNextLV()
{
    return getStats(charValue(2).toInt()).at(2).toString();
}
QString USaveFile::charWeapon()
{
    return getWeapon(charValue(29).toInt()).at(0).toString();
}
QString USaveFile::charArmor()
{
    return getArmor(charValue(30).toInt()).at(0).toString();
}
QString USaveFile::charGold()
{
    return charValue(11).toString();
}
QString USaveFile::charKills()
{
    return charValue(12).toString();
}

QList<QVariant> USaveFile::getWeapon(int idWeapon)
{
    QList<QVariant> lst;

    switch (idWeapon) {
    case 3:
        lst.clear();
        lst.append("Stick");
        lst.append("0");
        return lst;
        break;
    case 13:
        lst.clear();
        lst.append("Toy Knife");
        lst.append("3");
        return lst;
        break;
    case 14:
        lst.clear();
        lst.append("Tough Glove");
        lst.append("5");
        return lst;
        break;
    case 45:
        lst.clear();
        lst.append("Torn Notebook");
        lst.append("2");
        return lst;
        break;
    case 47:
        lst.clear();
        lst.append("Burnt Pan");
        lst.append("10");
        return lst;
        break;
    case 49:
        lst.clear();
        lst.append("Empty Gun");
        lst.append("12");
        return lst;
        break;
    case 51:
        lst.clear();
        lst.append("Worn Dagger");
        lst.append("15");
        return lst;
        break;
    case 52:
        lst.clear();
        lst.append("Real Knife");
        lst.append("99");
        return lst;
        break;
    default:
        break;
    }
}
QList<QVariant> USaveFile::getArmor(int idArmor)
{
    QList<QVariant> lst;

    switch (idArmor) {
    case 4:
        lst.clear();
        lst.append("Bandage");
        lst.append("0");
        return lst;
        break;
    case 12:
        lst.clear();
        lst.append("Faded Ribbon");
        lst.append("3");
        return lst;
        break;
    case 15:
        lst.clear();
        lst.append("Manly Bandanna");
        lst.append("7");
        return lst;
        break;
    case 24:
        lst.clear();
        lst.append("Old Tutu");
        lst.append("10");
        return lst;
        break;
    case 44:
        lst.clear();
        lst.append("Butty Glasses");
        lst.append("6");
        return lst;
        break;
    case 46:
        lst.clear();
        lst.append("Stained Apron");
        lst.append("11");
        return lst;
        break;
    case 48:
        lst.clear();
        lst.append("Cowboy Hat");
        lst.append("12");
        return lst;
        break;
    case 50:
        lst.clear();
        lst.append("Heart Locket");
        lst.append("15");
        return lst;
        break;
    case 53:
        lst.clear();
        lst.append("The Locket");
        lst.append("99");
        return lst;
        break;
    case 64:
        lst.clear();
        lst.append("Temy Armor");
        lst.append("20");
        return lst;
        break;
    default:
        break;
    }
}
QList<QVariant> USaveFile::getStats(int lvlChar)
{
    QList<QVariant> lst;

    int curEXP = charValue(10).toInt();

    switch (lvlChar) {
    case 1:
        lst.clear();
        lst.append("0");
        lst.append("0");
        lst.append(QString::number(10 - curEXP));
        return lst;
        break;
    case 2:
        lst.clear();
        lst.append("2");
        lst.append("0");
        lst.append(QString::number(30 - curEXP));
        return lst;
        break;
    case 3:
        lst.clear();
        lst.append("4");
        lst.append("0");
        lst.append(QString::number(70 - curEXP));
        return lst;
        break;
    case 4:
        lst.clear();
        lst.append("6");
        lst.append("0");
        lst.append(QString::number(120 - curEXP));
        return lst;
        break;
    case 5:
        lst.clear();
        lst.append("8");
        lst.append("1");
        lst.append(QString::number(200 - curEXP));
        return lst;
        break;
    case 6:
        lst.clear();
        lst.append("10");
        lst.append("1");
        lst.append(QString::number(300 - curEXP));
        return lst;
        break;
    case 7:
        lst.clear();
        lst.append("12");
        lst.append("1");
        lst.append(QString::number(500 - curEXP));
        return lst;
        break;
    case 8:
        lst.clear();
        lst.append("14");
        lst.append("1");
        lst.append(QString::number(800 - curEXP));
        return lst;
        break;
    case 9:
        lst.clear();
        lst.append("16");
        lst.append("2");
        lst.append(QString::number(1200 - curEXP));
        return lst;
        break;
    case 10:
        lst.clear();
        lst.append("18");
        lst.append("2");
        lst.append(QString::number(1700 - curEXP));
        return lst;
        break;
    case 11:
        lst.clear();
        lst.append("20");
        lst.append("2");
        lst.append(QString::number(2500 - curEXP));
        return lst;
        break;
    case 12:
        lst.clear();
        lst.append("22");
        lst.append("2");
        lst.append(QString::number(3500 - curEXP));
        return lst;
        break;
    case 13:
        lst.clear();
        lst.append("24");
        lst.append("3");
        lst.append(QString::number(5000 - curEXP));
        return lst;
        break;
    case 14:
        lst.clear();
        lst.append("26");
        lst.append("3");
        lst.append(QString::number(7000 - curEXP));
        return lst;
        break;
    case 15:
        lst.clear();
        lst.append("28");
        lst.append("3");
        lst.append(QString::number(10000 - curEXP));
        return lst;
        break;
    case 16:
        lst.clear();
        lst.append("30");
        lst.append("3");
        lst.append(QString::number(15000 - curEXP));
        return lst;
        break;
    case 17:
        lst.clear();
        lst.append("32");
        lst.append("4");
        lst.append(QString::number(25000 - curEXP));
        return lst;
        break;
    case 18:
        lst.clear();
        lst.append("34");
        lst.append("4");
        lst.append(QString::number(50000 - curEXP));
        return lst;
        break;
    case 19:
        lst.clear();
        lst.append("36");
        lst.append("4");
        lst.append(QString::number(99999 - curEXP));
        return lst;
        break;
    case 20:
        lst.clear();
        lst.append("38");
        lst.append("4");
        lst.append(QString::number(0));
        return lst;
        break;
    default:
        break;
    }
}
