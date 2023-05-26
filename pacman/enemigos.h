#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#define verde 0
#define rosa 1
#define rojo 3
#define naranja 2
#define devil 4
#define run 5

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <QObject>
#include <control_maestro.h>
#include <iostream>
#include <random>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

#include "objetos.h"
#include "mainwindow.h"

class objetos;
class control_maestro;

class enemigos:public QObject, public QGraphicsPixmapItem
{Q_OBJECT // Agregamos la macro Q_OBJECT
public:
    enemigos();
    objetos* get_enemigo(int enemigo);
    char start;//sera 0 apagado y 1 on
    char obtenerPosicionAleatoria();
    void inicializarDireccionesAleatorias();
public slots://la utilizamos para el Qtimer

void mover();

private:
    bool colision(int posx_inc, int posy_inc, char direccion);
    int velocidad=4;
    objetos* enemigos_g[6];//0=fantasma verde,1=f Rosa,2=F rojo,3= F naranja, 4=ojos,5=fantasma comesetible
    char direccion[6];


};

#endif // ENEMIGOS_H
