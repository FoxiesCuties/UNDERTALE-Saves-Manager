#ifndef UNPROFILE_HPP
#define UNPROFILE_HPP

#include <QtWidgets>

class UnProfile : public QPushButton
{
    Q_OBJECT

public:

    UnProfile();

    void createObjects();
    void createInterface();
    void createSettings();

    //Setters
    void setName(QVariant name);
    void setLove(QVariant love);
    void setTime(QVariant frms);
    void setRoom(QVariant room);

    //Getters
    QVariant name();
    QVariant love();
    QVariant time();
    QVariant room();

private:

    //Variables
    QVariant    mNameVariant;
    QVariant    mLoveVariant;
    QVariant    mTimeVariant;
    QVariant    mRoomVariant;

    //Objects
    QLabel      *mNameValue;
    QLabel      *mLoveValue;
    QLabel      *mTimeValue;
    QLabel      *mRoomValue;
    QGridLayout *mProfileGrid;
};

#endif // UNPROFILE_HPP
