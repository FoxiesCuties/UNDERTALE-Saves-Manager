#include "StatsTab.hpp"

StatsTab::StatsTab()
{
    createObjects();
    createInterface();
}

void StatsTab::createObjects()
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

    mNameHBox           = new QHBoxLayout;
    mLoveHBox           = new QHBoxLayout;
    mHPHBox             = new QHBoxLayout;
    mAtExpHBox          = new QHBoxLayout;
    mDfNxtHBox          = new QHBoxLayout;
    mWeapHBox           = new QHBoxLayout;
    mArmorHBox          = new QHBoxLayout;
    mGoldHBox           = new QHBoxLayout;
    mDetailsVbox        = new QVBoxLayout;

}
void StatsTab::createInterface()
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

    mGameKillLab->setText("  KILLS:");

    this->setLayout(mDetailsVbox);
}

void StatsTab::setCharName(QString val)
{
    mGameNameVal->setText(val);
}
void StatsTab::setCharLV(QString val)
{
    mGameLoveVal->setText(val);
}
void StatsTab::setCharHP(QString val)
{
    QString charHP = val.section(" ",0,0);//WIP tiny hack for remove space.

    mGameHealthVal->setText(charHP+"/"+charHP);
}
void StatsTab::setCharBaseAtk(QString val)
{
    mGameAtkVal->setText(val);
}
void StatsTab::setCharWeaponAtk(QString val)
{
    mGameBnxAtkVal->setText("("+val+")");
}
void StatsTab::setCharEXP(QString val)
{
    mGameExpVal->setText(val);
}
void StatsTab::setCharBaseDef(QString val)
{
    mGameDefVal->setText(val);
}
void StatsTab::setCharArmorDef(QString val)
{
    mGameBnxDefVal->setText("("+val+")");
}
void StatsTab::setCharNextLV(QString val)
{
    mGameNExpVal->setText(val);
}
void StatsTab::setCharWeapon(QString val)
{
    mGameWeapVal->setText(val);
}
void StatsTab::setCharArmor(QString val)
{
    mGameArmrVal->setText(val);
}
void StatsTab::setCharGold(QString val)
{
    mGameGoldVal->setText(val);
}
void StatsTab::setCharKills(QString val)
{
    if(val.toInt() > 0){
        mGameKillLab->show();
        mGameKillVal->setText(val);
    } else {
        mGameKillLab->hide();
    }
}
