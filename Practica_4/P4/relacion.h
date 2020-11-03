#ifndef RELACION_H
#define RELACION_H
#include <string>

/*


    struct Relacion{
        string conexion;
        int costo;
    };


*/

using namespace std;
class Relacion
{
    //Atributos
    string Conexion;
    int Costo;

public:
    Relacion(); //constructor General
    Relacion(string conexion, int costo);

    string getConexion() const;
    void setConexion(const string &value);
    int getCosto() const;
    void setCosto(int value);
};

#endif // RELACION_H
