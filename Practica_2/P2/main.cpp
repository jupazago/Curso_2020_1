#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;
//Grupo 4 (6-7)  2,3,5,7,10,11,13,14,16,17
void ejercicio_2();//R
void ejercicio_3();//R
void ejercicio_5();//R
void ejercicio_7();//R
void ejercicio_10();//R
void ejercicio_11();//R
void ejercicio_13();//R
void ejercicio_14();//R
void ejercicio_16();//R
void ejercicio_17();

char fun_convertir(int *a);
char fun_convertir2(int a);
void funcion_cine1();
int funcion_galaxia(int *a);
int valor(char r);
int fun_romano(char numero[], int cifras);

int main()
{
    int valor = 1;

        cout << "*******************************"<<endl;
        cout << "******** Laboratorio 2 ********"<<endl;
        cout << "*******************************"<<endl<<endl;

        cout << "seleccione un ejercicio: ";
        cin >> valor;

        while (valor!=0) {
            switch(valor) {
                case 2: puts("Se ha pulsado el Ejercicio 2 \n");
                    ejercicio_2();
                    break;

                case 3: puts("Se ha pulsado el Ejercicio 3 \n");
                    ejercicio_3();
                    break;

                case 5: puts("Se ha pulsado el Ejercicio 5 \n");
                    ejercicio_5();
                    break;

                case 7: puts("Se ha pulsado el Ejercicio 7 \n");
                    ejercicio_7();
                    break;

                case 10: puts("Se ha pulsado el Ejercicio 10 \n");
                    ejercicio_10();
                    break;

                case 11: puts("Se ha pulsado el Ejercicio 11 \n");
                    ejercicio_11();
                    break;

                case 13: puts("Se ha pulsado el Ejercicio 13 \n");
                    ejercicio_13();
                    break;

                case 14: puts("Se ha pulsado el Ejercicio 14 \n");
                    ejercicio_14();
                    break;

                case 16: puts("Se ha pulsado el Ejercicio 16 \n");
                    ejercicio_16();
                    break;

                case 17: puts("Se ha pulsado el Ejercicio 17 \n");
                    ejercicio_17();
                    break;

                default: puts("Error, selecciona una opcion valida \n");
            }
            cout << "--------------------------------------------------------"<<endl;
            cout << endl<<endl<<"seleccione un ejercicio: ";
            cin >> valor;
        }
    return 0;
}

