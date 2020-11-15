#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream> //eof
#include <relacion.h>

using namespace std;

map<string,vector<Relacion>> cargar_datos(map<string,vector<Relacion>> contenedor);
void imprimir(map<string,vector<Relacion>> contenedor);
map<string,vector<Relacion>> CrearEnrutador(map<string,vector<Relacion>> enrutador, string nom_enrutador);
map<string,vector<Relacion>> RemoverEnrutador(map<string,vector<Relacion>> enrutador, string nom_enrutador);
bool existenciaEnrutadores(map<string,vector<Relacion>> enrutador, string nom_enrutador);
map<string,vector<Relacion>> CrearRelacion(map<string,vector<Relacion>> enrutador, string nom_enrutador, string nom_enrutador2);
map<string,vector<Relacion>> EliminarRelacion(map<string,vector<Relacion>> enrutador, string nom_enrutador, string nom_enrutador2);
bool existeRuta(map<string,vector<Relacion>> contenedor, string nom_enrutador1, string nom_enrutador2, string *recorrido, int *costo_total);

int main()
{
    int valor=1;
    string nom_enrutador, nom_enrutador2, nom_enrutador1;
    bool encontrado=false, encontrado2=false ;

    //mapa de clave ENRUTADOR y valor de tipo vector de estructura RELACION
    map<string,vector<Relacion>> enrutador; //mapa se llama ENRUTADOR, está vacio.
    imprimir(enrutador);
    while (valor!=0) {
        //////////////////////////////////////////finalizado....
        cout << "       Menu" << endl;
        cout << "-------------------" << endl;
        cout << "1- Agregar Enrutadores" << endl; //si
        cout << "2- Remover Enrutadores" << endl; //si
        cout << "3- Crear Conexion o Actualizar" << endl; //si
        cout << "4- Eliminar Conexion" << endl; //si
        cout << "5- Ver mapa de conexiones" << endl; //si
        cout << "6- Costo de envio de paquete" << endl; //no finalizado
        cout << "7- Generar automaticamente" << endl << endl; //si
        cout << "Opcion: ";
        cin >> valor;



        if(valor==1){
            //Agregar enrutador
            encontrado=false;
            cout<<endl<<"Ingresa nombre del enrutador: ";
            cin >> nom_enrutador;
            encontrado = existenciaEnrutadores(enrutador, nom_enrutador);

            //si no existe el enrutador con ese nombre, lo creamos.
            //si ya existe, da el aviso de su existencia.
            if(encontrado==false){
                enrutador = CrearEnrutador(enrutador, nom_enrutador);
                cout << "Creacion exitosa"<<endl<<endl;
            }else {
                cout << "Ya existe un enrutador con ese nombre: "<<nom_enrutador<<endl;
            }

        }else if(valor==2){
            //Remover enrutador
            encontrado=false;
            cout<<endl<<"Ingresa nombre del enrutador: ";
            cin >> nom_enrutador;
            encontrado = existenciaEnrutadores(enrutador, nom_enrutador);
            //si no existe el enrutador da el aviso.
            //si si existe, lo eliminamos
            if(encontrado==false){
                cout << "No existe Enrutador"<<endl;

            }else {
                enrutador = RemoverEnrutador(enrutador, nom_enrutador);
                cout << "Eliminacion exitosa"<<endl;
            }
        }else if(valor==3){
            //Crear conexion entre enrutadores
            encontrado=false;
            encontrado2=false;

            cout<<endl<<"Ingresa nombre del enrutador #1: ";
            cin >> nom_enrutador;
            encontrado = existenciaEnrutadores(enrutador, nom_enrutador);

            cout<<endl<<"Ingresa nombre del enrutador #2: ";
            cin >> nom_enrutador2;
            encontrado2 = existenciaEnrutadores(enrutador, nom_enrutador2);

            if(encontrado==true && encontrado2==true){
                //si si existe
                enrutador = CrearRelacion(enrutador, nom_enrutador,nom_enrutador2);

            }else if(encontrado==false && encontrado2==false){
                cout << "No existe ningun enrutador con esos nombres"<<endl;

            }else if(encontrado==false){
                cout << "No existe un enrutador con dicho nombre: "<<nom_enrutador<<endl;

            }else if(encontrado2==false){
                cout << "No existe un enrutador con dicho nombre: "<<nom_enrutador2<<endl;
            }


        }else if(valor==4){
            //Eliminar conexion de enrutadores
            encontrado=false;
            encontrado2=false;

            cout<<endl<<"Ingresa nombre del enrutador #1: ";
            cin >> nom_enrutador;
            encontrado = existenciaEnrutadores(enrutador, nom_enrutador);

            cout<<endl<<"Ingresa nombre del enrutador #2: ";
            cin >> nom_enrutador2;
            encontrado2 = existenciaEnrutadores(enrutador, nom_enrutador2);

            if(encontrado==true && encontrado2==true){
                //si si existe
                enrutador = EliminarRelacion(enrutador, nom_enrutador,nom_enrutador2);

            }else if(encontrado==false && encontrado2==false){
                cout << "No existe ningun enrutador con esos nombres"<<endl;

            }else if(encontrado==false){
                cout << "No existe un enrutador con dicho nombre: "<<nom_enrutador<<endl;

            }else if(encontrado2==false){
                cout << "No existe un enrutador con dicho nombre: "<<nom_enrutador2<<endl;
            }

        }else if(valor==5){
            imprimir(enrutador);

        }else if(valor==6){
            bool encontrados[2] = {false, false};


            cout<<endl<<"Ingresa nombre del enrutador #1: ";
            cin >> nom_enrutador1;
            encontrados[0] = existenciaEnrutadores(enrutador, nom_enrutador1);

            cout<<endl<<"Ingresa nombre del enrutador #2: ";
            cin >> nom_enrutador2;
            encontrados[1] = existenciaEnrutadores(enrutador, nom_enrutador2);

            if(encontrados[0]==true && encontrados[1]==true){
                //si si existe
                string recorrido;
                int costo_total=0;
                bool verificar = existeRuta(enrutador, nom_enrutador1, nom_enrutador2, &recorrido, &costo_total);
                if(verificar == true){
                    cout << "Primera ruta encontrada: "<<recorrido<<endl;
                    cout << "Costo Total: "<<costo_total<<endl;
                }else{
                    cout<<"La distancia entre los enrutadores es mayor a 2"<<endl;
                }

            }else if(encontrados[0]==false && encontrados[1]==false){
                cout << "No existe ningun enrutador con esos nombres"<<endl;

            }else if(encontrados[0]==false){
                cout << "No existe un enrutador con dicho nombre: "<<nom_enrutador<<endl;

            }else if(encontrados[1]==false){
                cout << "No existe un enrutador con dicho nombre: "<<nom_enrutador2<<endl;
            }




        }else if(valor==7){
            //cargar datos de simulacion
            enrutador=cargar_datos(enrutador);
        }
    }//fin del while

    return 0;
}


