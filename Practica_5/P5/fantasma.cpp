#include "fantasma.h"

int Fantasma::getR() const
{
    return r;
}

void Fantasma::setR(int value)
{
    r = value;
}

int Fantasma::getPosx() const
{
    return posx;
}

void Fantasma::setPosx(int value)
{
    posx = value;
}

int Fantasma::getPosy() const
{
    return posy;
}

void Fantasma::setPosy(int value)
{
    posy = value;
}

int Fantasma::getVel() const
{
    return vel;
}

void Fantasma::setVel(int value)
{
    vel = value;
}

void Fantasma::MoveUp()
{
    posy-=2*vel;
    setPos(posx,posy);
}

void Fantasma::MoveDown()
{
    posy+=2*vel;
    setPos(posx,posy);
}

void Fantasma::MoveLeft()
{
    posx-=2*vel;
    setPos(posx,posy);
}

void Fantasma::MoveRight()
{
    posx+=2*vel;
    setPos(posx,posy);
}

QRectF Fantasma::boundingRect() const
{
    return QRect(-r,-r,2*r,2*r);
}

void Fantasma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::yellow);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/imagenes/fantasma.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

Fantasma::Fantasma(int r_, int x_, int y_)
{
    r=r_;
    posx=x_;
    posy=y_;
    setPos(posx,posy);
}
