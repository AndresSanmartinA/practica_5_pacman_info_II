#ifndef OBJETOS_H
#define OBJETOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QMainWindow>
#include <QGraphicsScene>



//le damos a objetos herencia publico de Qobjet

class objetos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT // Se utiliza para usar las características de QObject

public:

    objetos(QString name_url,int ancho,int alto);
    //sobrecargamos el costructor
};

#endif // OBJETOS_H
