#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

#include "objetos.h"
#include "personaje.h"
#include "control_maestro.h"

namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//declaramos de manera antisipada la clase personaje:
class personaje;
class control_maestro;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void tamaño_de_la_escena(int x_inc, int y_inc, int ancho, int largo);
    void agg_a_escena(objetos *item);
    void dll_de_escena(objetos *item);
    void actualizar_escena();
    ~MainWindow();
    QGraphicsScene* getEscena();
    Ui::MainWindow* getUI();

protected:
    void keyPressEvent(QKeyEvent* event);
private:
    control_maestro* control_maestro_p;
    Ui::MainWindow *ui;
    QGraphicsScene *escena;



};
#endif // MAINWINDOW_H
