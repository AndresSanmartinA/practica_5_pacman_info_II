#ifndef BLOQUE_H
#define BLOQUE_H

#include <QGraphicsItem>

class bloque : public QGraphicsItem { // <-- el símbolo ":" se usa para indicar herencia
    int posx, posy, largo, ancho;
public:
    bloque();
    bloque(int x, int y, int l, int a);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BLOQUE_H
