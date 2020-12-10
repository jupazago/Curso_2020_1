#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena= new QGraphicsScene(this);
    escena->setSceneRect(0,-300,370,300);
    escena->addRect(escena->sceneRect());
    ui->graphicsView->setScene(escena);
    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSimular_clicked()
{
    //cuerpo = new Particula(x,y,vx,vy,m);
    Particulas.push_back(new Particula(0, -7000, 2, 0, 70));
    escena->addItem(Particulas.back());
    timer->start(5);
}

void MainWindow::Mover()
{
    QList<Particula*>::iterator it;
    for(it=Particulas.begin();it!=Particulas.end();it++)
       (*it)->ActualizarPosicion();
}
