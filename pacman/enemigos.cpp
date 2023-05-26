#include "enemigos.h"

char tablero_fantasma[31][29]={
    {"xxxxxxxxxxxxxxxxxxxxxxxxxxxx"},
    {"x            xx            x"},
    {"x xxxx xxxxx xx xxxxx xxxx x"},
    {"x xxxx xxxxx xx xxxxx xxxx x"},
    {"x xxxx xxxxx xx xxxxx xxxx x"},
    {"x                          x"},
    {"x xxxx xx xxxxxxxx xx xxxx x"},
    {"x xxxx xx xxxxxxxx xx xxxx x"},
    {"x      xx    xx    xx      x"},
    {"xxxxxx xxxxx xx xxxxx xxxxxx"},
    {"xxxxxx xxxxx xx xxxxx xxxxxx"},
    {"xxxxxx xx          xx xxxxxx"},
    {"xxxxxx xx xxxxxxxx xx xxxxxx"},
    {"xxxxxx xx xzzzzzzx xxxxxxxxx"},
    {"x         xzzzzzzx         x"},
    {"xxxxxx xx xzzzzzzx xx xxxxxx"},
    {"xxxxxx xx xxxxxxxx xx xxxxxx"},
    {"xxxxxx xx          xx xxxxxx"},
    {"xxxxxx xxxxxxxxxxx xx xxxxxx"},
    {"xxxxxx xx xxxxxxxx xx xxxxxx"},
    {"x            xx            x"},
    {"x xxxx xxxxx xx xxxxx xxxx x"},
    {"x xxxx xxxxx xx xxxxx xxxx x"},
    {"x   xx                xx   x"},
    {"xxx xx xx xxxxxxxx xx xx xxx"},
    {"xxx xx xx xxxxxxxx xx xx xxx"},
    {"x      xx    xx    xx  x   x"},
    {"x xxxxxxxxxx xx xxxxxxxxxx x"},
    {"x xxxxxxxxxx xx xxxxxxxxxx x"},
    {"x                          x"},
    {"xxxxxxxxxxxxxxxxxxxxxxxxxxxx"}
};

enemigos::enemigos()
{   srand(time(NULL));//inicializamos la semilla random
    enemigos_g[verde]=new objetos("://verde",20,20);
    enemigos_g[rosa]=new objetos("://rosa",20,20);
    enemigos_g[naranja]=new objetos("://naranja",20,20);
    enemigos_g[rojo]=new objetos("://rojo",20,20);
    enemigos_g[devil]=new objetos("://devil",20,20);
    enemigos_g[run]=new objetos("://run",20,20);
    inicializarDireccionesAleatorias();//le damos direccion inicial a los fantasmas
}
char enemigos::obtenerPosicionAleatoria() {
    char valor;
    valor = rand() % 4;
    char direcciones[] = {'w', 's', 'd', 'a'};
   // valor = direcciones[valor];
    //return valor;
    return direcciones[valor];
}

objetos *enemigos::get_enemigo(int enemigo)
{
    return enemigos_g[enemigo];
}