map<string,vector<Relacion>> cargar_datos(map<string,vector<Relacion>> contenedor){
    //Relacion relacion; //Instanciamos la clase


    //Relacion relacion("A", 0);  //Ejemplo por constructor
/*
    relacion.setConexion("A");
    relacion.setCosto(0);
    contenedor["A"].push_back(relacion);

    relacion.setConexion("B");
    relacion.setCosto(4);
    contenedor["A"].push_back(relacion);

    relacion.setConexion("C");
    relacion.setCosto(7);
    contenedor["A"].push_back(relacion);

    relacion.setConexion("D");
    relacion.setCosto(5);
    contenedor["A"].push_back(relacion);



    relacion.setConexion("A");
    relacion.setCosto(4);
    contenedor["B"].push_back(relacion);

    relacion.setConexion("B");
    relacion.setCosto(0);
    contenedor["B"].push_back(relacion);

    relacion.setConexion("C");
    relacion.setCosto(3);
    contenedor["B"].push_back(relacion);

    relacion.setConexion("D");
    relacion.setCosto(1);
    contenedor["B"].push_back(relacion);



    relacion.setConexion("A");
    relacion.setCosto(7);
    contenedor["C"].push_back(relacion);

    relacion.setConexion("B");
    relacion.setCosto(3);
    contenedor["C"].push_back(relacion);

    relacion.setConexion("C");
    relacion.setCosto(0);
    contenedor["C"].push_back(relacion);

    relacion.setConexion("D");
    relacion.setCosto(2);
    contenedor["C"].push_back(relacion);



    relacion.setConexion("A");
    relacion.setCosto(5);
    contenedor["D"].push_back(relacion);

    relacion.setConexion("B");
    relacion.setCosto(1);
    contenedor["D"].push_back(relacion);

    relacion.setConexion("C");
    relacion.setCosto(2);
    contenedor["D"].push_back(relacion);

    relacion.setConexion("D");
    relacion.setCosto(0);
    contenedor["D"].push_back(relacion);


    */
    Relacion relacion;


    ifstream fileRead_texto;  //Puedo crear el flujo lectura desde un archivo
    string nombre_archivo= "../Data_Base.txt";

    fileRead_texto.open(nombre_archivo, ios::in); //abro archivo para su lectura
    if(!fileRead_texto.is_open()){
        throw '2';
    }
    string cadena = "invalido", enrutador;
    int costo;
    while(!fileRead_texto.eof()){ //mientras no sea el final del archivo
        if(cadena=="-"){
            fileRead_texto >> cadena;
            enrutador = cadena;
        //---------------------------------
            fileRead_texto >> cadena;
            relacion.setConexion(cadena);
        //---------------------------------
            fileRead_texto >> cadena;
            costo = stoi(cadena);
            relacion.setCosto(costo);
        //---------------------------------
            contenedor[enrutador].push_back(relacion);


        }else if(cadena != "invalido"){
            enrutador = cadena;
        //---------------------------------
            fileRead_texto >> cadena;
            relacion.setConexion(cadena);
        //---------------------------------
            fileRead_texto >> cadena;
            costo = stoi(cadena);
            relacion.setCosto(costo);
        //---------------------------------
            contenedor[enrutador].push_back(relacion);

        }

        fileRead_texto >> cadena;

    }
    fileRead_texto.close();

    return contenedor;
}

