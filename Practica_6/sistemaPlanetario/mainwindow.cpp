#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>  //Mensaje
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h_limit = 2000;
    v_limit = 1000;
    dt = 1;

    timer = new QTimer(this);
    scena = new QGraphicsScene(this);
    scena->setSceneRect(-h_limit/2, -v_limit/2, h_limit, v_limit); // punto medio
    ui->graphicsView->setScene(scena);
    ui->centralwidget->adjustSize();    //ajustar al tamanio

    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));

        /*                      // posx posy vx vy masa radio
    bars.append(new Cuerpograf(0,0,0,0,70000,300));
    bars.append(new Cuerpograf(0,-7000,2,0,70,120));
    //bars.append(new Cuerpograf(0,-500,0,0,70,120));
    bars.append(new Cuerpograf(4000,5000,-1.6,1.2,25,100));
    bars.append(new Cuerpograf(-5000,0,0,-2,70,70));

    scena->addItem(new Cuerpograf(0,0,0,0,7000,300));
    scena->addItem(new Cuerpograf(0,-7000,2,0,70,120));
    scena->addItem(new Cuerpograf(4000,5000,-1.6,1.2,25,100));
    scena->addItem(new Cuerpograf(-5000,0,0,-2,70,70));

    for (int i=0; i<bars.size(); i++) {
        bars.at(i)->actualizar(dt);
        scena->addItem(bars.at(i));
    }
    */
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scena;
}

void MainWindow::actualizar()
{


    if(contador<=1000 && bars.size()==3){
        QFile archivo("../coordenadas_Simulacion3.txt");  //Puedo crear el flujo lectura desde un archivo
        if(!archivo.open(QIODevice::WriteOnly | QIODevice::Append)){
            QMessageBox::critical(this,"¡Informacion!", "No se puede leer el archivo txt 3");
        }
        QTextStream out(&archivo);
        out <<bars.at(0)->getEsf()->getPX()<<"          "<<bars.at(0)->getEsf()->getPY()<<"          ";
        out <<bars.at(1)->getEsf()->getPX()<<"          "<<bars.at(1)->getEsf()->getPY()<<"          ";
        out <<bars.at(2)->getEsf()->getPX()<<"          "<<bars.at(2)->getEsf()->getPY()<<"          ";
        out <<"\n";

    }else if(contador<=1000 && bars.size()==5){
        QFile archivo("../coordenadas_Simulacion5.txt");  //Puedo crear el flujo lectura desde un archivo
        if(!archivo.open(QIODevice::WriteOnly | QIODevice::Append)){
            QMessageBox::critical(this,"¡Informacion!", "No se puede leer el archivo txt 5");
        }
        QTextStream out(&archivo);
        out <<bars.at(0)->getEsf()->getPX()<<"          "<<bars.at(0)->getEsf()->getPY()<<"          ";
        out <<bars.at(1)->getEsf()->getPX()<<"          "<<bars.at(1)->getEsf()->getPY()<<"          ";
        out <<bars.at(2)->getEsf()->getPX()<<"          "<<bars.at(2)->getEsf()->getPY()<<"          ";
        out <<bars.at(3)->getEsf()->getPX()<<"          "<<bars.at(3)->getEsf()->getPY()<<"          ";
        out <<bars.at(4)->getEsf()->getPX()<<"          "<<bars.at(4)->getEsf()->getPY()<<"          ";
        out <<"\n";
    }

    contador++;
    for(int i=0; i<bars.size(); i++) {
        for(int j=0; j<bars.size(); j++) {
            if(i != j){
                //hallar aceleracion
                bars.at(i)->getEsf()->acelerar(bars.at(j)->getEsf()->getPX(), bars.at(j)->getEsf()->getPY(), bars.at(j)->getEsf()->getMasa());
                //actualizar posicion
                bars.at(i)->actualizar(dt);

            }
        }
    }
    //Colisiones
    for(int i=0; i<bars.size(); i++) {
        for(int j=0; j<bars.size(); j++) {
            if(i != j && bars.at(i)->collidesWithItem(bars.at(j))){
                scena->removeItem(bars.at(i));
                scena->removeItem(bars.at(j));
                bars.removeAt(i);
                bars.removeAt(i);
                continue;
            }
        }
    }



}

