#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <particula.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnSimular_clicked();
    void Mover();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QTimer *timer;
    Particula *cuerpo;
    QList<Particula*> Particulas;

};

#endif // MAINWINDOW_H
