#include "objetos.h"

objetos::objetos(QString name_url, int ancho, int alto)
{
    //si se utiliza la escala seria
    setPixmap(QPixmap(name_url).scaled(ancho,alto));//aqui controlamos el tamaño de la imagen
    //osea los pixeles

}
