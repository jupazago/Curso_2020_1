#include "relacion.h"

string Relacion::getConexion() const
{
    return Conexion;
}

void Relacion::setConexion(const string &value)
{
    Conexion = value;
}

int Relacion::getCosto() const
{
    return Costo;
}

void Relacion::setCosto(int value)
{
    Costo = value;
}

Relacion::Relacion()
{
    Conexion= "Desconocido";
    Costo = 0;
}

Relacion::Relacion(string conexion, int costo)
{
    Conexion = conexion;
    Costo = costo;
}
