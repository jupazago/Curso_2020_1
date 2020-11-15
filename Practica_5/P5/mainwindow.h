#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <cuerpo.h>
#include <fantasma.h>
#include <pared.h>
#include <comida.h>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QList>
#include <QDebug>       //mensaje secundario
#include <iterator>
#include <QLabel>
#include <QMessageBox>  //Mensaje
#include <QString>      //Mostrar en pantalla
#include <QTimer>       //tiempo
#include <QDateTime>    //tiempo 2
#include <fstream>      //eof


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void funcion();
    void moviminentosEnemigos();

private:
    Ui::MainWindow *ui;

    //ifstream *fileRead_texto;
    QString *nombre_archivo;

    QTimer *timer;
    QTimer *timer2;

    Cuerpo *objCuerpo;

    Pared *paredSup;
    Pared *paredInf;
    Pared *paredIzq;
    Pared *paredDer;
    Pared *pared;

    Fantasma *fantasmal1, *fantasmal2, *fantasmal3;

    Comida *objComida;

    QList<Comida *> galletax;
    QList<Pared *> paredes;
    QList<Comida *> galletas;
    QList<Fantasma *> fantasmas;

    bool choca=false;

    //Puntaje
    int p=0;
    int *puntaje=&p;

    //Tiempo
    int r=0;
    int *reloj=&r;

    //tiempos -> movimientos enemigos
    int contador=1;
    int contador2=1;
    int contador3=1;

    int movLateral=1;
    int movAltura=1;

    int movLateral2=1;
    int movAltura2=1;

    int movLateral3=1;
    int movAltura3=1;

    //

    bool perdiste=false;

    QGraphicsScene *scene;

    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H
