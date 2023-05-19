#include "comida.h"
#include <QPainter>

comida::comida()
{
}

comida::comida(int x, int y, int r)
{   this->posx=x;
    this->posy=y;
    this->radio=r;
    esnegra = false;

}

QRectF comida::boundingRect() const
{
    return QRectF(posx+10, posy+10,radio*2,radio*2); //sumamos 10.5  para que queden mas centraditas, esto es como un cuadrado que esta alrededor de mi figura
}

//void comida::setesnegra(bool value) {
//    esnegra = value;
//}

 void comida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{  // if (esnegra==false){
    painter->setBrush(Qt::yellow);
   // }

   // if (esnegra==true){
   // painter->setBrush(Qt::black);
   // }
    painter->drawEllipse(boundingRect());
}

