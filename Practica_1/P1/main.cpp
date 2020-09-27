#include <iostream>

using namespace std;

void ejercicio_1();
void ejercicio_3();
void ejercicio_5();
void ejercicio_7();
void ejercicio_8();
void ejercicio_10();
void ejercicio_12();
void ejercicio_13();
void ejercicio_15();
void ejercicio_17();

int Sumar_multiplos(int numero, int limite);
int es_primo(int i); //funcion para los numeros primos
float raizC(float m);//funcion para la raiz cuadrada de un numero

int main()
{
    int valor = 1;

    cout << "*******************************"<<endl;
    cout << "******** Laboratorio 1 ********"<<endl;
    cout << "*******************************"<<endl<<endl;

    cout << "seleccione un ejercicio: ";
    cin >> valor;

    while (valor!=0) {
        switch(valor) {
            case 1: puts("Se ha pulsado el Ejercicio 1 \n");
                ejercicio_1();
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

            case 8: puts("Se ha pulsado el Ejercicio 8 \n");
                ejercicio_8();
                break;

            case 10: puts("Se ha pulsado el Ejercicio 10 \n");
                ejercicio_10();
                break;

            case 12: puts("Se ha pulsado el Ejercicio 12 \n");
                ejercicio_12();
                break;

            case 13: puts("Se ha pulsado el Ejercicio 13 \n");
                ejercicio_13();
                break;

            case 15: puts("Se ha pulsado el Ejercicio 15 \n");
                ejercicio_15();
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

void ejercicio_1(){
    /*
     * Escriba un programa que identique si un carácter ingresado es una vocal,
     * una consonante o ninguna de las 2 e imprima un mensaje según el caso.
     *
    */
    try {
        char caracter;
        cout << "********* Ejercicio 1 *********"<<endl<<endl;
        cout << "Ingrese un caracter"<<endl;
        cin >> caracter;

        //Todo el proceso es verificando el caracter en ascii
        if((caracter>64 && caracter<91) || (caracter>96 && caracter<123)){
            //Es una letra
            //Verificamos si es una vocal mayuscula o minuscula
            //de lo contrario es una consonante
            if(caracter == 65 || caracter == 69 ||caracter == 73 ||caracter == 79 ||caracter == 85){
                cout << "Es una vocal mayuscula"<<endl;

            }else if(caracter == (65+32) || caracter == (69+32) ||caracter == (73+32) ||caracter == (79+32) ||caracter == (85+32)){
                cout << "Es una vocal minuscula"<<endl;

            }else{
                cout << "Es una consonante"<<endl;
            }
        }else{
            cout << "No es una letra"<<endl<<endl;
        }


    }catch (char capturador) {
        cout << "Error: ";
    }
}

void ejercicio_3(){
    /* Escriba un programa que debe leer un mes y un día de dicho mes para luego decir
    si esa combinación de mes y día son válidos. El caso más especial es el 29 de febrero,
    en dicho caso imprimir posiblemente año bisiesto
    */
    try {
        cout << "********* Ejercicio 3 *********"<<endl<<endl;
        int mes, dia;

        cout << "Introducir mes: " ;
        cin >> mes;
        cout << "Introducir dia: " ;
        cin >> dia;
        if(mes<1 || mes>12 ){
            cout << mes << " es un mes invalido \n";
        } else if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
            if(dia>0 && dia<32){
                cout << dia << "/" << mes << " es una fecha valida. \n";
            }
        } else if(mes==4 || mes==6 || mes==9 || mes==11){
            if(dia>0 && dia<31){
                cout << dia << "/" << mes << " es una fecha valida. \n";
            }else{
                cout << dia << "/" << mes << " es una fecha invalida. \n";
            }
        }else{
            if(dia>0 && dia<30){
                cout << dia << "/" << mes << " es valida en bisiesto. \n";
            }
        }

    }catch (char capturador) {
        cout << "Error: ";
    }
}
void ejercicio_5(){
    /*Escriba un programa que muestre el siguiente patrón en la pantalla:
                       *
                      ***
                     *****
                    *******
                     ******
                      ***
                       *

    El tamaño del patrón estará determinado un número entero impar que ingrese el usuario. En el
    ejemplo mostrado, el tamaño de la gura es 7.
    */
    try {
        cout << "********* Ejercicio 5 *********"<<endl<<endl;
        int numero_imp, x, k;
        cout << "Introducir numero impar ";
        cin >> numero_imp;
        if(numero_imp%2 == 0){
            throw '1';          //Capturamos la excepcion
        }

        for(int i=1; i<=numero_imp; i=i+2){
            for(x=(numero_imp-i); x>=1; x=x-2){
                cout << " ";
            }
            for(int j=1; j<= i; j++){
                cout << "*";
            }
            for(k=(numero_imp-i); k>=1; k=k-2){
                cout << " ";
            }
            cout << "\n";
        }
        for(int i=(numero_imp-2); i>=1; i=i-2){
            for(x=(numero_imp-i); x>=1; x=x-2){
                cout << " ";
            }
            for(int j=1; j<= i; j++){
                cout << "*";
            }
            for(k=(numero_imp-i); k>=1; k=k-2){
                cout << " ";
            }
            cout << "\n";
        }



    }catch (char capturador) {
        cout << "Error: ";
        if(capturador=='1'){
            cout << "Numero no es impar"<<endl;
        }
    }
}

void ejercicio_7(){
    /* En la serie de Fibonacci, cada número es la suma de los 2 anteriores e inicia con 1 y
       Ej: 1, 1, 2, 3, 5, 8, ....
    Escriba un programa que reciba un número n y halle la suma de todos los números pares en la serie
    de Fibonacci menores a n.
    */
    try {
        cout << "********* Ejercicio 7 *********"<<endl<<endl;
        int n_serie, fibo_1, fibo_2, suma_fibo;
        fibo_1 = 1, fibo_2 = 1, suma_fibo = 0;

        cout << "ingrese un numero mayor a 1: ";
        cin >> n_serie;

        //Capturamos la excepción
        if(n_serie<2){
            throw '1';
        }

        //Procedimiento de la serie
        while (n_serie > 0) {
            for(int i=2; i<=n_serie; i++){
                if(fibo_2>=n_serie){
                    n_serie = 0;
                    break;
                }
                fibo_2 = fibo_1 + fibo_2;
                fibo_1 = fibo_2 - fibo_1;

                //Sumamos todos los numeros pares de la serie
                if((fibo_2%2)==0){
                    suma_fibo = suma_fibo + fibo_2;
                }
            }
        }
        cout << endl << "es resultado de la suma es: " << suma_fibo << endl;



    }catch (char capturador) {
        cout << "Error: ";
        if(capturador=='1'){
            cout << "Numero no es mayor a 1"<<endl;
        }
    }
}

void ejercicio_8(){
    /* Escriba un programa que reciba 3 números a, b, c, y calcule la suma de todos los
    múltiplos de a y b que sean menores a c. Tenga en cuenta no sumar 2 veces los múltiplos comunes.
    Ej: para a=3, b=5 y c=10. Se sumarían 3+6+9+5=23
    Para a=5, b=7 y c=36. Se sumarían 5+10+15+20+25+30+35+7+14+21+28 = 210.
    Nota: el formato de salida debe ser:
    m11 + m12 + m13 + . . . + m21 + m22 + m23. . . = sumatoria.
    m11 representa el primer múltiplo de a y así sucesivamente. m21 representa el primer múltiplo de b
    y así sucesivamente.
    */
    try {
        cout << "********* Ejercicio 8 *********"<<endl<<endl;

        int a,b,c, total=0;

        cout << "Ingrese el valor de A:";
        cin >> a;
        cout << "Ingrese el valor de B:";
        cin >> b;
        cout << "Ingrese el valor de C:";
        cin >> c;

        if(a<c && b<c){
            total += Sumar_multiplos(a,c);
            //cout <<total<<endl<<endl;
            total += Sumar_multiplos(b,c);
            //cout <<total<<endl<<endl;

            int multiplicador=1;

            while ((a*b*multiplicador)<c) {
                total -= a*b*multiplicador;
                multiplicador++;
            }

        }else if(a>c){
            total += Sumar_multiplos(b,c);

        }else if(b>c){
            total += Sumar_multiplos(a,c);

        }else{
            throw '1';
        }
        cout << " = "<<total<<endl<<endl;
    }catch (char capturador) {
        cout << "Error: ";
        if(capturador=='1'){
            cout << "El numero A y B son mayores que el numero C"<<endl;
        }

    }
}

void ejercicio_10(){
    /* Escriba un programa que reciba un número n e imprima el enésimo número primo.
    Ej: Si recibe 4 el programa debe imprimir 7.
    Nota: la salida del programa debe ser: El primo numero 4 es: 7.
    */
    try {
        cout << "********* Ejercicio 10 *********"<<endl<<endl;
        int num_primo, n;
        num_primo = 0;
        cout << "dime el n-esimo termino de los numeros primos: ";
        cin >> n;
        for(int i=2; i>0; i++){
            if(es_primo(i)==1){
                num_primo++;
                if(num_primo==n){
                    cout << "el primo numero " << n << " es "  << i << endl;
                    break;
                }
            }
        }

    }catch (char capturador) {
        cout << "Error: ";

    }
}

void ejercicio_12(){
    /*
    Escriba un programa que calcula el máximo factor primo de un número.
    Ej: Si se recibe 33 el programa debe imprimir 11.
    Nota: la salida del programa debe ser: El mayor factor primo de 33 es: 11.
    */
    try {
        cout << "********* Ejercicio 12 *********"<<endl<<endl;

        int numero, maximo = 0;
        int nu_primo = 0;

        cout << "Ingrese un numero: ";
        cin >> numero;
        cout << endl<<endl;

        for(int i=2; i>0; i++){
            if(es_primo(i)==1){
                nu_primo++;

                //Cuando finaliza la vusqueda
                if(i>numero){
                    cout << "El mayor factor primo de "<< numero<<" es: "  << maximo<< endl;
                    break;
                }

                //Se evalua constantemente el multiplo del numero primo
                if(numero>nu_primo){
                    if(numero%nu_primo ==0){
                        //cout << "XD"<<endl;
                        maximo = nu_primo;
                    }
                    //El Numero primo es i
                }
            }
        }



    }catch (char capturador) {
        cout << "Error: ";

    }
}

void ejercicio_13(){
    /* Escriba un programa que reciba un número y calcule la suma de todos los primos
    menores que el número ingresado.
    Ej: Si se recibe 10 el programa debe imprimir 17.
    Nota: la salida del programa debe ser: El resultado de la suma es: 17.
    */
    try {
        cout << "********* Ejercicio 13 *********"<<endl<<endl;
        int nu_primo, m, sumar_primo;
        sumar_primo = 0;
        nu_primo = 0;
        cout << "Ingrese un numero para sumar los numeros primos antes de ese: ";
        cin >> m;
        for(int i=2; i>0; i++){
            if(es_primo(i)==1){
                nu_primo++;
                if(i>m){
                    cout << "el reultado de la suma es: " << sumar_primo << endl;
                    break;
                }
                if(m>nu_primo){
                    sumar_primo = sumar_primo + i;
                    //El Numero primo es i
                }
            }
        }

    }catch (char capturador) {
        cout << "Error:";

    }
}

void ejercicio_15(){
    try {
        cout << "********* Ejercicio 15 *********"<<endl<<endl;
        int nume, suma_diagonal, espacio, pasos;
        espacio=0;
        pasos=0;
        suma_diagonal = 0;
        cout << "Ingrese un numero impar: ";
        cin >> nume;

        if((nume%2)!=0){
            for(int i=1; i<=(nume*nume); i+=2){
                suma_diagonal += i;
                //cout << i << "con espacio" << espacio << endl;
                //cout << i << endl;
                if(espacio==4){
                    espacio=1;
                    pasos += 2;
                }else{
                    espacio += 1;
                }
                i+=pasos;
            }
        } else{
            throw '1';
        }
        cout << "Es un espiral "<<nume<< "x"<< nume<<", la suma es: " << suma_diagonal << endl;

    }catch (char capturador) {
        cout << "Error: ";
        if(capturador=='1'){
            cout << "No es numero impar";
        }
    }
}

void ejercicio_17(){
    try {
        cout << "********* Ejercicio 17 *********"<<endl<<endl;

        int numero, igual;

        cout << "Ingrese un numero: ";
        cin >> numero;

        if(numero==1){

        }else if (numero>1){
            //Secuencia triangular sin la formula n*(n+1)/2.
            //solo para imprimir en pantalla y comprobar el proceso

            for(int i=1;i<=numero;i++){
                if(i==1){
                    i++;
                    igual = 1;
                }
                cout << i << " + " << igual<<" = "<<i+igual<<endl;
                igual += i;

            }

            cout << "-*-*-*-*-*-*--*-"<<endl;
            //usamos la formular esta vez
            //int numero_n = igual;
            int numero_n = numero*(numero+1)/2;
            cout << "El "<<numero<<" numero triangular es: "<< numero_n << endl;

            //Buscamos sus multiplos
            cout << numero_n<<": ";
            int contador=0;
            for(int i=1;i<=numero_n; i++){
                if(numero_n%i == 0){
                    cout <<i<<", ";
                    contador++;
                }
            }
            cout <<endl;
            cout << "Posee "<< contador-1 <<" Divisores diferentes de 1"<< endl;

        }else{
            throw '1';
        }


    }catch (char capturador) {
        cout << "Error: ";
        if(capturador=='1'){
            cout << "El numero debe ser mayor a 1";
        }
    }
}

//Función de los numeros primos
int es_primo (int i){
/* Se recibe una variable de tipo Entero para evaluarse si es o nó un número primo
*  Se evalua en el condicional si el numero recibido es 2 ó 3, si no es así,
*  en el Else se se hace su respectivo proceso para verificar si es un numero primo
*/
    int j;
    double x;
    if(i%2==0){
        if(i==2)return 1;
        else return 0;
    }
    else{
        x=raizC(i);
        j=3;
        while(j<=x && (i%j)!=0)
        j=j+2;
        if(j>x) return 1;
        else return 0;
    }
}

float raizC(float m){
    float i=0;
    float x1,x2;
    while( (i*i) <= m )
            i+=0.1;
    x1=i;
    for(int j=0;j<10;j++)
    {
        x2=m;
        x2/=x1;
        x2+=x1;
        x2/=2;
        x1=x2;
    }

    return x2;
}
int Sumar_multiplos(int numero, int limite){
    int arreglo[limite];
    int encontrado=0;
    int suma=0;

    for(int i=1; i<=limite; i++){
        if((numero*i)<=limite){
            encontrado=i;
            arreglo[i]= numero*i;
        }
    }
    for(int i=1; i<=encontrado; i++){
        if(i<=encontrado){
            cout << arreglo[i] << " ";
            suma += arreglo[i];
        }else{
            arreglo[i]=0;
        }

    }
    //cout << suma<<" del #: "<<numero<<endl;
    return suma;
}
