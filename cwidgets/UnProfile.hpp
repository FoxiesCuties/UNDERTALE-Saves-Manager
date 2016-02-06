#ifndef UNPROFILE_HPP
#define UNPROFILE_HPP

#include <QtWidgets>

#include "cwidgets/SaveDetails.hpp"
#include "cwidgets/USaveFile.hpp"

class UnProfile : public QPushButton
{
    Q_OBJECT

public:

    UnProfile();

    void createObjects();
    void createConnexions();
    void createInterface();
    void createObjectName();
    void createSettings();

    //Setters
    void setIdentifier(int id);
    void setName(QVariant name);
    void setLove(QVariant love);
    void setTime(QVariant frms);
    void setRoom(QVariant room);
    void setFile0(QVariant file);

    //Getters
    int identifier();
    QVariant name();
    QVariant love();
    QVariant time();
    QVariant room();
    QString file0();

    //Events
    void mouseDoubleClickEvent(QMouseEvent *event);


private slots:

    void deleteSave();

signals:

    void deleteSaveID(int);

private:

    QVariant        mFile0Variant;

    //Variables
    int             mSaveIdInt;
    int             mRoomNumber;
    QVariant        mNameVariant;
    QVariant        mLoveVariant;
    QVariant        mTimeVariant;
    QVariant        mRoomVariant;

    //Objects
    USaveFile       *mSaveFile0;
    QLabel          *mNameValue;
    QLabel          *mLoveValue;
    QLabel          *mTimeValue;
    QLabel          *mRoomValue;
    QPushButton     *mDeleteBut;
    QGridLayout     *mProfileGrid;
    SaveDetails     *mSaveDetails;
};

#endif // UNPROFILE_HPP
