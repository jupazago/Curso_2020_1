#include "comida.h"

int Comida::getR() const
{
    return r;
}

void Comida::setR(int value)
{
    r = value;
}

int Comida::getPosx() const
{
    return posx;
}

void Comida::setPosx(int value)
{
    posx = value;
}

int Comida::getPosy() const
{
    return posy;
}

void Comida::setPosy(int value)
{
    posy = value;
}

QRectF Comida::boundingRect() const
{
    return QRect(-r,-r,2*r,2*r);
}

void Comida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //como pintar la esfera
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
}

Comida::Comida()
{

}

Comida::Comida(int r_, int x_, int y_)
{
    r=r_;
    posx=x_;
    posy=y_;
    setPos(posx,posy);
}
