#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //timer
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(funcion()));
    connect(timer2, SIGNAL(timeout()),this, SLOT(moviminentosEnemigos()));
    timer->start(1000);
    timer2->start(50);

    scene= new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    //-x -y para estar en el centro de la escena
    scene->setSceneRect(0,0,780,480);
    scene->backgroundBrush();
    ui->graphicsView->setBackgroundBrush(QPixmap(":/imagenes/fondo_pacman.jpg"));

    //Agregamos el pacman
    objCuerpo = new Cuerpo(15,40,40);
    scene->addItem(objCuerpo);


    //Pared
    paredes = *new QList<Pared *>();


    QFile archivo("../coordenadas_paredes.txt");  //Puedo crear el flujo lectura desde un archivo
    if(!archivo.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"¡Informacion!", "No se puede leer el archivo txt");
    }

    QTextStream in(&archivo);
    QString valor;
    while(!in.atEnd()){ //mientras no sea el final del archivo
        valor = in.readLine();
        int paredX = valor.toInt();
        valor = in.readLine();
        int paredY = valor.toInt();
        valor = in.readLine();
        int paredW = valor.toInt();
        valor = in.readLine();
        int paredH = valor.toInt();
        //                   x-y-ancho-alto
        pared = new Pared( paredX, paredY, paredW, paredH);
        paredes.push_back(pared);
        scene->addItem(paredes.back());
    }

    //  COMIDA
    galletas = *new QList<Comida *>();
    int px =    40;
    int py =    40;
    int radio = 7;

    for(int i= 0;i<13; i++){
        for (int j=0;j<7;j++) {
            objComida = new Comida(radio, px, py);
            galletas.push_back(objComida);
            scene->addItem(galletas.back());
            py+=66;
        }
        px+=58;
        py=40;
    }



    //  FANTASMAS
    fantasmas = *new QList<Fantasma *>();

    fantasmal1 = new Fantasma(15,360,270);
    fantasmas.push_back(fantasmal1);
    scene->addItem(fantasmas.back());

    fantasmal2 = new Fantasma(15,60,440);
    fantasmas.push_back(fantasmal2);
    scene->addItem(fantasmas.back());

    fantasmal3 = new Fantasma(15,730,410);
    fantasmas.push_back(fantasmal3);
    scene->addItem(fantasmas.back());

}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{



    if(evento->key()==Qt::Key_A){
        objCuerpo->MoveLeft();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(objCuerpo->collidesWithItem(*p)){
                objCuerpo->MoveRight();
                objCuerpo->rotarUp();


            }
        }
        for (auto i=galletas.begin(); i!=galletas.end(); i++) {
            if(objCuerpo->collidesWithItem(*i)){
                choca=true;
                scene->removeItem(*i);
                galletas.erase(i);
                break;
            }
        }
        for (auto g=fantasmas.begin(); g!=fantasmas.end(); g++) {
            if(objCuerpo->collidesWithItem(*g)){
                perdiste=true;

            }
        }

    }else if(evento->key()==Qt::Key_D){
        objCuerpo->MoveRight();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(objCuerpo->collidesWithItem(*p)){
                objCuerpo->MoveLeft();
            }
        }
        for (auto i=galletas.begin(); i!=galletas.end(); i++) {
            if(objCuerpo->collidesWithItem(*i)){
                choca=true;
                scene->removeItem(*i);
                galletas.erase(i);
                break;
            }
        }
        for (auto g=fantasmas.begin(); g!=fantasmas.end(); g++) {
            if(objCuerpo->collidesWithItem(*g)){
                perdiste=true;

            }
        }


    }else if(evento->key()==Qt::Key_W){
        objCuerpo->MoveUp();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(objCuerpo->collidesWithItem(*p)){
                objCuerpo->MoveDown();
            }
        }
        for (auto i=galletas.begin(); i!=galletas.end(); i++) {
            if(objCuerpo->collidesWithItem(*i)){
                choca=true;
                scene->removeItem(*i);
                galletas.erase(i);
                break;
            }
        }
        for (auto g=fantasmas.begin(); g!=fantasmas.end(); g++) {
            if(objCuerpo->collidesWithItem(*g)){
                perdiste=true;

            }
        }


    }else if(evento->key()==Qt::Key_S){
        objCuerpo->MoveDown();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(objCuerpo->collidesWithItem(*p)){
                objCuerpo->MoveUp();
            }
        }
        for (auto i=galletas.begin(); i!=galletas.end(); i++) {
            if(objCuerpo->collidesWithItem(*i)){
                choca=true;
                scene->removeItem(*i);
                galletas.erase(i);
                break;
            }
        }
        for (auto g=fantasmas.begin(); g!=fantasmas.end(); g++) {
            if(objCuerpo->collidesWithItem(*g)){
                perdiste=true;

            }
        }

    }

    //Mostrar puntaje
    QString s = QString::number(*puntaje);
    ui->lblPuntaje->setText(s);

    //  Verificacion de puntaje
    if(*puntaje==91){
        timer->stop();
        QMessageBox::information(this,"¡HAS GANADO!", "Puntuación Perfecta");
        //QMessageBox::critical(this,"¡HAS GANADO!", "Puntuación Perfecta");
    }

    //Contador de puntaje
    if(choca==true){
        choca=false;
        *puntaje+=1;
        qDebug()<<*puntaje;
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::funcion()
{

    //Mostrar puntaje
    QString tiempito = QString::number(*reloj);
    ui->lblReloj->setText(tiempito);

    r++; //variable principal para almacenar los segundos

    /* //Reloj digital
    QTime time = QTime::currentTime();
    QString time_texto = time.toString("hh : mm : ss");
    //ui->lblReloj.setText(time_texto);
    ui->lblPuntaje_2->setText((time_texto));
    */
}

void MainWindow::moviminentosEnemigos()
{

    if(contador>400 || contador<0){
        contador=1;
    }else if(contador>0 && contador<100){
        fantasmal1->MoveUp();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal1->collidesWithItem(*p)){
                fantasmal1->MoveDown();
                fantasmal2->MoveDown();
                if(movLateral==1){
                    contador+=200;
                    movLateral=2;
                }else{
                    contador+=300;
                    movLateral=1;
                }

            }
        }
        if(fantasmal1->collidesWithItem(objCuerpo)){
            perdiste=true;
        }


    }else if (contador>100 && contador <200) {
        fantasmal1->MoveDown();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal1->collidesWithItem(*p)){
                fantasmal1->MoveUp();
                if(movLateral==1){
                    contador+=200;
                    movLateral=2;
                }else{
                    contador+=100;
                    movLateral=1;
                }
            }
        }
        if(fantasmal1->collidesWithItem(objCuerpo)){
            perdiste=true;
        }


    }else if (contador>200 && contador<300) {
        fantasmal1->MoveLeft();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal1->collidesWithItem(*p)){
                fantasmal1->MoveRight();
                if(movAltura==1){
                    contador-=200;
                    movAltura=2;
                }else{
                    contador-=100;
                    movAltura=1;
                }
            }
        }
        if(fantasmal1->collidesWithItem(objCuerpo)){
            perdiste=true;
        }

    }else if (contador>300 && contador<400) {
        fantasmal1->MoveRight();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal1->collidesWithItem(*p)){
                fantasmal1->MoveLeft();
                if(movAltura==1){
                    contador-=300;
                    movAltura=2;
                }else{
                    contador-=200;
                    movAltura=1;
                }
            }
        }
        if(fantasmal1->collidesWithItem(objCuerpo)){
            perdiste=true;
        }
    }


    if(contador2>800 || contador2<0){
        contador2=1;
    }else if(contador2>0 && contador2<200){
        fantasmal2->MoveUp();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal2->collidesWithItem(*p)){
                fantasmal2->MoveDown();
                if(movLateral2==1){
                    contador2+=200;
                    movLateral2=2;
                }else{
                    contador2+=300;
                    movLateral2=1;
                }

            }
        }
        if(fantasmal2->collidesWithItem(objCuerpo)){
            perdiste=true;
        }

    }else if (contador2>200 && contador2 <400) {
        fantasmal2->MoveDown();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal2->collidesWithItem(*p)){
                fantasmal2->MoveUp();
                if(movLateral2==1){
                    contador2+=400;
                    movLateral2=2;
                }else{
                    contador2+=200;
                    movLateral2=1;
                }
            }

        }
        if(fantasmal2->collidesWithItem(objCuerpo)){
            perdiste=true;
        }


    }else if (contador2>400 && contador2<600) {
        fantasmal2->MoveLeft();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal2->collidesWithItem(*p)){
                fantasmal2->MoveRight();
                if(movAltura2==1){
                    contador2-=300;
                    movAltura2=2;
                }else{
                    contador2-=200;
                    movAltura2=1;
                }
            }

        }
        if(fantasmal2->collidesWithItem(objCuerpo)){
            perdiste=true;
        }

    }else if (contador2>600 && contador2<800) {
        fantasmal2->MoveRight();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal2->collidesWithItem(*p)){
                fantasmal2->MoveLeft();
                if(movAltura2==1){
                    contador2-=400;
                    movAltura2=2;
                }else{
                    contador2-=600;
                    movAltura2=1;
                }
            }

        }
        if(fantasmal2->collidesWithItem(objCuerpo)){
            perdiste=true;
        }
    }
    if(contador3>800 || contador3<0){
        contador3=1;
    }else if(contador3>0 && contador3<200){
        fantasmal3->MoveUp();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal3->collidesWithItem(*p)){
                fantasmal3->MoveDown();
                if(movLateral3==1){
                    contador3+=200;
                    movLateral3=2;
                }else{
                    contador3+=300;
                    movLateral3=1;
                }

            }
        }
        if(fantasmal3->collidesWithItem(objCuerpo)){
            perdiste=true;
        }

    }else if (contador3>200 && contador3 <400) {
        fantasmal3->MoveDown();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal3->collidesWithItem(*p)){
                fantasmal3->MoveUp();
                if(movLateral3==1){
                    contador3+=400;
                    movLateral3=2;
                }else{
                    contador3+=200;
                    movLateral3=1;
                }
            }

        }
        if(fantasmal3->collidesWithItem(objCuerpo)){
            perdiste=true;
        }


    }else if (contador3>400 && contador3<600) {
        fantasmal3->MoveLeft();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal3->collidesWithItem(*p)){
                fantasmal3->MoveRight();
                if(movAltura3==1){
                    contador3-=300;
                    movAltura3=2;
                }else{
                    contador3-=200;
                    movAltura3=1;
                }
            }

        }
        if(fantasmal3->collidesWithItem(objCuerpo)){
            perdiste=true;
        }

    }else if (contador3>600 && contador3<800) {
        fantasmal3->MoveRight();
        for (auto p=paredes.begin(); p!=paredes.end(); p++) {
            if(fantasmal3->collidesWithItem(*p)){
                fantasmal3->MoveLeft();
                if(movAltura3==1){
                    contador3-=400;
                    movAltura3=2;
                }else{
                    contador3-=600;
                    movAltura3=1;
                }
            }

        }
        if(fantasmal3->collidesWithItem(objCuerpo)){
            perdiste=true;
        }
    }
    contador+=2;
    contador2+=2;
    contador3+=2;

    if(perdiste==true){
        timer->stop();
        QMessageBox::critical(this,"¡Perdiste!", "Perdiste la partida");
        QApplication::quit();
    }


}

