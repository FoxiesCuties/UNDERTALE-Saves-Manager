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
QList<QVariant> USaveFile::getItem(int idItem)
{
    QList<QVariant> lst;

    switch (idItem) {
    case 1:
        lst.clear();
        lst.append("Monster Candy");
        lst.append("Heals 10 HP Has a distinct, non-licorice flavor.");
        return lst;
        break;
    case 2:
        lst.clear();
        lst.append("Croquet Roll");
        lst.append("Heals 15 HP Fried dough traditionally served with a mallet.");
        return lst;
        break;
    case 3:
        lst.clear();
        lst.append("Stick");
        lst.append("Weapon AT 0 Its bark is worse than its bite.");
        return lst;
        break;
    case 4:
        lst.clear();
        lst.append("Bandage");
        lst.append("Heals 10 HP It has already been used several times.");
        return lst;
        break;
    case 5:
        lst.clear();
        lst.append("Rock Candy");
        lst.append("Heals 1 HP Here is a recipe to make this at home: 1. Find a rock");
        return lst;
        break;
    case 6:
        lst.clear();
        lst.append("Pumpkin Rings");
        lst.append("Heals 8 HP A small pumpkin cooked like onion rings.");
        return lst;
        break;
    case 7:
        lst.clear();
        lst.append("Spider Donut");
        lst.append("Heals 12 HP A donut made with Spider Cider in the batter.");
        return lst;
        break;
    case 8:
        lst.clear();
        lst.append("Stoic Onion");
        lst.append("Heals 5 HP Even eating it raw, the tears just won't come.");
        return lst;
        break;
    case 9:
        lst.clear();
        lst.append("Ghost Fruit");
        lst.append("Heals 16 HP If eaten, it will never pass to the other side.");
        return lst;
        break;
    case 10:
        lst.clear();
        lst.append("Spider Cider");
        lst.append("Heals 24 HP Made with whole spiders, not just the juice.");
        return lst;
        break;
    case 11:
        lst.clear();
        lst.append("Butterscotch Pie");
        lst.append("All HP Butterscotch-cinnamon pie, one slice.");
        return lst;
        break;
    case 12:
        lst.clear();
        lst.append("Faded Ribbon");
        lst.append("Armor DF 3 If you're cuter, monsters won't hit you as hard.");
        return lst;
        break;
    case 13:
        lst.clear();
        lst.append("Toy Knife");
        lst.append("Weapon AT 3 Made of plastic. A rarity nowadays.");
        return lst;
        break;
    case 14:
        lst.clear();
        lst.append("Tough Glove");
        lst.append("Weapon AT 5 A worn pink leather glove. For five-fingered folk.");
        return lst;
        break;
    case 15:
        lst.clear();
        lst.append("Manly Bandanna");
        lst.append("Armor DF 7 It has seen some wear. It has abs drawn on it.");
        return lst;
        break;
    case 16:
        lst.clear();
        lst.append("Snowman Piece");
        lst.append("Heals 45 HP Please take this to the ends of the earth.");
        return lst;
        break;
    case 17:
        lst.clear();
        lst.append("Nice Cream");
        lst.append("Heals 15 HP Instead of a joke, the wrapper says something nice.");
        return lst;
        break;
    case 18:
        lst.clear();
        lst.append("Puppydough Icecream");
        lst.append("\"Puppydough Icecream\" Heals 28 HP. Made by young pups.");
        return lst;
        break;
    case 19:
        lst.clear();
        lst.append("Bisicle");
        lst.append("Heals 11 HP It's a two-pronged popsicle, so you can eat it twice.");
        return lst;
        break;
    case 20:
        lst.clear();
        lst.append("Unisicle");
        lst.append("Heals 11 HP It's a SINGLE-pronged popsicle. Wait, that's just normal...");
        return lst;
        break;
    case 21:
        lst.clear();
        lst.append("Cinnamon Bun");
        lst.append("Heals 22 HP A cinnamon roll in the shape of a bunny.");
        return lst;
        break;
    case 22:
        lst.clear();
        lst.append("Temmie Flakes");
        lst.append("Heals 2 HP It's just torn up pieces of colored construction paper.");
        return lst;
        break;
    case 23:
        lst.clear();
        lst.append("Abandoned Quiche");
        lst.append("Heals 34 HP A psychologically damaged spinach egg pie.");
        return lst;
        break;
    case 24:
        lst.clear();
        lst.append("Old Tutu");
        lst.append("Armor DF 10 Finally, a protective piece of armor.");
        return lst;
        break;
    case 25:
        lst.clear();
        lst.append("Ballet Shoes");
        lst.append("Wpn AT 7 These used shoes make you feel incredibly dangerous.");
        return lst;
        break;
    case 26:
        lst.clear();
        lst.append("Punch Card");
        lst.append("Battle Item Use to make punching attacks stronger in one battle. Use outside of battle to look at the card.");
        return lst;
        break;
    case 27:
        lst.clear();
        lst.append("Annoying Dog");
        lst.append("Dog A little white dog. It's fast asleep...");
        return lst;
        break;
    case 28:
        lst.clear();
        lst.append("Dog Salad");
        lst.append("Heals ?? HP Recovers HP. (Hit Poodles.)");
        return lst;
        break;
    case 29:
        lst.clear();
        lst.append("Dog Residue");
        lst.append("Dog Item Shiny trail left behind by a dog.");
        return lst;
        break;
    case 30:
        lst.clear();
        lst.append("Dog Residue");
        lst.append("Dog Item Dog-shaped husk shed from a dog's carapace.");
        return lst;
        break;
    case 31:
        lst.clear();
        lst.append("Dog Residue");
        lst.append("Dog Item Dirty dishes left unwashed by a dog.");
        return lst;
        break;
    case 32:
        lst.clear();
        lst.append("Dog Residue");
        lst.append("Dog Item Glowing crystals secreted by a dog.");
        return lst;
        break;
    case 33:
        lst.clear();
        lst.append("Dog Residue");
        lst.append("Dog Item Jigsaw puzzle left unfinished by a dog.");
        return lst;
        break;
    case 34:
        lst.clear();
        lst.append("Dog Residue");
        lst.append("Dog Item Web spun by a dog to ensnare prey.");
        return lst;
        break;
    case 35:
        lst.clear();
        lst.append("Astronaut Food");
        lst.append("Heals 21 HP For feeding a pet astronaut.");
        return lst;
        break;
    case 36:
        lst.clear();
        lst.append("Instant Noodles");
        lst.append("Heals HP Comes with everything you need for a quick meal!");
        return lst;
        break;
    case 37:
        lst.clear();
        lst.append("Crab Apple");
        lst.append("Heals 18 HP An aquatic fruit that resembles a crustacean.");
        return lst;
        break;
    case 38:
        lst.clear();
        lst.append("Hot Dog...?");
        lst.append("Heals 20 HP The \"meat\" is made of something called a \"water sausage.\"");
        return lst;
        break;
    case 39:
        lst.clear();
        lst.append("Hot Cat");
        lst.append("Heals 21 HP Like a hot dog, but with little cat ears on the end.");
        return lst;
        break;
    case 40:
        lst.clear();
        lst.append("Glamburger");
        lst.append("Heals 27 HP A hamburger made of edible glitter and sequins.");
        return lst;
        break;
    case 41:
        lst.clear();
        lst.append("Sea Tea");
        lst.append("Heals 10 HP Made from glowing marshwater. Increases SPEED for one battle.");
        return lst;
        break;
    case 42:
        lst.clear();
        lst.append("Starfait");
        lst.append("Heals 14 HP A sweet treat made of sparkling stars.");
        return lst;
        break;
    case 43:
        lst.clear();
        lst.append("Legendary Hero");
        lst.append("Heals 40 HP Sandwich shaped like a sword. Increases ATTACK when eaten.");
        return lst;
        break;
    case 44:
        lst.clear();
        lst.append("Butty Glasses");
        lst.append("Armor DF 6 Glasses marred with wear. Increases INV by 9. (After you get hurt by an attack, you stay invulnerable for longer.)");
        return lst;
        break;
    case 45:
        lst.clear();
        lst.append("Torn Notebook");
        lst.append("Weapon AT 2 Contains illegible scrawls. Increases INV by 6. (After you get hurt by an attack, you stay invulnerable for longer.)");
        return lst;
        break;
    case 46:
        lst.clear();
        lst.append("Stained Apron");
        lst.append("Armor DF 11 Heals 1 HP every other turn.");
        return lst;
        break;
    case 47:
        lst.clear();
        lst.append("Burnt Pan");
        lst.append("Weapon AT 10 Damage is rather consistent. Consumable items heal 4 more HP.");
        return lst;
        break;
    case 48:
        lst.clear();
        lst.append("Cowboy Hat");
        lst.append("Armor DF 12 This battle-worn hat makes you want to grow a beard. It also raises ATTACK by 5.");
        return lst;
        break;
    case 49:
        lst.clear();
        lst.append("Empty Gun");
        lst.append("Weapon AT 12 An antique revolver. It has no ammo. Must be used precisely, or damage will be low.");
        return lst;
        break;
    case 50:
        lst.clear();
        lst.append("Heart Locket");
        lst.append("Armor DF 15 It says \"Best Friends Forever.\"");
        return lst;
        break;
    case 51:
        lst.clear();
        lst.append("Worn Dagger");
        lst.append("Weapon AT 15 Perfect for cutting plants and vines.");
        return lst;
        break;
    case 52:
        lst.clear();
        lst.append("Real Knife");
        lst.append("Weapon AT 99 Here we are!");
        return lst;
        break;
    case 53:
        lst.clear();
        lst.append("The Locket");
        lst.append("Armor DF 99 You can feel it beating.");
        return lst;
        break;
    case 54:
        lst.clear();
        lst.append("Bad Memory");
        lst.append("Hurts 1 HP ?????");
        return lst;
        break;
    case 55:
        lst.clear();
        lst.append("Dream");
        lst.append("Heals 12 HP The goal of \"Determination.\"");
        return lst;
        break;
    case 56:
        lst.clear();
        lst.append("Undyne's Letter");
        lst.append("Unique Letter written for Dr. Alphys.");
        return lst;
        break;
    case 57:
        lst.clear();
        lst.append("Undyne Letter EX");
        lst.append("Unique It has DON'T DROP IT written on it.");
        return lst;
        break;
    case 58:
        lst.clear();
        lst.append("Popato Chisps");
        lst.append("Heals 13 HP Regular old popato chisps.");
        return lst;
        break;
    case 59:
        lst.clear();
        lst.append("Junk Food");
        lst.append("Heals 17 HP Food that was probably once thrown away.");
        return lst;
        break;
    case 60:
        lst.clear();
        lst.append("Mystery Key");
        lst.append("Unique It is too bent to fit on your keychain.");
        return lst;
        break;
    case 61:
        lst.clear();
        lst.append("Face Steak");
        lst.append("Heals 60 HP Huge steak in the shape of Mettaton's face. (You don't feel like it's made of real meat...)");
        return lst;
        break;
    case 62:
        lst.clear();
        lst.append("Hush Puppy");
        lst.append("Heals 65 HP This wonderful spell will stop a dog from casting magic.");
        return lst;
        break;
    case 63:
        lst.clear();
        lst.append("Snail Pie");
        lst.append("Heals Some HP An acquired taste.");
        return lst;
        break;
    case 64:
        lst.clear();
        lst.append("temy armor");
        lst.append("Armor DF 20 The things you can do with a college education! Raises ATTACK when worn. Recovers HP every other turn. INV up slightly.");
        return lst;
        break;
    default:
        lst.clear();
        lst.append("Unknow");
        lst.append("Unknow");
        return lst;
        break;
    }
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
    case 25:
        lst.clear();
        lst.append("Ballet Shoes");
        lst.append("7");
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
        lst.clear();
        lst.append("");
        lst.append("0");
        return lst;
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