void imprimir(map<string,vector<Relacion>> contenedor){
    cout <<"---------------------------------" <<endl<<endl;
    for(auto par=begin(contenedor); par!=end(contenedor); par++){
        cout <<"Enrutador: "<< par->first <<endl;
        cout <<"Conexiones:          Costo:" <<endl;
        for(auto emp=begin(par->second);emp!=end(par->second); emp++){
         cout<<par->first<<":"<< emp->getConexion()<<"                         "<<emp->getCosto()<<endl<<endl;
        }
        cout <<"---------------------------------" <<endl<<endl;
    }
}
map<string,vector<Relacion>> CrearEnrutador(map<string,vector<Relacion>> enrutador, string nom_enrutador){
    Relacion relacion;

    //Creamos el enrutador y su costo con si mismo como valor inicial
    relacion.setConexion(nom_enrutador);
    relacion.setCosto(0);

    //relacion.conexion = nom_enrutador;
    //relacion.costo = 0;
    enrutador[nom_enrutador].push_back(relacion);

    return enrutador;
}

map<string,vector<Relacion>> RemoverEnrutador(map<string,vector<Relacion>> enrutador, string nom_enrutador){
    //Recorremos el mapa y aliminamos primeramente las conexiones,
    //que se encuentren relacionadas al enrutador a eliminar
    string conectar;
    for(auto par=begin(enrutador); par!=end(enrutador); par++){
        //cout <<"Enrutador: "<< par->first <<endl;
        auto p=begin(par->second);//valor del mapa
        while (p != end(par->second)) {//recorrer valor del mapa
            if(p->getConexion()==nom_enrutador){
                p = (par->second).erase(p);
                //p->getConexion();
            }else{
                p++;
            }
        }
    }

    enrutador.erase(nom_enrutador);
    return enrutador;
}

bool existenciaEnrutadores(map<string,vector<Relacion>> enrutador, string nom_enrutador){

    //Verificamos si existe un enrutador con el mismo nombre en el mapa
    if(enrutador.find(nom_enrutador) == enrutador.end()){
        //no existe
        //cout << endl<<"No existe"<<endl;
        return false;
    }else{
        //existe
        //cout << endl<<"Existe"<<endl;
        return true;
    }
}

