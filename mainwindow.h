#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QList>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

#include "objetos.h"
#include "bloque.h"
#include "comida.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *teclas);//para las teclas del teclado
    ~MainWindow();
    bool colision();
    void comer();
    void pacman();
    void fantasmas();//todavia falta que cambie de cara

    void fantasmamove(/*int posx, int posy*/);
    char voltear(char posicion);

    public slots://la utilizamos para el Qtimer
    void mover();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    objetos *enemigo;
    bloque *muro;
    comida *bolita;
    //QString h;
    QList<bloque*>bloques;
    QList<comida*>bolitas; //listas que me almacenan los bloques y bolitas
    int ganaste;
    int ganaste1;
    void our_focus(QGraphicsItem *item);

    //hacemos el puntero personaje 4 pos,arriba,abajo,derecha,izquierda
    int ancho_sprite=20,alto_sprite=20;
    int const arriba=0,abajo=1,derecha=2,izquierda=3,base=4;
    objetos *movimiento;//este se va a encargar de moverse entre los punteros personaje
    //y cambiar de imagen respectivamente
    objetos *personaje[5];
    //agregamos un char que sera el que indicara a que direcion se mueve de manera const el pacman
    char x_o_y;
    QTimer *tiempo;
    objetos *enemigos[6];//0=fantasma verde,1=f Rosa,2=F rojo,3= F naranja, 4=ojos,5=fantasma comesetible

};
#endif // MAINWINDOW_H
