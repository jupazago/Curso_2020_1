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
    posx=posx+velx*delta;
    posy=posy+vely*delta-(0.5*g*delta*delta);
    setPos(posx,-posy);
}

void Particula::CalcularVelocidad()
{
    ang=atan2(vely,velx);
    vel=sqrt(velx*velx+vely*vely);
}

Particula::Particula()
{

}

Particula::Particula(double x, double y, double vx, double vy, double m)
{
    posx    = x;
    posy    = y;
    velx    = vx;
    vely    = vy;
    masa    = m;
    setPos(posx,-posy);
}

QRectF Particula::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagen/bola.png");
    painter->drawPixmap(-r,-r,2*r,2*r,pixmap);
   // painter->setBrush(Qt::cyan);
    //painter->drawEllipse(boundingRect());
}
