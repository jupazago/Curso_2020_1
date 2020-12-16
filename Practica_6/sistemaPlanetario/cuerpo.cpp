#include "cuerpo.h"
#include <math.h>
#include <cmath>

Cuerpo::Cuerpo(float PX_, float PY_, float VX_, float VY_, float mass, float R_)
{
    PX = PX_;
    PY = PY_;
    VX = VX_;
    VY = VY_;
    masa = mass;
    AX = 0;
    AY = 0;
    G = 6.67384 * (pow(10, -11));
    R = R_;
}

float Cuerpo::getPY() const
{
    return PY;
}

float Cuerpo::getMasa() const
{
    return masa;
}

float Cuerpo::getR() const
{
    return R;
}

float Cuerpo::getPX() const
{
    return PX;
}

void Cuerpo::acelerar(float px2, float py2, float mass2)
{
    //radio = sqrt(  pow(px2-PX, 2) + pow(py2-PY, 2)  );
    radio = pow((pow((px2-PX), 2)+ pow((py2-PY), 2)), 1/2);
    AX = G*mass2*(px2-PX)/pow(radio, 2);
    AY = G*mass2*(py2-PY)/pow(radio, 2);
}

void Cuerpo::actualizar(float dt)
{
    VX = VX + (AX*dt);
    VY = VY + (AY*dt);
    PX = PX + (VX*dt); //Es lo mismo qu ela formula completa
    PY = PY + (VY*dt);


}


