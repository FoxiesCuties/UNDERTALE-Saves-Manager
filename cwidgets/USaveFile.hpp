#ifndef USAVEFILE_HPP
#define USAVEFILE_HPP

#include <QtWidgets>

class USaveFile : public QFile
{

public:

    USaveFile();

    void setSaveFile(QString file0);

    QVariant charValue(int line);

    QString charName();
    QString charLV();
    QString charHP();
    QString charBaseAtk();
    QString charWeaponAtk();
    QString charEXP();
    QString charBaseDef();
    QString charArmorDef();
    QString charNextLV();
    QString charWeapon();
    QString charArmor();
    QString charGold();
    QString charKills();

    QList<QVariant> getWeapon(int idWeapon);
    QList<QVariant> getArmor(int idArmor);
    QList<QVariant> getStats(int lvlChar);

private:

    QString mFilename;
};

#endif // USAVEFILE_HPP
