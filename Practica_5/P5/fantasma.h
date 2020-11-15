#ifndef FANTASMA_H
#define FANTASMA_H
#include <QGraphicsItem> //para que sea un elemento graficable
#include <QPainter>

class Fantasma: public QGraphicsItem
{
    int r;
    int posx;
    int posy;
    int vel=4;
public:
    Fantasma();
    Fantasma(int r_, int x_, int y_);
    int getR() const;
    void setR(int value);
    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);
    int getVel() const;
    void setVel(int value);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // FANTASMA_H
