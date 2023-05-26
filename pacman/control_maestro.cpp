#include "control_maestro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "control_maestro.h"
#include "personaje.h"
#include "iostream"
#include "tablero.cpp"
using namespace std;

#include <QTimer>

control_maestro::control_maestro(MainWindow* mainWindow)
{
    this->pantalla_juego = mainWindow;
    this->escena = mainWindow->getEscena();
    pacman=new personaje();
    fantasmas=new enemigos();
    inicio_juego=true;

    //Mapa
    crearmapa(escena,tablero);
    pantalla_juego->setStyleSheet("background-color: black;");

    fantasmas->start='1';

    timer_enemigos = new QTimer();
    QObject::connect(timer_enemigos, SIGNAL(timeout()), fantasmas, SLOT(mover()));
         timer_enemigos->start(60); // Intervalo de tiempo en milisegundos para mover a los enemigos (ajusta según tus necesidades)

    QTimer *timerColisiones = new QTimer(this);
    connect(timerColisiones, &QTimer::timeout, this, &control_maestro::colisionesfantasmas);
    timerColisiones->start(60);

    pantalla_juego->getUI()->graphicsView->setScene(escena);
         direccion='z';
         numero=0;
         lcdnumero=pantalla_juego->getUI()->lcdNumber;
         //esto se utiliza para cambiar el color y texto de textBrouser
        // QColor color(Qt::red);
        // QTextCharFormat format;
        // format.setForeground(color);
       //  pantalla_juego->getUI()->textBrowser->setCurrentCharFormat(format);
      //   pantalla_juego->getUI()->textBrowser->append("Tu puntaje es:");
         pantalla_juego->getUI()->textBrowser->setStyleSheet("border: none;");
         aggrgarMovimiento_comida();
         agregarMovimiento();

}

void control_maestro::mover_personaje()
{

    //pacman->movimiento->setY(pacman->movimiento->y()-pacman->velocidad);
}

void control_maestro::comer_c()
{
    QList<comida*>::iterator it=bolitas.begin();
    while (it!=bolitas.end()){
        if((*it)->collidesWithItem(pacman->movimiento)){
            direccion='w';
            numero=numero+10;
            lcdnumero->display(numero);
            escena->removeItem(*it);
            delete *it;
            it=bolitas.erase(it);
        }
        else{
            ++it;
        }

    }
}

void control_maestro::aggrgarMovimiento_comida()
{
    timer_comida=new QTimer();
    QObject::connect(timer_comida, SIGNAL(timeout()), pacman, SLOT(comer2()));
    timer_comida->start(50);
}

control_maestro::~control_maestro()
{
    delete pacman;
    delete fantasmas;
    delete timer;
    delete timer_comida;
    delete timer_enemigos;
}

void control_maestro::mover_personaje_auto()
{
    telepor_pacman(pacman->movimiento->x(),pacman->movimiento->y());


    if (pacman->x_o_y=='w' and inicio_juego ==true) { // Arriba
        direccion='w';

        if(colision(pacman->movimiento->x(),pacman->movimiento->y()-pacman->velocidad,direccion)==false){//aqui hacemos que haga el paso para verificar si se puede hacer
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_arriba)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_arriba)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_arriba);
            pacman->moverV2(direccion);
            fin_de_juego();
            comer_c();
            pacman->x_o_y='w';
            escena->addItem(pacman->movimiento);}

        else{
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_base)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_base)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_base);
            escena->addItem(pacman->movimiento);
        }



    }
    else if (pacman->x_o_y=='s' and inicio_juego ==true) { // abajo
        direccion='s';

        if(colision(pacman->movimiento->x(),pacman->movimiento->y()+pacman->velocidad,direccion)==false){
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_abajo)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_abajo)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_abajo);
            pacman->moverV2(direccion);
            fin_de_juego();
            comer_c();
            pacman->x_o_y='s';
            escena->addItem(pacman->movimiento);}
        else{
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_base)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_base)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_base);
            escena->addItem(pacman->movimiento);
        }

    }
    else if (pacman->x_o_y=='d' and inicio_juego ==true) { // derecha
        direccion='d';

        if(colision(pacman->movimiento->x()+pacman->velocidad,pacman->movimiento->y(),direccion)==false){
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_derecha)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_derecha)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_derecha);
            pacman->moverV2(direccion);
            fin_de_juego();
            comer_c();
            pacman->x_o_y='d';
            escena->addItem(pacman->movimiento);}
        else{
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_base)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_base)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_base);
            escena->addItem(pacman->movimiento);
        }

    }
    else if (pacman->x_o_y=='a' and inicio_juego ==true) { // izquierda
        direccion='a';

        if(colision(pacman->movimiento->x()-pacman->velocidad,pacman->movimiento->y(),direccion)==false){
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_izquierda)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_izquierda)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_izquierda);
            pacman->moverV2(direccion);
            fin_de_juego();
            comer_c();
            pacman->x_o_y='a';
            escena->addItem(pacman->movimiento);}

        else{
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_base)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_base)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_base);
            escena->addItem(pacman->movimiento);
        }

    }

}

