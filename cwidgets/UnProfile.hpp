#ifndef UNPROFILE_HPP
#define UNPROFILE_HPP

#include <QtWidgets>

class UnProfile : public QPushButton
{
    Q_OBJECT

public:

    UnProfile();

    void createObjects();
    void createConnexions();
    void createInterface();
    void createSettings();

    //Setters
    void setIdentifier(int id);
    void setName(QVariant name);
    void setLove(QVariant love);
    void setTime(QVariant frms);
    void setRoom(QVariant room);

    //Getters
    int identifier();
    QVariant name();
    QVariant love();
    QVariant time();
    QVariant room();

private slots:

    void deleteSave();

signals:

    void deleteSaveID(int);

private:

    //Variables
    int             mSaveIdInt;
    QVariant        mNameVariant;
    QVariant        mLoveVariant;
    QVariant        mTimeVariant;
    QVariant        mRoomVariant;

    //Objects
    QLabel          *mNameValue;
    QLabel          *mLoveValue;
    QLabel          *mTimeValue;
    QLabel          *mRoomValue;
    QPushButton     *mDeleteBut;
    QGridLayout     *mProfileGrid;
};

#endif // UNPROFILE_HPP