void ejercicio_2(){
    //variable para cada letra del abecedario
    int la=0,lb=0,lc=0,ld=0,le=0,lf=0,lg=0,lh=0,li=0,lj=0,lk=0,ll=0,lm=0,ln=0,lo=0,lp=0,lq=0,lr=0,ls=0,lt=0,lu=0,lv=0,lw=0,lx=0,ly=0,lz=0; // variables ejercicio 2

    int entero_letra;
    char letra;
    int arreglo_letras[100];

    //Recorro el arreglo y le asigno un valor al azar de deltras Mayusculas
    //en el codigo ASCII

    for(int I=0; I<100; I++){
        arreglo_letras[I] = (rand() %26 + 65); // genera numero aleatorio 65 al 90, 91 no
        entero_letra = arreglo_letras[I]; //lo almaceno  temporalmente en el auxiliar tipo int
        letra = entero_letra; //lo pasamos a ascii
        cout << letra;

        //Añado un valor de +1 depende de la letra, desde A hasta Z

        if(entero_letra==65){
            la++;
        }else if(entero_letra==66){
            lb++;
        }else if(entero_letra==67){
            lc++;
        }else if(entero_letra==68){
            ld++;
        }else if(entero_letra==69){
            le++;
        }else if(entero_letra==70){
            lf++;
        }else if(entero_letra==71){
            lg++;
        }else if(entero_letra==72){
            lh++;
        }else if(entero_letra==73){
            li++;
        }else if(entero_letra==74){
            lj++;
        }else if(entero_letra==75){
            lk++;
        }else if(entero_letra==76){
            ll++;
        }else if(entero_letra==77){
            lm++;
        }else if(entero_letra==78){
            ln++;
        }else if(entero_letra==79){
            lo++;
        }else if(entero_letra==80){
            lp++;
        }else if(entero_letra==81){
            lq++;
        }else if(entero_letra==82){
            lr++;
        }else if(entero_letra==83){
            ls++;
        }else if(entero_letra==84){
            lt++;
        }else if(entero_letra==85){
            lu++;
        }else if(entero_letra==86){
            lv++;
        }else if(entero_letra==87){
            lw++;
        }else if(entero_letra==88){
            lx++;
        }else if(entero_letra==89){
            ly++;
        }else if(entero_letra==90){
            lz++;
        } else{
            cout << "error"<<endl;
        }
    }
    cout << endl<<endl;
    //Imprimo cada valor

    cout << "cantidad de A:" << la<<endl;
    cout << "cantidad de B:" << lb<<endl;
    cout << "cantidad de C:" << lc<<endl;
    cout << "cantidad de D:" << ld<<endl;
    cout << "cantidad de E:" << le<<endl;
    cout << "cantidad de F:" << lf<<endl;
    cout << "cantidad de G:" << lg<<endl;
    cout << "cantidad de H:" << lh<<endl;
    cout << "cantidad de I:" << li<<endl;
    cout << "cantidad de J:" << lj<<endl;
    cout << "cantidad de K:" << lk<<endl;
    cout << "cantidad de L:" << ll<<endl;
    cout << "cantidad de M:" << lm<<endl;
    cout << "cantidad de N:" << ln<<endl;
    cout << "cantidad de O:" << lo<<endl;
    cout << "cantidad de P:" << lp<<endl;
    cout << "cantidad de Q:" << lq<<endl;
    cout << "cantidad de R:" << lr<<endl;
    cout << "cantidad de S:" << ls<<endl;
    cout << "cantidad de T:" << lt<<endl;
    cout << "cantidad de U:" << lu<<endl;
    cout << "cantidad de V:" << lv<<endl;
    cout << "cantidad de W:" << lw<<endl;
    cout << "cantidad de X:" << lx<<endl;
    cout << "cantidad de Y:" << ly<<endl;
    cout << "cantidad de Z:" << lz<<endl;

}

void ejercicio_3(){
    try {
        char palabra1[30], palabra2[30];
        bool retorno=false;

        cout << "Ingrese la primera palabra: ";
        cin >> palabra1;

        cout << endl << endl;

        cout <<"Ingrese la segunda palabra: ";
        cin >> palabra2;

        //Capturamos la excepción


        for(int i=0; i<30; i++){
            if(palabra1[i] == palabra2[i]){
                if(palabra1[i] == '\0' && palabra2[i]== '\0'){
                    retorno = true;
                    break;
                }
                continue;
            }else {
                throw '1';
            }
        }

        cout << "El resultado es: "<<retorno<<endl;

    }catch (char capturador) {
        bool retorno=false;
        cout << "Error: ";
        if(capturador=='1'){
            cout << "Las palabras no son iguales"<<endl;
            cout << "El resultado es: "<<retorno<<endl;
        }
    }
}

void ejercicio_5(){
    //una variable INT a String por medio de punteros

    int n_convertir;
    int *p_n_convertir = &n_convertir; //puntero

    cout << "Ingrese el numero a convertir: ";
    cin >> n_convertir;

    cout << endl<< "La cadena es: "<< fun_convertir(p_n_convertir)<<endl<<endl;
}

char fun_convertir(int *a){
    int cifras = 1;
    int copia = *a;
    int residuo = 0;

    while (copia>9) {
        copia /= 10;
        cifras++;
    }

    char retorno[cifras];
    copia = *a;

    for(int i=cifras-1; i>=0; i--){
        residuo = copia%10;
        copia /=10;
        retorno[i]=residuo+48;
    }
    cout << retorno;




    return retorno[cifras];
}

void ejercicio_7(){
    //variables para 7
    char pala_original[25];
    char pala_final[25];
    int tamano;
    bool pala_encontrada = false;
    int cont=0;

    //Eliminar letra repetidas en una cadena de texto

    cout << "Ingrese palabra Original" << endl;
    cin >> pala_original;
    tamano = 25;
    for(int i=0; i<tamano ; i++){
        //pala_original[i]
        for(int j=0; j<tamano;j++){
            if(pala_original[i]==pala_final[j]){
                pala_encontrada=true;
            }
        }
        if(pala_original[i]=='\0'){
            break;
        }
        if (pala_encontrada==true){
            pala_encontrada=false;
        } else {
            pala_final[cont]=pala_original[i];
            cout<<pala_final[cont];
            cont++;
        }
    }
    cout << endl;
}