void control_maestro::agregarMovimiento()//esto seria para el movimiento automatico
{
    timer = new QTimer;
    //connect(timer, SIGNAL(timeout()), this, SLOT(mover_personaje_auto()));
    connect(timer, &QTimer::timeout, this, &control_maestro::mover_personaje_auto);
    timer->start(50);
}


void control_maestro::keyPressEvent(QKeyEvent* event)

{

    telepor_pacman(pacman->movimiento->x(),pacman->movimiento->y());


    if (event->key() == Qt::Key_W and inicio_juego ==true) { // Arriba
        direccion='w';

        if(colision(pacman->movimiento->x(),pacman->movimiento->y()-pacman->velocidad,direccion)==false){//aqui hacemos que haga el paso para verificar si se puede hacer
        escena->removeItem(pacman->movimiento);
        pacman->get_personaje_p(n_arriba)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
        pacman->get_personaje_p(n_arriba)->setX(pacman->movimiento->x());
        pacman->movimiento=pacman->get_personaje_p(n_arriba);
        pacman->moverV2(direccion);
        fin_de_juego();
        comer_c();
        pacman->x_o_y='w';
        escena->addItem(pacman->movimiento);}

        else{
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_base)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_base)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_base);
            escena->addItem(pacman->movimiento);
        }



    }

    else if (event->key() == Qt::Key_S and inicio_juego ==true) { // abajo
        direccion='s';

        if(colision(pacman->movimiento->x(),pacman->movimiento->y()+pacman->velocidad,direccion)==false){
        escena->removeItem(pacman->movimiento);
        pacman->get_personaje_p(n_abajo)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
        pacman->get_personaje_p(n_abajo)->setX(pacman->movimiento->x());
        pacman->movimiento=pacman->get_personaje_p(n_abajo);
        pacman->moverV2(direccion);
        fin_de_juego();
        comer_c();
        pacman->x_o_y='s';
        escena->addItem(pacman->movimiento);}
        else{
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_base)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_base)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_base);
            escena->addItem(pacman->movimiento);
        }

    }
    else if (event->key() == Qt::Key_D and inicio_juego ==true) { // derecha
        direccion='d';

        if(colision(pacman->movimiento->x()+pacman->velocidad,pacman->movimiento->y(),direccion)==false){
        escena->removeItem(pacman->movimiento);
        pacman->get_personaje_p(n_derecha)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
        pacman->get_personaje_p(n_derecha)->setX(pacman->movimiento->x());
        pacman->movimiento=pacman->get_personaje_p(n_derecha);
        pacman->moverV2(direccion);
        fin_de_juego();
        comer_c();
        pacman->x_o_y='d';
        escena->addItem(pacman->movimiento);}
        else{
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_base)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_base)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_base);
            escena->addItem(pacman->movimiento);
        }

    }
    else if (event->key() == Qt::Key_A and inicio_juego ==true) { // izquierda
        direccion='a';

        if(colision(pacman->movimiento->x()-pacman->velocidad,pacman->movimiento->y(),direccion)==false){
        escena->removeItem(pacman->movimiento);
        pacman->get_personaje_p(n_izquierda)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
        pacman->get_personaje_p(n_izquierda)->setX(pacman->movimiento->x());
        pacman->movimiento=pacman->get_personaje_p(n_izquierda);
        pacman->moverV2(direccion);
        fin_de_juego();
        comer_c();
        pacman->x_o_y='a';
        escena->addItem(pacman->movimiento);}

        else{
            escena->removeItem(pacman->movimiento);
            pacman->get_personaje_p(n_base)->setY(pacman->movimiento->y());//le damos la pocicion en x y y del personaje
            pacman->get_personaje_p(n_base)->setX(pacman->movimiento->x());
            pacman->movimiento=pacman->get_personaje_p(n_base);
            escena->addItem(pacman->movimiento);
        }

    }


}
void control_maestro::crearmapa(QGraphicsScene *escena, char tablero[31][29]){
    // Calcular el ancho y alto de cada  cuadro en la matriz
    int  anchoc = 20;
    int  altoc =  20;
    int cantidad_fantasmas=0;
    //macros
    pantalla_juego->tamaño_de_la_escena(0,0,560,650);//aqui le damos el tamaño a la escena
    pantalla_juego->setGeometry(0,0,562,652);//aqui le damos tamaño al la pantalla


    for (int y = 0; y < 31; y++) {
       for (int x = 0; x < 29; x++) {
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
               pacman->movimiento->setPos(posX+10,posY);//le sume 10 solo para que que en el centro :v
               escena->addItem(pacman->movimiento);
           }
           //aqui colocamos la condicion y la posicion de los fantasmas
           else if(tablero[y][x]=='f'){
               int posX = x * anchoc;
               int posY = y * altoc;
               fantasmas->get_enemigo(cantidad_fantasmas)->setPos(posX,posY);
               escena->addItem(fantasmas->get_enemigo(cantidad_fantasmas));
               cantidad_fantasmas=cantidad_fantasmas+1;

           }
       }
    }
}

