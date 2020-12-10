#include "particula.h"

double Particula::getPosx() const
{
    return posx;
}

void Particula::setPosx(double value)
{
    posx = value;
}

double Particula::getPosy() const
{
    return posy;
}

void Particula::setPosy(double value)
{
    posy = value;
}

void Particula::ActualizarPosicion()
{
    CalcularVelocidad();
    posx = posx + velx*delta;
    posy = posy + vely*delta - (0.5*g*delta*delta);
    setPos(posx, posy);
}

void Particula::CalcularVelocidad()
{
    velx = vel*cos(ang);
    vely = vel*sin(ang)-g*delta;

    ang = atan2(velx,vely);
    vel = sqrt(velx*velx + vely*vely);
}

Particula::Particula()
{

}

Particula::Particula(double x, double y, double v, double a)
{
    posx = x;
    posy = y;
    vel = v;
    ang = a;
    setPos(posx, -posy);
}

QRectF Particula::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagen/ball.png)");
    painter->drawPixmap(-r,-r,2*r,2*r, pixmap);
}
