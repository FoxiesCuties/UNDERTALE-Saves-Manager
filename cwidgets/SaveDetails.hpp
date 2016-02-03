#ifndef SAVEDETAILS_HPP
#define SAVEDETAILS_HPP

#include <QtWidgets>

class SaveDetails : public QDialog
{
    Q_OBJECT

public:

    SaveDetails();

    void createObjects();
    void createInterface();

public slots:

    void setRoomNumber(int room);

private:

    QString         mAstPath;
    QPixmap         mRoomPixmap;
    QLabel          *mRoomPixLab;
    QHBoxLayout     *mDetailsHbox;
    QLabel          *mGameTypeLab;
    QLabel          *mGameTypeVal;
    QLabel          *mGameGoldLab;
    QLabel          *mGameGoldVal;
    QGridLayout     *mDetailsGrid;
};

#endif // SAVEDETAILS_HPP