bool control_maestro::colision(int posx_inc, int posy_inc, char direccion)
{
    int ancho = 20;
    int alto = 20;
    int objeto_x = posx_inc / ancho;
    int objeto_y = posy_inc / alto;
    int fila = objeto_y + 1;  // Sumar 1 para compensar el índice base 0 en C++
    int columna = objeto_x + 1;  // Sumar 1 para compensar el índice base 0 en C++

    if (direccion == 'w') {
        // hay que colocar las siguientes condiciones:
        // si pos_inc y % alto == 0 true
        // si la x - velm % == 0
        // si la x % != 0 pero y % == 0
        // si la x % != 0 y y % != 0
        if (posy_inc % alto == 0) {
            return false;
        }
        else if ((posy_inc - pacman->velocidad) % ancho == 0 and tablero[fila - 1][columna - 1] == 'x') {
            return true;
        }
        else if ((posy_inc) % ancho != 0 and posx_inc % alto == 0) {
            if (tablero[fila - 1][columna - 1] == 'x') {
                return true;
            }
        }
        else if ((posy_inc) % ancho != 0 and posx_inc % alto != 0) {
            if (tablero[fila - 1][columna - 1] == 'x' or tablero[fila-1][columna] == 'x') {
                return true;
            }
        }
    }
    else if (direccion == 's') {
        if (posy_inc % alto == 0) {
            return false;
        }
        else if ((posy_inc - pacman->velocidad) % ancho == 0 and tablero[fila][columna-1] == 'x') {
            return true;
        }
        else if ((posy_inc) % ancho != 0 and posx_inc % alto == 0) {
            if (tablero[fila][columna-1] == 'x') {
                return true;
            }
        }
        else if ((posy_inc) % ancho != 0 and posx_inc % alto != 0) {
            if (tablero[fila][columna - 1] == 'x' or tablero[fila][columna] == 'x') {
                return true;
            }
        }
    }
    else if (direccion == 'd') {
        if (posx_inc % ancho == 0) {
            return false;
        }
        else if ((posx_inc - pacman->velocidad) % ancho == 0 and tablero[fila-1][columna] == 'x') {
            return true;
        }
        else if ((posx_inc) % ancho != 0 and posy_inc%alto == 0) {
            if (tablero[fila - 1][columna] == 'x') {
                return true;
            }
        }
        else if ((posx_inc) % ancho != 0 and posy_inc%alto != 0) {
            if (tablero[fila][columna] == 'x' or tablero[fila-1][columna] == 'x') {
                return true;
            }
        }
    }
    else if (direccion == 'a') {
        if (posx_inc % ancho == 0) {
            return false;
        }
        else if ((posx_inc - pacman->velocidad) % ancho == 0 and tablero[fila - 1][columna - 1] == 'x') {
            return true;
        }
        else if ((posx_inc) % ancho != 0 and posy_inc%alto == 0) {
            if (tablero[fila - 1][columna - 1] == 'x') {
                return true;
            }
        }
        else if ((posx_inc) % ancho != 0 and posy_inc%alto != 0) {
            if (tablero[fila - 1][columna - 1] == 'x' or tablero[fila][columna-1] == 'x') {
                return true;
            }
        }
    }

    return false;
}

