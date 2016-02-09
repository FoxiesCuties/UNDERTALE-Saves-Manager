#ifndef STATSTAB_HPP
#define STATSTAB_HPP

#include <QtWidgets>

class StatsTab : public QWidget
{
    Q_OBJECT

public:

    StatsTab();

    //Regions
    void createObjects();
    void createInterface();

    //Methods
    void setCharName(QString val);
    void setCharLV(QString val);
    void setCharHP(QString val);
    void setCharBaseAtk(QString val);
    void setCharWeaponAtk(QString val);
    void setCharEXP(QString val);
    void setCharBaseDef(QString val);
    void setCharArmorDef(QString val);
    void setCharNextLV(QString val);
    void setCharWeapon(QString val);
    void setCharArmor(QString val);
    void setCharGold(QString val);
    void setCharKills(QString val);

private:

    QLabel              *mGameNameVal;
    QLabel              *mGameLoveVal;
    QLabel              *mGameHealthVal;
    QLabel              *mGameAtkVal;
    QLabel              *mGameBnxAtkVal;
    QLabel              *mGameExpVal;
    QLabel              *mGameDefVal;
    QLabel              *mGameBnxDefVal;
    QLabel              *mGameNExpVal;
    QLabel              *mGameWeapVal;
    QLabel              *mGameArmrVal;
    QLabel              *mGameGoldVal;
    QLabel              *mGameKillLab;
    QLabel              *mGameKillVal;
    QHBoxLayout         *mNameHBox;
    QHBoxLayout         *mLoveHBox;
    QHBoxLayout         *mHPHBox;
    QHBoxLayout         *mAtExpHBox;
    QHBoxLayout         *mDfNxtHBox;
    QHBoxLayout         *mWeapHBox;
    QHBoxLayout         *mArmorHBox;
    QHBoxLayout         *mGoldHBox;
    QVBoxLayout         *mDetailsVbox;
};

#endif // STATSTAB_HPP