void ejercicio_10(){
    char numero[30];
    int cifras=0;

    cout << "Ingrese el numero en ROMANO: ";
    cin >> numero;

    for(int i=0; i<30; i++){
        if(numero[i]!= '\0'){
            cifras++;
        }else{
            break;
        }
    }


    cout << "El numero romano es: " << fun_romano(numero,cifras) << endl;
}

int valor(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1; //Cantidad de letras que no son parte de los numeros romanos
}

int fun_romano(char numero[], int cifras){


    int res = 0;
    for (int i = 0; i < cifras; i++) {
        // simbolo de i
        int n1 = valor(numero[i]);

        if (i + 1 < cifras) {
            // obtener el valor i+1
            int n2 = valor(numero[i + 1]);

            // Comparando los valores
            if (n1 >= n2) {
                //actual comparandolo al siguiente
                res = res + n1;
            }
            else {
                // Valor del simbolo actual
                res = res + n2 - n1;
                i++;
            }
        }
        else {
            res = res + n1;
        }
    }
    return res;
}

void ejercicio_11(){

    char cine[15][20];
    int decision;
    char auxiliar_cine[15]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
    char fila_cine;
    int columna_cine;

    //Genero salas de cine

    for(int i=0; i<15;i++){
        for(int j=0;j<20;j++){
            cine[i][j]='-';
        }
    }
    //preguntar

    cout << "¿Que deseas hacer?" << endl << endl;
    cout << "1 - reservar" << endl;
    cout << "2 - cancelar reserva" << endl;
    cout << "3 - Ver Disponibilidad" << endl;
    cout << "cualquier numero - Salir" << endl;
    cin >> decision;
    while(decision>0 && decision<4){

        //Imprimir Sala de cine actual

        funcion_cine1();
        cout << endl;
        for(int i=0; i<15;i++){
            cout << auxiliar_cine[i] << "    ";
            for(int j=0;j<20;j++){
                cout << cine[i][j] << "   ";
            }
            cout << endl;
        }

        //Reservar

        if (decision==1){
            cout << "Ingresa Fila a seleccionar: letra A-O" << endl;
            cin >> fila_cine;
            cout << "Ingresa Columna a seleccionar: numero 1-20" << endl;
            cin >> columna_cine;
            //cout << fila_cine-65<<endl;  FILAS
            //cout << columna_cine-1<<endl; COLUMNAS
            cine[fila_cine-65][columna_cine-1]='+';

        } else if(decision==2){

            //Cancelar

            cout << "Ingresa Fila a seleccionar: letra A-O" << endl;
            cin >> fila_cine;
            cout << "Ingresa Columna a seleccionar: numero 1-20" << endl;
            cin >> columna_cine;
            cine[fila_cine-65][columna_cine-1]='-';
        } else{
            //blanco
        }


        //Preguntar

        cout << endl<< endl;
        cout << "¿Que deseas hacer?" << endl << endl;
        cout << "1 - reservar" << endl;
        cout << "2 - cancelar reserva" << endl;
        cout << "3 - Ver Disponibilidad" << endl;
        cout << "cualquier numero - Salir" << endl;
        cin >> decision;
    }
}

void funcion_cine1(){
    //Imprime puestos
    cout << "Total de puestos"<<endl;
    cout << "     ";
    cout << 1;
    for(int i=1; i<10;i++){
        cout << "   ";
        cout << (i+1);
    }
    for(int i=1; i<11;i++){
        cout << "  ";
        cout << (i+10);
    }
}

void ejercicio_13(){
    int matriz_galaxia[6][8]={{0,3,4,0,0,0,6,8},{5,13,6,0,0,0,2,3},{2,6,2,7,3,0,10,0},{0,0,4,15,4,1,6,0},{0,0,7,12,6,9,10,4},{5,0,6,10,6,4,8,0}};
    int *punt_galaxia = &matriz_galaxia[0][0];
    int promedio_galaxia;

    promedio_galaxia=funcion_galaxia(punt_galaxia);
    cout << "Estrellas encontradas en la imagen: " << promedio_galaxia << endl;
}

