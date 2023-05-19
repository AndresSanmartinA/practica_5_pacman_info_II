#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "objetos.h"
#define base 0
#define arriba 1
#define abajo 2
#define derecha 3
#define izquierda 4
#define ancho_sprite 20
#define alto_sprite 20

class personaje
{
public:
    personaje();
    void mover();
    void comer();
private:
    objetos *movimiento;
    char x_o_y;
};

#endif // PERSONAJE_H
