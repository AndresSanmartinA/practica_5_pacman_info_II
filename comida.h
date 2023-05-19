#ifndef COMIDA_H
#define COMIDA_H

#include <QGraphicsItem>

class comida : public QGraphicsItem {
    int posx, posy, radio;
    bool esnegra;
public:
    comida();
    comida(int x, int y, int r);
    QRectF boundingRect() const; //esto es importante porque mis objetos quedan delimitados para las colisiones
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //void setesnegra(bool value);
};

#endif // COMIDA_H
