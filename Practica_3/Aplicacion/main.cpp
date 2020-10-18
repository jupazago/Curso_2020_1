#include <iostream>
#include <fstream> //eof
#include <bitset>
#include <iostream>

using namespace std;

bool iniciar_sesion(string key);

string fun_deco_metodo_2(string cadena_codificada, int semilla);
string fun_a_decodificar2(string cadena_codificada, int semilla);

string fun_metodo_2(string cadena_texto, int semilla);
string fun_a_codificar2(string cadena_binaria, int semilla);

void registrar_usuario();




int main()
{
    string key;
    bool iniciar=false;
    int valor;

    //Inicio de sesion del administrador
    cout << "Hola, inicia sesion como administrador"<<endl<<endl;
    while (iniciar==false) {
        cout << "Contrasenia: ";
        cin >> key;
        if((iniciar_sesion(key))==true){
            iniciar = true;
        }else{
            cout << endl << "Reintente nuevamente"<<endl;
        }
    }
    cout <<endl<< "------------Menu-----------";
    cout <<endl<< "---------------------------";
    cout <<endl<< "1. Registrar Usuario";
    cout <<endl<< "2. Consultar saldo";
    cout <<endl<< "3. Retirar saldo";
    cout <<endl<< "4. Cerrar sesion";
    cout <<endl<< "---------------------------";
    cout <<endl<< "NOTA: El servicio de la opcion 2. y 3. tiene un costo de $ 1.000 Pesos";
    cout <<endl<<endl<<"Tu opcion: ";
    cin >> valor;
    while (iniciar==true) {

        switch (valor) {
        case 1: puts("Menu de registro de usuario \n");
            registrar_usuario();
        break;
        ///////////////////////////////////////////////
        case 2: puts("Consulta de saldo \n");
            //consultar_saldo(2);
        break;
        //////////////////////////////////////////////
        case 3: puts("Retirar dinero \n");
            //consultar_saldo(3);
        break;
        //////////////////////////////////////////////
        default:puts("Salir \n");
            iniciar=false;
        }
        cout <<endl<< "------------Menu-----------";
        cout <<endl<< "---------------------------";
        cout <<endl<<"Tu opcion: ";
        cin >> valor;
    }




    return 0;
}

bool iniciar_sesion(string key){
    string cadena_codificada;

    ifstream user_sudo;

    try {
        user_sudo.open("../sudo.txt", ios::in); //abro archivo para su lectura
        if(!user_sudo.is_open())
            throw '1';
        while(!user_sudo.eof()){ //mientras no sea el final del archivo
            getline(user_sudo, cadena_codificada);
        }
        user_sudo.close();

        string cadena_decodificada = fun_deco_metodo_2(cadena_codificada, 4);

        if(cadena_decodificada == key){
            return true;
        }
        cout << "Datos incorrectos";
        return false;

    } catch (char excepcion) {
        if(excepcion == '1'){
            cout << "Error de lectura en SUDO.txt"<<endl;
        }
        return false;
    }

}


string fun_deco_metodo_2(string cadena_codificada, int semilla){
    //system("cls");

    string cadena_binaria = fun_a_decodificar2(cadena_codificada, semilla);


    return cadena_binaria;
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
    }
    final += arreglo_binarioo;
    return final;
}


void registrar_usuario(){
    string  valor;
    string usuario, contrasena, saldo;
    int tusuario, tcontrasena, tsaldo;
    bool quedarse[3]={false,false,false};

    cout << endl<<endl<<"Todos los campos son numericos";
    cout << endl<<"Tenga en Cuenta"<<endl;
    cout << "*El documento debe tener de 5 a 10 digitos"<<endl;
    cout << "*La clave debe tene unicamente 4 digitos"<<endl;
    cout << "*Saldo a partir de cero pesos"<<endl;
    try {

        while(quedarse[0]==false){
            cout<<endl<<"Ingrese el documento a registrar: ";
            cin >> usuario;
            tusuario = usuario.size();
            if(tusuario>5 && tusuario<11){
                quedarse[0]=true;
            }else{
                quedarse[0]=false;
            }
        }
        while(quedarse[1]==false){
            cout<<endl<<"Ingrese la clave: ";
            cin >> contrasena;
            tcontrasena = contrasena.size();
            if(tcontrasena==4){
                for(int i=0; i<tcontrasena; i++){
                    if(contrasena[i] != '0'
                    && contrasena[i] != '1'
                    && contrasena[i] != '2'
                    && contrasena[i] != '3'
                    && contrasena[i] != '4'
                    && contrasena[i] != '5'
                    && contrasena[i] != '6'
                    && contrasena[i] != '7'
                    && contrasena[i] != '8'
                    && contrasena[i] != '9'){
                        quedarse[1]=false;
                        throw 505;
                    }else{
                        quedarse[1]=true;
                    }
                }
            }else{
                quedarse[1]=false;
            }
        }
        while(quedarse[2]==false){
            cout<<endl<<"Ingrese el saldo nuevo: ";
            cin >> saldo;
            tsaldo=saldo.size();
            if(tsaldo>=0){
                quedarse[2]=true;
            }else{
                quedarse[2]=false;
            }
        }
        string datos= " "+usuario+" "+contrasena+" "+saldo;
        cout << datos;

        string cadena_codificada = fun_metodo_2(datos, 4);
        int tamanio = cadena_codificada.size();
        string cadena_codificada_final;
        for(int i=0; i<tamanio; i++){
            if(cadena_codificada[i] == '1' && cadena_codificada[i] == '0'){
                cadena_codificada_final[i] = cadena_codificada[i];
            }
        }

        ofstream escritura;

        //guardar en el texto de base de datos
        escritura.open("../Data_Base.txt",ios::app);
        for(int i=0;i<tamanio;i++){
            escritura << cadena_codificada_final[i];
        }

        escritura.close();


    } catch (...) {
        cout << "Errores"<<endl;
    }
}


string fun_metodo_2(string cadena_texto, int semilla){
    try {
        string cadena_binaria;
        system("cls");
        for (size_t i = 0; i < cadena_texto.size(); ++i){
            cadena_binaria.append((bitset<8>(cadena_texto.c_str()[i])).to_string());
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


        return cad;
    } catch (...) {
        cout <<"ERROR"<<endl;
        return "";
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
    cout<<cadena_binaria<<"--"<<endl;


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
    cadena_codificada += arreglo_binario3;

    return  cadena_codificada;
}






