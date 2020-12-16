#include "cuerpograf.h"

Cuerpograf::Cuerpograf(float x, float y, float vx, float vy, float m, float r): escala(0.04)
{
    esf = new Cuerpo(x, y, vx, vy, m, r);

}

QRectF Cuerpograf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(), -1*escala*esf->getR(), 2*escala*esf->getR(), 2*escala*esf->getR());
}

void Cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

void Cuerpograf::setEscala(float s)
{
    escala = s;
}

void Cuerpograf::actualizar(float dt)
{
    //llamo y cambio el proceso fisico, y ubico el dibujo en esa posicion
    esf->actualizar(dt);
    setPos(esf->getPX()*escala, esf->getPY()*escala);
}

Cuerpo *Cuerpograf::getEsf()
{
    return esf;
}
