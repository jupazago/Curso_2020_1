#include "cuerpo.h"

int Cuerpo::getR() const
{
    return r;
}

void Cuerpo::setR(int value)
{
    r = value;
}

int Cuerpo::getPosx() const
{
    return posx;
}

void Cuerpo::setPosx(int value)
{
    posx = value;
}

int Cuerpo::getPosy() const
{
    return posy;
}

void Cuerpo::setPosy(int value)
{
    posy = value;
}

void Cuerpo::MoveUp()
{
    posy-=2*vel;
    setPos(posx,posy);

}

void Cuerpo::MoveDown()
{
    posy+=2*vel;
    setPos(posx,posy);
}

void Cuerpo::MoveLeft()
{
    posx-=2*vel;
    setPos(posx,posy);
}

void Cuerpo::MoveRight()
{
    posx+=2*vel;
    setPos(posx,posy);
}

void Cuerpo::rotarLeft()
{
    posx-=posx;
}

void Cuerpo::rotarUp()
{

}

void Cuerpo::rotarDown()
{

}

void Cuerpo::rotarRight()
{

}

QRectF Cuerpo::boundingRect() const
{
    return QRect(-r,-r,2*r,2*r);
}

void Cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //como pintar la esfera
    //painter->setBrush(Qt::yellow);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/imagenes/pac2.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}

Cuerpo::Cuerpo()
{

}

Cuerpo::Cuerpo(int r_, int x_, int y_)
{
    r=r_;
    posx=x_;
    posy=y_;
    setPos(posx,posy);
}
