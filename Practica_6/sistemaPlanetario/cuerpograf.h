#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <cuerpo.h>

class Cuerpograf: public QGraphicsItem
{
public:
    Cuerpograf(float x, float y, float vx, float vy, float m, float r);
    QRectF boundingRect() const; //usando polimorfismo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setEscala(float s);
    void actualizar(float dt);
    Cuerpo* getEsf();

private:
    Cuerpo *esf;
    float escala;
};

#endif // CUERPOGRAF_H
