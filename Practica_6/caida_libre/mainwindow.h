#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <particula.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>

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
    void on_btnSimular_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QTimer *timer;
    Particula *cuerpo;
};
#endif // MAINWINDOW_H
