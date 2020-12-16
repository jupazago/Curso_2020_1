#ifndef CUERPO_H
#define CUERPO_H


class Cuerpo
{
private:
    float PX;
    float PY;
    float VX;
    float VY;
    float radio;//Distancia entre 2 planetas
    float masa;
    float AX;
    float AY;
    float G;
    float R;    //Radio del planeta

public:
    Cuerpo(float PX_, float PY_, float VX_, float VY_, float mass, float R_);

    float getPX() const;
    float getPY() const;
    float getMasa() const;
    float getR() const;

    void acelerar(float px2, float py2, float mass2);
    void actualizar(float dt);
};

#endif // CUERPO_H









