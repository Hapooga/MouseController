#ifndef MOUSECONTROL_H
#define MOUSECONTROL_H

#include <QLabel>
#include <QMouseEvent>

class MouseControl : public QLabel
{
     Q_OBJECT
public:
    MouseControl(QWidget* parent = 0);

    void mouseMoveEvent(QMouseEvent* event);

    ushort GetX() const ;
    ushort GetY() const ;

signals:

    void ChengePose();

private:

    ushort x;
    ushort y;
};

#endif // MOUSECONTROL_H
