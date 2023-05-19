#include "personaje.h"

#include "objetos.h"

personaje::personaje()
{
    personaje[base]=new objetos(":/imagenes/pacman/a1.png",ancho_sprite,alto_sprite);//la imagen que queremos proyectar del pacman
    movimiento=personaje[base];//paara ensayar funcion comer
    personaje[arriba]=new objetos(":/imagenes/pacman/b3.png",ancho_sprite,alto_sprite);
    personaje[abajo]=new objetos(":/imagenes/pacman/d3.png",ancho_sprite,alto_sprite);
    personaje[derecha]=new objetos(":/imagenes/pacman/c3.png",ancho_sprite,alto_sprite);
    personaje[izquierda]=new objetos(":/imagenes/pacman/a3.png",ancho_sprite,alto_sprite);
    x_o_y='z';
}
void personaje::mover()
{
    //our_focus(movimiento);
    if(x_o_y=='w'){//le damos la condicion al movimiento
        if (colision()) {
            personaje[base]->setX(movimiento->x());
            personaje[base]->setY(movimiento->y());
            escena->removeItem(movimiento);
            movimiento=personaje[base];
            comer();
            movimiento->setY(movimiento->y()+4); // Deshacer el movimiento cambiar set x and y
            escena->addItem(movimiento);

            x_o_y='z';}
        else{
            movimiento->setY(movimiento->y()-2);
            comer();}
    }
    else if(x_o_y=='s'){
        if (colision()) {
            personaje[base]->setX(movimiento->x());
            personaje[base]->setY(movimiento->y());
            escena->removeItem(movimiento);
            movimiento=personaje[base];
            comer();
            movimiento->setY(movimiento->y()-4);
            escena->addItem(movimiento);

            x_o_y='z';}
        else{comer();
            movimiento->setY(movimiento->y()+2);}

    }
    else if(x_o_y=='a'){
        if (colision()) {
            personaje[base]->setX(movimiento->x());
            personaje[base]->setY(movimiento->y());
            escena->removeItem(movimiento);
            movimiento=personaje[base];
            comer();
            movimiento->setX(movimiento->x()+4);
            escena->addItem(movimiento);

            //movimiento->setX(movimiento->y()); // Deshacer el movimiento
            x_o_y='z';}
        else{comer();
            movimiento->setX(movimiento->x()-2);}
    }
    else if(x_o_y=='d'){
        if (colision()) {
            personaje[base]->setX(movimiento->x());
            personaje[base]->setY(movimiento->y());
            escena->removeItem(movimiento);
            movimiento=personaje[base];
            comer();
            movimiento->setX(movimiento->x()-4);
            escena->addItem(movimiento);

            //movimiento->setX(movimiento->y()); // Deshacer el movimiento
            x_o_y='z';

        }
        else{comer();
            movimiento->setX(movimiento->x()+2);}
    }
    //ahora aqui le damos vida a los fantasmas-preguntar si se puede usar funcion a parte de la de
    //pacman creo que si
    /*enemigos[0]->setX(enemigos[0]->x()+1);
    enemigos[1]->setX(enemigos[1]->x()-1);
    enemigos[2]->setY(enemigos[2]->y()+1);
    enemigos[3]->setY(enemigos[3]->y()-1);*/
}
void personaje::comer()
{
    QList<comida*>::iterator it = bolitas.begin();
    while (it != bolitas.end()) {
        if ((*it)->collidesWithItem(movimiento)) {
            escena->removeItem(*it);
            delete *it;
            it = bolitas.erase(it);
        } else {
            ++it;
        }
    }
}
