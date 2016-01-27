#ifndef TPUSHBUTTON_HPP
#define TPUSHBUTTON_HPP

#include <QMouseEvent>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QPoint>

class TPushButton : public QPushButton
{
    Q_OBJECT

public:

    TPushButton(QWidget * parent = 0);
    TPushButton(const QString & text, QWidget * parent = 0);

    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);

private:

    QWidget *m_parentWidget;
    QPoint  m_positionPoint;
};

#endif // TPUSHBUTTON_HPP
