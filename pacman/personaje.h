#ifndef PERSONAJE_H
#define PERSONAJE_H

#define n_arriba 0
#define n_abajo 1
#define n_derecha 2
#define n_izquierda 3
#define n_base 4
#define n_ancho_sprite 20
#define n_alto_sprite 20
#define caras_personaje 5


#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include "objetos.h"
#include "mainwindow.h"
#include <QObject>
#include "control_maestro.h"

//class control_maestro;
class personaje:public QObject, public QGraphicsPixmapItem
{Q_OBJECT // Agregamos la macro Q_OBJECT
public:
    personaje();
    //void keyPressEvent(QKeyEvent *teclas);//para las teclas del teclado
    void principal_personaje();
    bool comida;
    char direccion;
    objetos *movimiento;//este se va a encargar de moverse entre los punteros personaje
    objetos *get_personaje_p(int numero_p);
    void personaje_arriba_c(char cara);
    void personaje_abajo_c(char cara);
    void personaje_derecha_c(char cara);
    void personaje_izquierda_c(char cara);
~personaje();

    int velocidad;
    char x_o_y;

public slots://la utilizamos para el Qtimer

void mover();
void comer();
void comer2();
void moverV2(char direccion);

private:
int comida_t;
//char direccion;
objetos *personaje_p[caras_personaje];
//agregamos un char que sera el que indicara a que direcion se mueve de manera const el pacman

};

#endif // PERSONAJE_H
