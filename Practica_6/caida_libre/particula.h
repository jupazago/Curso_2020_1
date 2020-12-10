#ifndef PARTICULA_H
#define PARTICULA_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class Particula: public QGraphicsItem
{
    double posx;
    double posy;
    double vel;
    double ang;
    double velx;
    double vely;
    const double delta = 0.01;
    const double g = 9.8;
    int r = 25;

public:
    Particula();
    Particula(double x, double y, double v, double a);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


    double getPosx() const;
    void setPosx(double value);
    double getPosy() const;
    void setPosy(double value);

    void ActualizarPosicion();
    void CalcularVelocidad();
};

#endif // PARTICULA_H
