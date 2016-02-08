#ifndef SAVEDETAILS_HPP
#define SAVEDETAILS_HPP

#include <QtWidgets>

class SaveDetails : public QDialog
{
    Q_OBJECT

public:

    SaveDetails(QWidget * parent = 0);

    void createObjects();
    void createConnexions();
    void createInterface();
    void createObjectNames();
    void createSettings();

    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

public slots:

    void setRoomNumber(int room);
//--
    void setGameNameVal(QString val);
    void setGameLoveVal(QString val);
    void setGameHealthVal(QString val);
    void setGameAtkVal(QString val);
    void setGameBnxAtkVal(QString val);
    void setGameExpVal(QString val);
    void setGameDefVal(QString val);
    void setGameBnxDefVal(QString val);
    void setGameNExpVal(QString val);
    void setGameWeapVal(QString val);
    void setGameArmrVal(QString val);
    void setGameGoldVal(QString val);
    void setGameKillVal(QString val);

private:

    int             mRoomInt;
    QPoint          mGamePoint;
    QPixmap         mRoomPixmap;

    QLabel          *mGameNameVal;
    QLabel          *mGameLoveVal;
    QLabel          *mGameHealthVal;
    QLabel          *mGameAtkVal;
    QLabel          *mGameBnxAtkVal;
    QLabel          *mGameExpVal;
    QLabel          *mGameDefVal;
    QLabel          *mGameBnxDefVal;
    QLabel          *mGameNExpVal;
    QLabel          *mGameWeapVal;
    QLabel          *mGameArmrVal;
    QLabel          *mGameGoldVal;
    QLabel          *mGameKillLab;
    QLabel          *mGameKillVal;
    QLabel          *mRoomPixLab;
    QHBoxLayout     *mNameHBox;
    QHBoxLayout     *mLoveHBox;
    QHBoxLayout     *mHPHBox;
    QHBoxLayout     *mAtExpHBox;
    QHBoxLayout     *mDfNxtHBox;
    QHBoxLayout     *mWeapHBox;
    QHBoxLayout     *mArmorHBox;
    QHBoxLayout     *mGoldHBox;
    QVBoxLayout     *mDetailsVbox;
    QHBoxLayout     *mDetailsHbox;
    QPushButton     *mDetCloseBut;
    QWidget         *mStatsTab;
    QWidget         *mBagTab;
    QHBoxLayout     *mTabWidgetHBox;
    QTabWidget      *mDetailsTabWidget;
};

#endif // SAVEDETAILS_HPP
