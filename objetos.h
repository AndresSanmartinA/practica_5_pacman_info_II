#ifndef OBJETOS_H
#define OBJETOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QMainWindow>
#include <QGraphicsScene>
#include "objetos.h"

//le damos a objetos herencia publico de Qobjet

class objetos : public QObject, public QGraphicsPixmapItem
{  // int posx,posy,velocidad;
    Q_OBJECT // Se utiliza para usar las características de QObject

public:
  //   objetos(QString name, int velocidad, int posx, int posy); // Corregido: agregué los tipos de datos para velocidad, posx y posy
   // void MoveUp();
   // void MoveDown(); // Corregido: corregí el nombre de la función MoveDowm() a MoveDown()
   // void MoveRight();
   // void MoveLeft(); // Corregido: corregí el nombre de la función Moveleft() a MoveLeft()

    objetos(QString name_url,int ancho,int alto);
    //sobrecargamos el costructor
};
#endif // OBJETOS_H
