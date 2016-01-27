#include "TPushButton.hpp"

TPushButton::TPushButton(QWidget * parent) : QPushButton(parent)
{
    m_parentWidget = parent;
}
TPushButton::TPushButton(const QString & text, QWidget * parent) : QPushButton(text, parent)
{
    m_parentWidget = parent;
}

void TPushButton::mousePressEvent(QMouseEvent *event)
{
    m_positionPoint = event->globalPos() - m_parentWidget->pos();
}
void TPushButton::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint movePoint = event->globalPos() - m_positionPoint - pos();
    m_parentWidget->move(x() + movePoint.x(), y() + movePoint.y());
    m_positionPoint = event->globalPos() - m_parentWidget->pos();
}
