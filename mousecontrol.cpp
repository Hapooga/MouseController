#include "mousecontrol.h"



//----------------------------------------------------
MouseControl::MouseControl(QWidget* parent) :
    QLabel(parent), x(0), y(0)
{
}
//----------------------------------------------------
void MouseControl::mouseMoveEvent(QMouseEvent* event){
    this->x = event->position().x();
    this->y = event->position().y();
    emit ChengePose();
}
//----------------------------------------------------
ushort MouseControl::GetX() const { return x; }
//----------------------------------------------------
ushort MouseControl::GetY() const { return y; }
//----------------------------------------------------
