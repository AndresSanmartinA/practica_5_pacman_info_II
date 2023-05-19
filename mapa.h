#ifndef MAPA_H
#define MAPA_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include "comida.h"
#include "bloque.h"
#include "personaje.h"
#include "enemigo.h"
#include "colision.h"
class mapa
{
public:
    mapa();
    void crearmapa(QGraphicsScene escena);
private:

    char *tablero;
    bloque *muro;
    comida *bolita;
};

#endif // MAPA_H
