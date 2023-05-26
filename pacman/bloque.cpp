#include "bloque.h"
#include <QPainter>

bloque::bloque() : QGraphicsItem()
{
}

bloque::bloque(int x, int y, int l, int a)
{   this->posx=x;
    this->posy=y;
    this->largo=l;
    this->ancho=a;
}

QRectF bloque::boundingRect() const
{
    return QRectF(posx, posy,20,20);
}

void bloque::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