map<string,vector<Relacion>> CrearRelacion(map<string,vector<Relacion>> enrutador, string nom_enrutador, string nom_enrutador2){
    Relacion relacion;
    int ncosto;
    bool encontrado=false;
    cout << "Que costo tendra la relacion: ";
    cin >> ncosto;
    string comparar;
    for(auto par=begin(enrutador); par!=end(enrutador); par++){
        //cout <<"Enrutador: "<< par->first <<endl;
        if(par->first==nom_enrutador){

            auto p=begin(par->second);//valor del mapa
            while (p != end(par->second) && encontrado==false) {//recorrer valor del mapa, VECTOR
                comparar = p->getConexion();
                if(comparar==nom_enrutador2){
                    p->setCosto(ncosto);//asiganamos el set para darle ese valor
                    encontrado=true;
                }else{
                    p++;
                }
            }
        }
        if(par->first==nom_enrutador2){
            encontrado=false;
            auto p=begin(par->second);//valor del mapa
            while (p != end(par->second) && encontrado==false) {//recorrer valor del mapa, VECTOR
                comparar = p->getConexion();
                if(comparar==nom_enrutador){
                    p->setCosto(ncosto);
                    encontrado=true;
                }else{
                    p++;
                }
            }
        }
    }
    if(encontrado!=true){

        relacion.setConexion(nom_enrutador2);
        relacion.setCosto(ncosto);
        //relacion.conexion=nom_enrutador2;
        //relacion.costo=ncosto;
        enrutador[nom_enrutador].push_back(relacion);

        relacion.setConexion(nom_enrutador);
        relacion.setCosto(ncosto);
        //relacion.conexion=nom_enrutador;
        //relacion.costo=ncosto;
        enrutador[nom_enrutador2].push_back(relacion);
    }else{
        cout << "Ya existe una relacion, se actualizara su costo"<<endl;
    }

    return enrutador;
}
map<string,vector<Relacion>> EliminarRelacion(map<string,vector<Relacion>> enrutador, string nom_enrutador, string nom_enrutador2){
    //Recorremos el mapa y aliminamos primeramente las conexiones,
    //que se encuentren relacionadas al enrutador a eliminar
    for(auto par=begin(enrutador); par!=end(enrutador); par++){
        //cout <<"Enrutador: "<< par->first <<endl;
        auto p=begin(par->second);//valor del mapa
        while (p != end(par->second)) {//recorrer valor del mapa
            if(p->getConexion()==nom_enrutador && par->first==nom_enrutador2){
                p = (par->second).erase(p);
            }else if(p->getConexion()==nom_enrutador2 && par->first==nom_enrutador){
                p = (par->second).erase(p);
            }else{
                p++;
            }
        }
    }
    return enrutador;
}


bool existeRuta(map<string,vector<Relacion>> contenedor, string nom_enrutador1, string nom_enrutador2, string *recorrido, int *costo_total){

    for(auto par=begin(contenedor); par!=end(contenedor); par++){
        *recorrido = " ";
        *recorrido = *recorrido + par->first + " ";
        *costo_total= 0;

        if(par->first == nom_enrutador1){
            //cout<<"*"<<par->first<<endl;
            for(auto emp=begin(par->second); emp!=end(par->second); emp++){
                if(emp->getConexion() == nom_enrutador2){

                    //Si se encuentra a una distancia de 1

                    *recorrido = *recorrido + emp->getConexion() + " ";
                    *costo_total += stoi(to_string(emp->getCosto()));
                    cout<<" "<<emp->getConexion();
                    cout<<endl<<endl;
                    return true;

                }
                if(emp->getConexion() != nom_enrutador1){
                    //cout<<" **"<<emp->getConexion()<<": ";

                    for(auto par2=begin(contenedor); par2!=end(contenedor); par2++){
                        if(par2->first == emp->getConexion()){
                            //Entramos a ver sus rutas
                            //cout<<" -"<<par2->first;
                            for(auto emp2=begin(par2->second); emp2!=end(par2->second); emp2++){

                                if(emp2->getConexion() == nom_enrutador2){
                                    *recorrido = *recorrido + emp->getConexion() + " ";
                                    *recorrido = *recorrido + emp2->getConexion() + " ";
                                    *costo_total += stoi(to_string(emp->getCosto()));
                                    *costo_total += stoi(to_string(emp2->getCosto()));
                                    cout<<endl<<endl;
                                    return true;
                                }

                                if(emp2->getConexion() != nom_enrutador1 || par2->first != emp->getConexion()){
                                    //cout << " -"<<emp2->getConexion();
                                }
                            }
                        }
                    }
                }
                cout<<endl;
            }
        }
    }
    //par->first                Enrutador
    //emp->getConexion()        conexion
    //emp->getCosto()           costo
    return false;
}


