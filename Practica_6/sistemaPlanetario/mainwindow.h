#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <cuerpo.h>
#include <cuerpograf.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void actualizar();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    //creamos lo que necesitamos
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scena;
    float dt;
    int contador;
    int h_limit;
    int v_limit;
    QList<Cuerpograf*> bars;
};
#endif // MAINWINDOW_H
