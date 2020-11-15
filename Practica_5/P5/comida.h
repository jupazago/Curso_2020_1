#ifndef COMIDA_H
#define COMIDA_H
#include <QGraphicsItem> //para que sea un elemento graficable
#include <QPainter>

class Comida:public QGraphicsItem
{
    int r;
    int posx;
    int posy;
public:
    Comida();
    Comida(int r_, int x_, int y_);
    int getR() const;
    void setR(int value);
    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // COMIDA_H
