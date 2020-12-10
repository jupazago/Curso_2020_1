#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    escena->setSceneRect( 0, -300, 370, 300);
    escena->addRect(escena->sceneRect());
    ui->graphicsView->setScene(escena);
    timer = new QTimer;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnSimular_clicked()
{
    double x =ui->LE_Posx->text().toDouble();
    double y =ui->LE_Posy->text().toDouble();
    double v =ui->LE_vel->text().toDouble();
    double a =ui->LE_Angulo->text().toDouble();

    //angulo a radianes
    a = (a*3.14159)/180;
    cuerpo = new Particula(x,y,v,a);
    escena->addItem(cuerpo);
}
