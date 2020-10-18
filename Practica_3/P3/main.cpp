#include <string>
#include <fstream> //eof
#include <bitset>
#include <iostream>

using namespace std;

void ejercicios();
void decodificar();

void fun_metodo_1(int semilla);
string fun_a_codificar1(string cadena_binaria, int semilla);

void fun_metodo_2(int semilla);
string fun_a_codificar2(string cadena_binaria, int semilla);

void fun_deco_metodo_1(int semilla);


void fun_deco_metodo_2(int semilla);
string fun_a_decodificar2(string cadena_codificada, int semilla);

int main()
{
    int opcion;
    cout << "--------------------------" << endl;
    cout << "------- Practica 3 -------" << endl;
    cout << "--------------------------" << endl;


    while (true) {
        cout << "1- Codificar" << endl;
        cout << "2- Aplicacion" << endl;
        cout << "3- Decodificar" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {

            case 1: puts("Codificar \n");
                ejercicios();
                break;

            case 2: puts("Aplicacion \n");
                cout << endl <<"Abrir el otro archivo main de apliacion"<<endl<<endl;
                break;

            case 3: puts("Decodificar \n");
                decodificar();
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
            fun_metodo_2(semilla);

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
        fileRead_texto.close();
        string cadena_binaria;
        system("cls");
        for (size_t i = 0; i < cadena_texto.size(); ++i){
            cadena_binaria.append((bitset<8>(cadena_texto.c_str()[i])).to_string());
            //cout << bitset<8>(cadena_texto[i])<<" ";
        }
        //cout <<endl<< cadena_binaria<<endl;
        cout << endl;
        //int tamanio = cadena_binaria.size();
        string cadena_codificada = fun_a_codificar1(cadena_binaria, semilla);

        /*
         *
         * Imprimir la cadena codificada del metodo 1
         *
        cout << "----------"<<endl;
        for(int i=0; i<tamanio; i++){
            cout << cadena_codificada[i];
        }
        cout << "----------"<<endl;

        */
        cout << endl;





    } catch (...) {
        cout <<"ERROR"<<endl;
    }
}

string fun_a_codificar1(string cadena_binaria, int semilla){
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


void fun_metodo_2(int semilla){
    try {
        ifstream fileRead_texto;  //Puedo crear el flujo lectura desde un archivo

        fileRead_texto.open("../archivo_texto.txt", ios::in); //abro archivo para su lectura
        if(!fileRead_texto.is_open()){
            throw 505;
        }

        string cadena_texto;

        while(!fileRead_texto.eof()){ //mientras no sea el final del archivo
            getline(fileRead_texto, cadena_texto);
        }
        fileRead_texto.close();


        string cadena_binaria;
        system("cls");
        for (size_t i = 0; i < cadena_texto.size(); ++i){
            cadena_binaria.append((bitset<8>(cadena_texto.c_str()[i])).to_string());
            //cout << bitset<8>(cadena_texto[i])<<" ";
        }
        cout << endl;
        int tamanio = cadena_binaria.size();
        string cadena_codificada = fun_a_codificar2(cadena_binaria, semilla);
        char cad[tamanio];

        /*
         * Imprimir la cadena codificada del metodo 2
         *
         */
        cout << "---------- codificado -----"<<endl;
        for(int i=0; i<tamanio; i++){
            //cout << cadena_codificada[i];
            cad[i] = cadena_codificada[i];
        }
        cout << "----------"<<endl;


        cout << endl;

        ofstream escritura_metodo2;
        string nombre_archivo= "../archivo_codificado.txt";
        cout << "Nombre de archivo de salida codificado: "<<nombre_archivo<<endl;

        escritura_metodo2.open((nombre_archivo),ios::out);//abriendo o creando el archivo
        if(escritura_metodo2.fail()){
            //Si hubo fallas, capturar la excepcion
            throw 505;
        }

        //ingreso el arreglo al archivo .txt
        for(int i=0; i<tamanio;i++){
            //cout << cad[i];
            escritura_metodo2 << cad[i];
        }

        escritura_metodo2.close();



    } catch (...) {
        cout <<"ERROR"<<endl;
    }
}

string fun_a_codificar2(string cadena_binaria, int semilla){
    int aux_evaluar = 1;
    int tamanio = cadena_binaria.size();
    int cambio = 0;
    int regresa = semilla;
    char arreglo_binario3[tamanio];
    char segundo_paso1[semilla];
    char segundo_paso2[semilla];

    for(int i=0; i<tamanio;i++){
        segundo_paso1[aux_evaluar-1] = cadena_binaria[i];
        if(aux_evaluar == semilla){
            aux_evaluar = 0;
            for(int j=0;j<semilla;j++){
                if(cambio==0 && j==0){
                    cambio = 1;
                    if(segundo_paso1[semilla-1]=='0'){
                        segundo_paso2[j]= '0';
                        arreglo_binario3[i-regresa+1] = '0';
                        regresa--;
                    }else if(segundo_paso1[semilla-1]=='1'){
                        segundo_paso2[j]= '1';
                        arreglo_binario3[i-regresa+1] = '1';
                        regresa--;
                    }
                }else{
                    if(segundo_paso1[j-1]=='0'){
                        segundo_paso2[j]= '0';
                        arreglo_binario3[i-regresa+1] = '0';
                        regresa--;
                    }else if(segundo_paso1[j-1]=='1'){
                        segundo_paso2[j]= '1';
                        arreglo_binario3[i-regresa+1] = '1';
                        regresa--;
                    }
                }
            }
            cambio = 0;
            regresa=semilla;
        }
        aux_evaluar++;
    }
    string cadena_codificada;
    for(int i=0; i<tamanio;i++){
        cadena_codificada[i] = arreglo_binario3[i];
    }

    return  cadena_codificada;
}

void decodificar(){
    int semilla, metodo;
    cout << "Seleccione la semilla: ";
    cin >> semilla;
    cout << "Metodo para decodificar: ";
    cin >> metodo;
    try {
        if(metodo == 1){
            fun_deco_metodo_1(semilla);

        }else if(metodo== 2){
            fun_deco_metodo_2(semilla);

        }else{
            throw 505;

        }
    } catch (...) {
        cout << "Error - seleccione un metodo valido."<<endl;
    }
}

void fun_deco_metodo_1(int semilla){
    //xd
}

void fun_deco_metodo_2(int semilla){
    try {
        ifstream fileRead_texto;  //Puedo crear el flujo lectura desde un archivo

        fileRead_texto.open("../archivo_codificado.txt", ios::in); //abro archivo para su lectura
        if(!fileRead_texto.is_open()){
            throw '2';
        }

        string cadena_codificada;

        while(!fileRead_texto.eof()){ //mientras no sea el final del archivo
            getline(fileRead_texto, cadena_codificada);
        }

        fileRead_texto.close();
        system("cls");

        int tamanio = cadena_codificada.size();
        string cadena_binaria = fun_a_decodificar2(cadena_codificada, semilla);

        cout << endl;

        ofstream escritura_metodo2;
        string nombre_archivo= "../archivo_resultado.txt";
        cout << "Nombre de archivo de salida codificado: "<<nombre_archivo<<endl;

        escritura_metodo2.open((nombre_archivo),ios::out);//abriendo o creando el archivo
        if(escritura_metodo2.fail()){
            //Si hubo fallas, capturar la excepcion
            throw '3';
        }

        //ingreso el arreglo al archivo .txt
        for(int i=0; i<tamanio/8;i++){
            //cout << cadena_binaria[i];
            escritura_metodo2 << cadena_binaria[i];
        }

        escritura_metodo2.close();

    } catch (...) {
        cout <<"ERROR"<<endl;
    }
}

string fun_a_decodificar2(string cadena_codificada, int semilla){
    int tamanio = cadena_codificada.size();
    int cambio = 0;
    int aux_evaluar = 1;
    int regresa = semilla-1;
    char arreglo_binario1[tamanio];
    int cont = 0;

    string segundo_paso1, segundo_paso;


    for(int i=0; i<tamanio;i++){
        segundo_paso1[aux_evaluar-1]=cadena_codificada[i];
        //cout <<texto_cifrado[i];
        if(aux_evaluar == semilla){
            aux_evaluar = 0;
            for(int j=0;j<semilla;j++){
                if(cambio==0 && j==0){
                    cambio = 1;
                    if(segundo_paso1[j]=='0'){
                        segundo_paso[regresa]= '0';
                        //cout << segundo_paso1[j];
                        arreglo_binario1[i-regresa] = '0';
                        regresa--;
                    }else if(segundo_paso1[j]=='1'){
                        //cout << segundo_paso1[j];
                        segundo_paso[regresa]= '1';
                        arreglo_binario1[i-regresa] = '1';
                        regresa--;
                    }
                }else{
                    if(segundo_paso1[j]=='0'){
                        segundo_paso[j-1]= '0';
                        //cout << segundo_paso1[j];
                        arreglo_binario1[i-regresa] = '0';
                        regresa--;
                    }else if(segundo_paso1[j]=='1'){
                        //cout << segundo_paso1[j];
                        segundo_paso[j-1]= '1';
                        arreglo_binario1[i-regresa] = '1';
                        regresa--;
                    }
                }
            }
            regresa=semilla-1;
            for(int j=0;j<semilla;j++){
                //cout << segundo_paso[j];
                if(segundo_paso[j]=='0'){
                    arreglo_binario1[i-regresa] = '0';
                }else if(segundo_paso[j]=='1'){
                    arreglo_binario1[i-regresa] = '1';
                }

                regresa--;
            }

            cambio = 0;
            //cout << " ";
            regresa=semilla-1;

        }
        aux_evaluar++;
        //cout <<endl<< i<<endl;
    }
    cout<< endl<<endl<<endl;
    regresa = semilla-1;
    cout<< endl;
    int contador=0;
    int contador2=0;
    char arreglo_binarioo[tamanio];
    char num;
    char arreglo_auxiliar[8];
    for(int i=0; i<tamanio;i++){
        arreglo_auxiliar[contador]=arreglo_binario1[i];
        //cout << arreglo_binario1[i];
        if(contador==7){
            contador=-1;
            for(int j=7; j>=0;j--){
                //cout << arreglo_auxiliar[j];
                if(j==7){
                    if(arreglo_auxiliar[7]=='0'){
                        num = num+(0*1);
                    }else if(arreglo_auxiliar[7]=='1'){
                        num = num+(1*1);
                    }
                }else if(j==6){
                    if(arreglo_auxiliar[6]=='0'){
                        num = num+(0*2);
                    }else if(arreglo_auxiliar[6]=='1'){
                        num = num+(1*2);
                    }
                }else if(j==5){
                    if(arreglo_auxiliar[5]=='0'){
                        num = num+(0*4);
                    }else if(arreglo_auxiliar[5]=='1'){
                        num = num+(1*4);
                    }
                }else if(j==4){
                    if(arreglo_auxiliar[4]=='0'){
                        num = num+(0*8);
                    }else if(arreglo_auxiliar[4]=='1'){
                        num = num+(1*8);
                    }
                }else if(j==3){
                    if(arreglo_auxiliar[3]=='0'){
                        num = num+(0*16);
                    }else if(arreglo_auxiliar[3]=='1'){
                        num = num+(1*16);
                    }
                }else if(j==2){
                    if(arreglo_auxiliar[2]=='0'){
                        num = num+(0*32);
                    }else if(arreglo_auxiliar[2]=='1'){
                        num = num+(1*32);
                    }
                }else if(j==1){
                    if(arreglo_auxiliar[1]=='0'){
                        num = num+(0*64);
                    }else if(arreglo_auxiliar[1]=='1'){
                        num = num+(1*64);
                    }
                }else if(j==0){
                    if(arreglo_auxiliar[0]=='0'){
                        num = num+(0*128);
                    }else if(arreglo_auxiliar[0]=='1'){
                        num = num+(1*128);
                    }
                }else{
                    throw '2';
                }

            }
            arreglo_binarioo[contador2]=num;
            contador2=contador2+1;
            //cout << num << " ";
            num=0;
        }
        contador++;
    }
    cout << endl<<endl;
    string final;

    //division por 8, es la cantidad de bits que tiene un byte, osea cada letra
    for(int i=0; i<(tamanio/8);i++){
        final[i] = arreglo_binarioo[i];
        //cout << arreglo_binarioo[i];
    }
    cout << endl;
    return final;
}






