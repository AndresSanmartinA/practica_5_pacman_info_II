#ifndef CONTROL_MAESTRO_H
#define CONTROL_MAESTRO_H

#define n_arriba 0
#define n_abajo 1
#define n_derecha 2
#define n_izquierda 3
#define n_base 4

#include "personaje.h"
#include "mainwindow.h"
#include "objetos.h"
#include "bloque.h"
#include "comida.h"
#include "enemigos.h"

#include "ui_mainwindow.h"
#include "control_maestro.h"
#include "personaje.h"
#include "iostream"
//#include "tablero.cpp"

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include <QWidget>

class personaje;
class MainWindow;
class objetos;
class enemigos;


class control_maestro:public QObject, public QGraphicsPixmapItem
{

public:

    control_maestro(MainWindow* mainWindow);
    ~control_maestro();
    void mover_personaje();
    void comer_c(); // de los objetos
    void agregarMovimiento();
    void keyPressEvent(QKeyEvent* event);
    void crearmapa(QGraphicsScene *escena, char tablero[31][29]);
    bool colision(int posx_inc, int posy_inc, char direccion);
    bool comer(int posx_inc, int posy_inc, char direccion);
    void telepor_pacman(int posx, int posy);
    void fin_de_juego();
    void colisionesfantasmas();

public slots://la utilizamos para el Qtimer
    void mover_personaje_auto();
    void aggrgarMovimiento_comida();


private:
    bool inicio_juego;
    bool colision_enemigo;
    QLCDNumber* lcdnumero;
    int numero;
    char direccion;
    personaje* pacman;
    enemigos* fantasmas;
    //objetos *movimiento_p;
    MainWindow *pantalla_juego;
    MainWindow* mainWindow;
    QGraphicsScene* escena;
    QGraphicsScene* escenaFinal;
    QTimer* timer;
    QTimer* timer_enemigos;
    QTimer* timer_comida;
    QTimer* timerColisiones;
    bloque *muro;
    comida *bolita;
    objetos* finjuego;
    objetos* perdiste;
    QList<bloque*>bloques;
    QList<comida*>bolitas; //listas que me almacenan los bloques y bolitas


};

#endif // CONTROL_MAESTRO_H


