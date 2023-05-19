#include "objetos.h"

/*objetos::objetos(QString name,int velocidad, int posx, int posy)//esta se va a encargar de los objetos de la escena
{   //vamos a cargar una imagen al proyecto primero agregamos recursos
    setPixmap(QPixmap(name));//aqui cargamos la imagen dentro del objeto
    this->velocidad = velocidad;
    this->posx = posx;
    this->posy = posy;
    setPos(posx,posy);
}

void objetos::MoveUp()
{   posy=posy-velocidad;
    setPos(posx,posy);
}

void objetos::MoveDown()
{
    posy=posy+velocidad;
    setPos(posx,posy);
}

void objetos::MoveRight()
{     posx=posx+velocidad;
      setPos(posx,posy);
}
void objetos::MoveLeft()
{
      posx=posx-velocidad;
      setPos(posx,posy);
}
*/
objetos::objetos(QString name_url, int ancho, int alto)
{
    //si se utiliza la escala seria
    setPixmap(QPixmap(name_url).scaled(ancho,alto));//aqui controlamos el tamaño de la imagen
    //osea los pixeles
}

