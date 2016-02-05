#ifndef SAVEDETAILS_HPP
#define SAVEDETAILS_HPP

#include <QtWidgets>

class SaveDetails : public QDialog
{
    Q_OBJECT

public:

    SaveDetails();

    void createObjects();
    void createConnexions();
    void createInterface();
    void createSettings();

    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

public slots:

    void setRoomNumber(int room);
    void setPoint(QPoint point);
//--
    void setGameNameVal(QString val);
    void setGameLoveVal(QString val);
    void setGameHealthVal(QString val);
    void setGameAtkVal(QString val);
    void setGameExpVal(QString val);
    void setGameDefVal(QString val);
    void setGameNExpVal(QString val);
    void setGameWeapVal(QString val);
    void setGameArmrVal(QString val);
    void setGameGoldVal(QString val);

private:

    int             mRoomInt;
    QPoint          mGamePoint;
    QPixmap         mRoomPixmap;

    QLabel          *mGameNameVal;
    QLabel          *mGameLoveVal;
    QLabel          *mGameHealthVal;
    QLabel          *mGameAtkVal;
    QLabel          *mGameExpVal;
    QLabel          *mGameDefVal;
    QLabel          *mGameNExpVal;
    QLabel          *mGameWeapVal;
    QLabel          *mGameArmrVal;
    QLabel          *mGameGoldVal;
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
};

#endif // SAVEDETAILS_HPP