bool control_maestro::comer(int posx_inc, int posy_inc, char direccion)
{

int ancho = 20;
int alto = 20;
int objeto_x = posx_inc / ancho;
int objeto_y = posy_inc / alto;
int fila = objeto_y + 1;  // Sumar 1 para compensar el índice base 0 en C++
int columna = objeto_x + 1;  // Sumar 1 para compensar el índice base 0 en C++

if (direccion == 'w') {
    if (posy_inc % alto == 0) {
        return false;
    }
    else if ((posy_inc - pacman->velocidad) % ancho == 0 and tablero[fila - 1][columna - 1] == 'c') {
        return true;
    }
    else if ((posy_inc) % ancho != 0 and posx_inc % alto == 0) {
        if (tablero[fila - 1][columna - 1] == 'c') {
            return true;
        }
    }
    else if ((posy_inc) % ancho != 0 and posx_inc % alto != 0) {
        if (tablero[fila - 1][columna - 1] == 'c' or tablero[fila-1][columna] == 'c') {
            return true;
        }
    }
}
else if (direccion == 's') {
    if (posy_inc % alto == 0) {
        return false;
    }
    else if ((posy_inc - pacman->velocidad) % ancho == 0 and tablero[fila][columna-1] == 'c') {
        return true;
    }
    else if ((posy_inc) % ancho != 0 and posx_inc % alto == 0) {
        if (tablero[fila][columna-1] == 'c') {
            return true;
        }
    }
    else if ((posy_inc) % ancho != 0 and posx_inc % alto != 0) {
        if (tablero[fila][columna - 1] == 'c' or tablero[fila][columna] == 'c') {
            return true;
        }
    }
}
else if (direccion == 'd') {
    if (posx_inc % ancho == 0) {
        return false;
    }
    else if ((posx_inc - pacman->velocidad) % ancho == 0 and tablero[fila-1][columna] == 'c') {
        return true;
    }
    else if ((posx_inc) % ancho != 0 and posy_inc%alto == 0) {
        if (tablero[fila - 1][columna] == 'c') {
            return true;
        }
    }
    else if ((posx_inc) % ancho != 0 and posy_inc%alto != 0) {
        if (tablero[fila][columna] == 'c' or tablero[fila-1][columna] == 'c') {
            return true;
        }
    }
}
else if (direccion == 'a') {
    if (posx_inc % ancho == 0) {
        return false;
    }
    else if ((posx_inc - pacman->velocidad) % ancho == 0 and tablero[fila - 1][columna - 1] == 'c') {
        return true;
    }
    else if ((posx_inc) % ancho != 0 and posy_inc%alto == 0) {
        if (tablero[fila - 1][columna - 1] == 'c') {
            return true;
        }
    }
    else if ((posx_inc) % ancho != 0 and posy_inc%alto != 0) {
        if (tablero[fila - 1][columna - 1] == 'c' or tablero[fila][columna-1] == 'c') {
            return true;
        }
    }
}

return false;
}

void control_maestro::telepor_pacman(int posx, int posy)
{
 if (posx>=560 and posy==280){
     pacman->movimiento->setPos(-10,280);
 }
 else if (posx<=-20 and posy==280)
     pacman->movimiento->setPos(550,280);
}

void control_maestro::colisionesfantasmas()
{
 for (int i = 0; i < 4; i++) {
     QGraphicsItem* fantasma = fantasmas->get_enemigo(i);

     if (pacman->movimiento->collidesWithItem(fantasma)) {
        inicio_juego=false;
        perdiste=new objetos(":/imagenes/game over.jpg",560,650);
        escena->addItem(perdiste);
        pantalla_juego->getUI()->graphicsView->setScene(escena);
     }
 }
}

void control_maestro::fin_de_juego()
{colision_enemigo=false;
 if(numero==2500){
     escena->removeItem(pacman->movimiento);
     inicio_juego=false;
     timer_enemigos->stop();
     timer_comida->stop();
     finjuego=new objetos("://imagenes/lose.jpg",560,650);
     escena->addItem(finjuego);
     pantalla_juego->getUI()->graphicsView->setScene(escena);
 }
 else if (colision_enemigo==true){
     inicio_juego=false;
     perdiste=new objetos(":/imagenes/game over.jpg",560,650);
     escena->addItem(perdiste);
     pantalla_juego->getUI()->graphicsView->setScene(escena);
 }

}