//simulacion de 3
void MainWindow::on_pushButton_clicked()
{
        //                 // posx posy vx vy masa radio
    bars.append(new Cuerpograf(0,-7000,2,0,70,120));
    bars.append(new Cuerpograf(0,0,0,0,70000,300));
    bars.append(new Cuerpograf(4000,5000,-1.6,1.2,25,100));
    for (int i=0; i<bars.size(); i++) {
        bars.at(i)->actualizar(dt);
        scena->addItem(bars.at(i));
    }
    timer->start(dt);

}
//Personalizada
void MainWindow::on_pushButton_2_clicked()
{
    double A[6]={ui->A1->value(),
                ui->A2->value(),
                ui->A3->value(),
                ui->A4->value(),
                ui->A5->value(),
                ui->A6->value()};

    float B[6]={static_cast<float>(ui->B1->value()),
                static_cast<float>(ui->B2->value()),
                static_cast<float>(ui->B3->value()),
                static_cast<float>(ui->B4->value()),
                static_cast<float>(ui->B5->value()),
                static_cast<float>(ui->B6->value())};

    float C[6]={static_cast<float>(ui->C1->value()),
                static_cast<float>(ui->C2->value()),
                static_cast<float>(ui->C3->value()),
                static_cast<float>(ui->C4->value()),
                static_cast<float>(ui->C5->value()),
                static_cast<float>(ui->C6->value())};

    float D[6]={static_cast<float>(ui->D1->value()),
                static_cast<float>(ui->D2->value()),
                static_cast<float>(ui->D3->value()),
                static_cast<float>(ui->D4->value()),
                static_cast<float>(ui->D5->value()),
                static_cast<float>(ui->D6->value())};

    float E[6]={static_cast<float>(ui->E1->value()),
                static_cast<float>(ui->E2->value()),
                static_cast<float>(ui->E3->value()),
                static_cast<float>(ui->E4->value()),
                static_cast<float>(ui->E5->value()),
                static_cast<float>(ui->E6->value())};
    if(A[2] != 0){
        bars.append(new Cuerpograf(A[0],A[1],A[2],A[3],A[4],A[5]));
    }
    if(B[2] != 0){
        bars.append(new Cuerpograf(B[0],B[1],B[2],B[3],B[4],B[5]));
    }
    if(C[2] != 0){
        bars.append(new Cuerpograf(C[0],C[1],C[2],C[3],C[4],C[5]));
    }
    if(D[2] != 0){
        bars.append(new Cuerpograf(D[0],D[1],D[2],D[3],D[4],D[5]));
    }
    if(E[2] != 0){
        bars.append(new Cuerpograf(E[0],E[1],E[2],E[3],E[4],E[5]));
    }

    for (int i=0; i<bars.size(); i++) {
        bars.at(i)->actualizar(dt);
        scena->addItem(bars.at(i));
    }
    timer->start(dt);
}
//Simulacion de 5
void MainWindow::on_pushButton_3_clicked()
{
                        // posx posy vx vy masa radio
    bars.append(new Cuerpograf(0,0,0,0,50000,200));
    bars.append(new Cuerpograf(-5000,0,0,-2,50,70));
    bars.append(new Cuerpograf(5000,0,0,2,70,70));
    bars.append(new Cuerpograf(0,-5000,2,0,70,70));
    bars.append(new Cuerpograf(0,5000,-2,0,70,70));
    for (int i=0; i<bars.size(); i++) {
        bars.at(i)->actualizar(dt);
        scena->addItem(bars.at(i));
    }
    timer->start(dt);
}

void MainWindow::on_pushButton_4_clicked()
{
    for(int i=0; i<bars.size(); i++) {
        scena->removeItem(bars.at(i));
        bars.removeAt(i);
    }
    timer->stop();
}