int funcion_galaxia(int *a){
    //Imprimir tabla
    float promedio;
    int contador=0;
    int cont =0;
    cout << "Matriz de la galaxia NGC 1300" << endl << endl;

    //Imprimir la tabla

    for(int i=0; i<(6*8); i++){
        if(*(a+i)>9){
            cout << *(a+i) << "| ";
        }else{
            cout << *(a+i) << " | ";
        }
        cont++;
        //Imprimir salto de linea
        if (cont ==8){
            cont = 0;
            cout << endl;
        }
    }
    //buscador de estrellas
    for(int i=0; i<(6*8);i++){
        if(i<8 || i==15 || i==(15+1) || i==23 || i==(23+1) || i==31 || i==(31+1) || i>39){
            //cout << *(a+i) << " - ";
            continue;
        }else{
            promedio = (*(a+i) + *(a+(i-1)) + *(a+(i+1)) + *(a+(i-8)) + *(a+(i+8)))/5;
            if(promedio >=6.0){
                contador++;
            }
        }
    }
    return contador;
}

void ejercicio_14(){
    //Matriz 5x5 que vamos a rotar
    int a[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

    cout << "Matriz Original" << endl;
    for(int i=0; i<5;i++){
        for(int j=0; j<5; j++){
            if((a[i][j])>9){
                cout << a[i][j] << "- ";
            }else{
                cout << a[i][j] << " - ";
            }

        }
        cout << endl;
    }

    //Rotaciones

    cout << endl<<endl;
    cout << "Matriz Rotada 90" << endl;
    for(int j=0; j<5;j++){
        for(int i=4; i>=0; i--){
            if((a[i][j])>9){
                cout << a[i][j] << "- ";
            }else{
                cout << a[i][j] << " - ";
            }

        }
        cout << endl;
    }
    cout << endl<<endl;
    cout << "Matriz Rotada 180" << endl;
    for(int i=4; i>=0;i--){
        for(int j=4; j>=0; j--){
            if((a[i][j])>9){
                cout << a[i][j] << "- ";
            }else{
                cout << a[i][j] << " - ";
            }

        }
        cout << endl;
    }
    cout << endl<<endl;
    cout << "Matriz Rotada 270" << endl;
    for(int j=4; j>=0;j--){
        for(int i=0; i<5; i++){
            if((a[i][j])>9){
                cout << a[i][j] << "- ";
            }else{
                cout << a[i][j] << " - ";
            }

        }
        cout << endl;
    }
}

void ejercicio_16(){
    int numero;
    cout << "ingrese la dimension de la cuadricula: ";
    cin >> numero;


   //Formula:
    //Numerador --> (A+D)!
    //Denominador-> A!D!
    int numerador = 1;

    //Numerador
    for(int i=1; i<=(numero+numero); i++){
        numerador *= i;
    }

    //Denominador
    int denominador=1;

    //Factorial de A y D
    for(int i=1; i<=numero; i++){
        denominador *= i;
    }


    int resultado = numerador/(denominador*denominador);

    cout << "Para la malla de "<<numero<<"x"<<numero<<" puntos hay "<<resultado<<" caminos"<<endl;


}


void ejercicio_17(){
    int numero_inicio, suma, suma_total=0;
    int numero_auxiliar = 0, contador=0;;

    cout<<"Ingresa un numero: ";
    cin >> numero_inicio;

    try {
        while (numero_inicio!=numero_auxiliar && contador<20) {

            if(contador==0){
                numero_auxiliar = numero_inicio;
                suma = 0;
            }else{
                suma = 0;
            }


            for(int i=1;i<numero_auxiliar ;i++){
                if(numero_auxiliar%i == 0){
                    suma += i;
                }
            }
            if(suma<numero_inicio){
                suma_total += suma;
            }
            numero_auxiliar = suma;
            contador++;
            cout << endl<<numero_auxiliar<<endl;

            if(numero_auxiliar==0){
                break;
            }
        }
        cout << endl<<endl<<"El resultado de la suma es: "<<suma_total<<endl;
    } catch (char error) {
        cout << "Error: ";
    }

}