bool enemigos::colision(int posx_inc, int posy_inc, char direccion)
{
    int ancho = 20;//sprites
    int alto = 20;
    int objeto_x = posx_inc / ancho;
    int objeto_y = posy_inc / alto;
    int fila = objeto_y + 1;  // Sumar 1 para compensar el índice base 0 en C++
    int columna = objeto_x + 1;  // Sumar 1 para compensar el índice base 0 en C++

    if (direccion == 'w') {
        if (posy_inc % alto == 0) {
            return false;
        } else if ((posy_inc - velocidad) % ancho == 0 and tablero_fantasma[fila - 1][columna - 1] == 'x') {
            return true;
        } else if ((posy_inc) % ancho != 0 and posx_inc % alto == 0) {
            if (tablero_fantasma[fila - 1][columna - 1] == 'x') {
                return true;
            }
        } else if ((posy_inc) % ancho != 0 and posx_inc % alto != 0) {
            if (tablero_fantasma[fila - 1][columna - 1] == 'x' or tablero_fantasma[fila-1][columna] == 'x') {
                return true;
            }
        }
    } else if (direccion == 's') {
        if (posy_inc % alto == 0) {
            return false;
        } else if ((posy_inc - velocidad) % ancho == 0 and tablero_fantasma[fila][columna-1] == 'x') {
            return true;
        } else if ((posy_inc) % ancho != 0 and posx_inc % alto == 0) {
            if (tablero_fantasma[fila][columna-1] == 'x') {
                return true;
            }
        } else if ((posy_inc) % ancho != 0 and posx_inc % alto != 0) {
            if (tablero_fantasma[fila][columna - 1] == 'x' or tablero_fantasma[fila][columna] == 'x') {
                return true;
            }
        }
    } else if (direccion == 'd') {
        if (posx_inc % ancho == 0) {
            return false;
        } else if ((posx_inc - velocidad) % ancho == 0 and tablero_fantasma[fila-1][columna] == 'x') {
            return true;
        } else if ((posx_inc) % ancho != 0 and posy_inc%alto == 0) {
            if (tablero_fantasma[fila - 1][columna] == 'x') {
                return true;
            }
        } else if ((posx_inc) % ancho != 0 and posy_inc%alto != 0) {
            if (tablero_fantasma[fila][columna] == 'x' or tablero_fantasma[fila-1][columna] == 'x') {
                return true;
            }
        }
    } else if (direccion == 'a') {
        if (posx_inc % ancho == 0) {
            return false;
        } else if ((posx_inc - velocidad) % ancho == 0 and tablero_fantasma[fila - 1][columna - 1] == 'x') {
            return true;
        } else if ((posx_inc) % ancho != 0 and posy_inc%alto == 0) {
            if (tablero_fantasma[fila - 1][columna - 1] == 'x') {
                return true;
            }
        } else if ((posx_inc) % ancho != 0 and posy_inc%alto != 0) {
            if (tablero_fantasma[fila - 1][columna - 1] == 'x' or tablero_fantasma[fila][columna-1] == 'x') {
                return true;
            }
        }
    }

    return false;

}

void enemigos::mover()
{
    for (int i = 0; i < 4; i++) {
        // Obtener posición actual del enemigo
        int x = enemigos_g[i]->x();
        int y = enemigos_g[i]->y();

        // Verificar si hay colisión en la dirección actual
        if (direccion[i]=='w'){
            if (colision(x, y-velocidad, direccion[i])) {
                // Cambiar a una nueva dirección aleatoria diferente a la actual
                char nuevaDireccion = obtenerPosicionAleatoria();
                while (nuevaDireccion == direccion[i]) {
                    nuevaDireccion = obtenerPosicionAleatoria();
                }
                direccion[i] = nuevaDireccion;
            }
            else{enemigos_g[i]->setY(y - velocidad);}

        }
        else if(direccion[i]=='s'){
            if (colision(x, y+velocidad, direccion[i])) {
                // Cambiar a una nueva dirección aleatoria diferente a la actual
                char nuevaDireccion = obtenerPosicionAleatoria();
                while (nuevaDireccion == direccion[i]) {
                    nuevaDireccion = obtenerPosicionAleatoria();
                }
                direccion[i] = nuevaDireccion;
            }
            else{enemigos_g[i]->setY(y + velocidad);}

        }
        else if(direccion[i]=='a'){
            if (colision(x-velocidad, y, direccion[i])) {
                // Cambiar a una nueva dirección aleatoria diferente a la actual
                char nuevaDireccion = obtenerPosicionAleatoria();
                while (nuevaDireccion == direccion[i]) {
                    nuevaDireccion = obtenerPosicionAleatoria();
                }
                direccion[i] = nuevaDireccion;
            }
            else{enemigos_g[i]->setX(x - velocidad);}

        }
        else if(direccion[i]=='d'){
            if (colision(x+velocidad, y, direccion[i])) {
                // Cambiar a una nueva dirección aleatoria diferente a la actual
                char nuevaDireccion = obtenerPosicionAleatoria();
                while (nuevaDireccion == direccion[i]) {
                    nuevaDireccion = obtenerPosicionAleatoria();
                }
                direccion[i] = nuevaDireccion;
            }
            else{enemigos_g[i]->setX(x + velocidad);}

        }

    }
}
void enemigos::inicializarDireccionesAleatorias() {
    direccion[verde] = obtenerPosicionAleatoria();
    direccion[rosa] = obtenerPosicionAleatoria();
    direccion[rojo] = obtenerPosicionAleatoria();
    direccion[naranja] = obtenerPosicionAleatoria();
}



