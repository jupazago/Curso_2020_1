#ifndef CUERPO_H
#define CUERPO_H
#include <QGraphicsItem> //para que sea un elemento graficable
#include <QPainter>


class Cuerpo: public QGraphicsItem
{
    int r;
    int posx;
    int posy;
    int vel=3;
public:
    Cuerpo();
    Cuerpo(int r_, int x_, int y_);
    int getR() const;
    void setR(int value);
    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    void rotarLeft();
    void rotarUp();
    void rotarDown();
    void rotarRight();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // CUERPO_H
