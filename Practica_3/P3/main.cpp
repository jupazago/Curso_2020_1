#include <string>
#include <fstream> //eof
#include <bitset>
#include <iostream>

using namespace std;

void ejercicios();
void aplicacion();

void fun_metodo_1(int semilla);
string fun_a_codificar(string cadena_binaria, int semilla);
void fun_metodo_2();

int main()
{
    int opcion;
    cout << "--------------------------" << endl;
    cout << "------- Practica 3 -------" << endl;
    cout << "--------------------------" << endl;


    while (true) {
        cout << "1- Ejercicios" << endl;
        cout << "2- Aplicacion" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {

            case 1: puts("Ejercicios \n");
                ejercicios();
                break;

            case 2: puts("Aplicación \n");
                //aplicacion();
                break;

            default: puts("Error, selecciona una opcion valida \n");
        }
    }
    return 0;
}

void ejercicios(){
    int semilla, metodo;
    cout << "Seleccione la semilla: ";
    cin >> semilla;
    cout << "Metodo de codificacion: ";
    cin >> metodo;
    try {
        if(metodo == 1){
            fun_metodo_1(semilla);

        }else if(metodo== 2){
            //fun_metodo_2();

        }else{
            throw 505;

        }
    } catch (...) {
        cout << "Error - seleccione un metodo valido."<<endl;
    }
}

void fun_metodo_1(int semilla){
    try {
        ifstream fileRead_texto;  //Puedo crear el flujo lectura desde un archivo

        fileRead_texto.open("../archivo_texto.txt", ios::in); //abro archivo para su lectura
        if(!fileRead_texto.is_open()){
            throw '2';
        }

        string cadena_texto;

        while(!fileRead_texto.eof()){ //mientras no sea el final del archivo
            getline(fileRead_texto, cadena_texto);
        }

        string cadena_binaria;
        system("cls");
        for (size_t i = 0; i < cadena_texto.size(); ++i){
            cadena_binaria.append((bitset<8>(cadena_texto.c_str()[i])).to_string());
            //cout << bitset<8>(cadena_texto[i])<<" ";
        }
        //cout <<endl<< cadena_binaria<<endl;
        cout << endl;
        int tamanio = cadena_binaria.size();
        string cadena_codificada = fun_a_codificar(cadena_binaria, semilla);
        cout << "----------"<<endl;
        for(int i=0; i<tamanio; i++){
            cout << cadena_codificada[i];
        }
        cout << "----------"<<endl;
        cout << endl;





    } catch (...) {
        cout <<"ERROR"<<endl;
    }
}

string fun_a_codificar(string cadena_binaria, int semilla){
    int tamanio = cadena_binaria.size();
    string cadena_codificada;

    int cambio=1;
    //Primer bloque
    for(int i=0; i<semilla;i++){
        if(cadena_binaria[i]=='0'){
            cadena_codificada[i]='1';
        }else if(cadena_binaria[i]=='1'){
            cadena_codificada[i]='0';
        }
    }

    //Siguientes Bloques


    int aux_evaluar = 0;
    int cant_unos = 0;
    int cant_ceros = 0;
    for(int i=semilla; i<tamanio; i++){

        if(cadena_binaria[i-semilla]=='0'){
            cant_ceros++;
            aux_evaluar++;
        }else if(cadena_binaria[i-semilla]=='1'){
            cant_unos++;
            aux_evaluar++;
        }

        if(aux_evaluar==semilla){
            aux_evaluar = 0;
            if(cant_unos>cant_ceros){
                cambio=0;
                if(cambio <=semilla){
                    for(cambio=3;cambio<=semilla;cambio=cambio+3){
                        if(cadena_binaria[i-semilla+cambio]=='0'){
                            cadena_codificada[i-semilla+cambio]='1';
                        }else if(cadena_binaria[i-semilla+cambio]=='1'){
                            cadena_codificada[i-semilla+cambio]='0';
                        }
                    }

                    for(int cambio=1;cambio<=semilla;cambio=cambio+3){
                        cadena_codificada[i-semilla+cambio]=cadena_binaria[i-semilla+cambio];
                    }

                    for(int cambio=2;cambio<=semilla;cambio=cambio+3){
                        cadena_codificada[i-semilla+cambio]=cadena_binaria[i-semilla+cambio];
                    }

                }
            }else if(cant_unos<cant_ceros){
                cambio=0;
                if(cambio <=semilla){
                    for(cambio=2;cambio<=semilla;cambio=cambio+2){
                        if(cadena_binaria[i-semilla+cambio]=='0'){
                            cadena_codificada[i-semilla+cambio]='1';
                        }else if(cadena_binaria[i-semilla+cambio]=='1'){
                            cadena_codificada[i-semilla+cambio]='0';
                        }
                    }

                    for(cambio=1;cambio<=semilla;cambio=cambio+2){
                        cadena_codificada[i-semilla+cambio]=cadena_binaria[i-semilla+cambio];
                    }

                }
            }else if(cant_unos==cant_ceros){
                for(int cambio=1;cambio<=semilla;cambio++){
                    if(cadena_binaria[i-semilla+cambio]=='0'){
                        cadena_codificada[i-semilla+cambio] = '1';
                    }else if(cadena_binaria[i-semilla+cambio]=='1'){
                        cadena_codificada[i-semilla+cambio] = '0';
                    }
                }
            }
            cant_unos = 0;
            cant_ceros = 0;
        }
        cambio=0;
    }
    return cadena_codificada;
}


void fun_metodo_2(){

}


