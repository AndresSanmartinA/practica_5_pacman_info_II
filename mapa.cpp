#include "mapa.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include "comida.h"
#include "bloque.h"
#include "personaje.h"
#include "enemigo.h"
#include "colision.h"



mapa::mapa()
{
    char mapita[31][30]={
        {"xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"},
        {"xccccccccccccxxxccccccccccccx"},
        {"xcxxxxcxxxxxcxxxcxxxxxcxxxxcx"},
        {"xCx  xcx   xcxxxcx   xcx  xCx"},
        {"xcxxxxcxxxxxcxxxcxxxxxcxxxxcx"},
        {"xcccccccccccccccccccccccccccx"},
        {"xcxxxxcxxcxxxxxxxxxcxxcxxxxcx"},
        {"xcxxxxcxxcxxxxxxxxxcxxcxxxxcx"},
        {"xccccccxxccccxxxccccxxccccccx"},
        {"xxxxxxcxxxxxcxxxcxxxxxcxxxxxx"},
        {"     xcxxxxxcxxxcxxxxxcx     "},
        {"     xcxx           xxcx     "},
        {"     xcxx xxx   xxx xxcx     "},
        {"xxxxxxcxx x       x xxcxxxxxx"},
        {"x     c   x ffff  x   c     x"},
        {"xxxxxxcxx x       x xxcxxxxxx"},
        {"     xcxx xxxxxxxxx xxcx     "},
        {"     xcxx     p     xxcx     "},
        {"     xcxx xxxxxxxxx xxcx     "},
        {"xxxxxxcxx xxxxxxxxx xxcxxxxxx"},
        {"xccccccccccccxxxccccccccccccx"},
        {"xcxxxxcxxxxxcxxxcxxxxxcxxxxcx"},
        {"xcxxxxcxxxxxcxxxcxxxxxcxxxxcx"},
        {"xCccxxccccccc cc ccccccxxccCx"},
        {"xxxcxxcxxcxxxxxxxxxcxxcxxcxxx"},
        {"xxxcxxcxxcxxxxxxxxxcxxcxxcxxx"},
        {"xccccccxxccccxxcccccxxccccccx"},
        {"xcxxxxxxxxxxcxxcxxxxxxxxxxxcx"},
        {"xcxxxxxxxxxxcxxcxxxxxxxxxxxcx"},
        {"xcccccccccccccccccccccccccccx"},
        {"xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"}
    };
    tablero=&mapita;



}

void mapa::crearmapa(QGraphicsScene escena)
{
    int  anchoc = 20;
    int  altoc =  20;
    int cantidad_fantasmas=0;


    for (int y = 0; y < 31; y++) {
        for (int x = 0; x < 30; x++) {
            if (tablero[y][x] == 'x') {
                // Calcular la posición del objeto muro
                int posX = x * anchoc;
                int posY = y * altoc;
                // Crear el objeto muro y agregarlo a la escena
                muro = new bloque(posX, posY, anchoc, altoc);
                escena->addItem(muro);
                bloques.append(muro); //esta lista me almacena todas los muros y me sirve para las colisiones, ya que tengo su posicion y es como una lista que guarda objetos
            }

            else if (tablero[y][x]=='c') {
                int posX = x * anchoc;
                int posY = y * altoc;
                bolita = new comida(posX,posY,4);
                escena->addItem(bolita);
                bolitas.append(bolita);
            }
            //aqui agregamos la posición del pacman segun se se diga en el mapa
            else if(tablero[y][x]=='p'){
                int posX = x * anchoc;
                int posY = y * altoc;
                personaje[base]->setPos(posX,posY);
                escena->addItem(personaje[base]);
            }
            //aqui colocamos la condicion y la posicion de los fantasmas
            else if(tablero[y][x]=='f'){
                int posX = x * anchoc;
                int posY = y * altoc;
                enemigos[cantidad_fantasmas]->setPos(posX,posY);
                escena->addItem(enemigos[cantidad_fantasmas]);
                cantidad_fantasmas=cantidad_fantasmas+1;

            }
        }
    }
}
