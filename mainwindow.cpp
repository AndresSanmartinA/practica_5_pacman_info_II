#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QPointF>
#include "objetos.h"
#include "bloque.h"
#include "mapa.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{   ui->setupUi(this);//preferible dejarlo de primero

   //Escenario
    escena=new QGraphicsScene;
    //enemigo= new objetos(":/imagenes/Pacman.png",3,0,280);

    escena->setSceneRect(0, 0, 560, 680);
    ui->graphicsView->setScene(escena);

    //damos un pacman base por si le damos pocicion con el mapa//lo mismo con los fantasmas



    fantasmas();

    //Mapa
    mapa(escena);
    setStyleSheet("background-color: black;");

    //ahora agregamos qtimer
    tiempo = new QTimer;
    //inicializamos el Qtimer
    connect(tiempo,SIGNAL(timeout()),this,SLOT(mover()));//1puntero que cuenta,2 tipo de modo
            //3 clase en la que se encuentra, 4 el nombre de ejecucion que se ejecuta

    //inicializamos el conteo de qtimer
            x_o_y='z';
            tiempo->start(40);//definimos cada cuanto se repite en milisegundos
            //ponemos la funcion comer//toca definir primero movimiento
                    comer();
   //Personajes
   //enemigo->setPos(0,280);
   //Personajes
   pacman();
   //escena->addItem(enemigo)
}

bool MainWindow::colision()
{  /*QList<bloque*>::iterator it;
   for(it=bloques.begin(); it!=bloques.end(); it++)
    {
        if((*it)->collidesWithItem(movimiento))
        {
            return true;
        }
    }*/
   return false;
}

void MainWindow::comer()
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

void MainWindow::pacman()
{
    //int ancho_sprite=20,alto_sprite=20;
   // personaje[base]=new objetos(":/imagenes/pacman/a1.png",ancho_sprite,alto_sprite);//la imagen que queremos proyectar del pacman

    personaje[arriba]=new objetos(":/imagenes/pacman/b3.png",ancho_sprite,alto_sprite);
    personaje[abajo]=new objetos(":/imagenes/pacman/d3.png",ancho_sprite,alto_sprite);
    personaje[derecha]=new objetos(":/imagenes/pacman/c3.png",ancho_sprite,alto_sprite);
    personaje[izquierda]=new objetos(":/imagenes/pacman/a3.png",ancho_sprite,alto_sprite);

    //personaje[base]->setPos(0,200);//este por si toca manual
    //movimiento=personaje[base];//lo comente para ensayar funcion comer
    //ahora lo cargamos en ecena
    escena->addItem(movimiento);
    //para eliminar el personaje
    //escena->removeItem(personaje[y que personaje vamos a eliminar]);
    //ya proyectamos la escena
    ui->graphicsView->setScene(escena);
}

void MainWindow::fantasmas()
{
    enemigos[0]=new objetos(":/imagenes/ghosts/greendown2.png",19,19);
    enemigos[1]=new objetos(":/imagenes/ghosts/pinkdown2.png",19,19);
    enemigos[2]=new objetos(":/imagenes/ghosts/reddown2.png",19,19);
    enemigos[3]=new objetos(":/imagenes/ghosts/yellowdown2.png",19,19);
    enemigos[4]=new objetos(":/imagenes/ghosts/run.png",19,19);
    enemigos[5]=new objetos(":/imagenes/ghosts/bl1.png",19,19);
}

void MainWindow::mover()
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

void MainWindow::our_focus(QGraphicsItem *item)
{
        QRectF pos= escena->sceneRect();

        escena->setSceneRect(item->x(),pos.y(),escena->width(),escena->height());
}

void MainWindow::keyPressEvent(QKeyEvent *teclas)
    {
    if (teclas->key() == Qt::Key_W) { // Arriba
        //enemigo->MoveUp();
        comer();
        personaje[arriba]->setY(movimiento->y());//le damos la pocicion en x y y del personaje
        personaje[arriba]->setX(movimiento->x());
        escena->removeItem(movimiento);
        escena->addItem(personaje[arriba]);
        movimiento=personaje[arriba];

        //movimiento->setY(movimiento->y()-1);
        x_o_y='w';
        if (colision()) {
            personaje[base]->setX(movimiento->x());
            personaje[base]->setY(movimiento->y());
            escena->removeItem(movimiento);
            movimiento=personaje[base];
            movimiento->setY(movimiento->y()+4); // Deshacer el movimiento cambiar set x and y

            escena->addItem(movimiento);

            x_o_y='z';}
        else{movimiento->setY(movimiento->y()-2);}//cambiemos el avance del pacman

    } else if (teclas->key() == Qt::Key_S) { // Abajo
        //enemigo->MoveDown();
        comer();
        personaje[abajo]->setY(movimiento->y());//le damos la pocicion en x y y del personaje
        personaje[abajo]->setX(movimiento->x());

        escena->removeItem(movimiento);
        escena->addItem(personaje[abajo]);
        movimiento=personaje[abajo];

       // movimiento->setY(movimiento->y()+1);
        x_o_y='s';
        //miramos lo de las colisiones

        if (colision()) {
            personaje[base]->setX(movimiento->x());
            personaje[base]->setY(movimiento->y());
            escena->removeItem(movimiento);
            movimiento=personaje[base];
            movimiento->setY(movimiento->y()-4);
            escena->addItem(movimiento);

            x_o_y='z';}
        else{movimiento->setY(movimiento->y()+2);}


    } else if (teclas->key() == Qt::Key_A) { // Izquierda
        //enemigo->MoveLeft();
        comer();
        personaje[derecha]->setY(movimiento->y());//le damos la pocicion en x y y del personaje
        personaje[derecha]->setX(movimiento->x());

        escena->removeItem(movimiento);
        escena->addItem(personaje[derecha]);
        movimiento=personaje[derecha];
        x_o_y='a';

        //movimiento->setX(movimiento->x()-1);

        if (colision()) {
            personaje[base]->setX(movimiento->x());
            personaje[base]->setY(movimiento->y());
            escena->removeItem(movimiento);
            movimiento=personaje[base];
            movimiento->setX(movimiento->x()+4);
            escena->addItem(movimiento);

            //movimiento->setX(movimiento->y()); // Deshacer el movimiento
            x_o_y='z';}
        else{movimiento->setX(movimiento->x()-2);}

    } else if (teclas->key() == Qt::Key_D) { // Derecha
        //enemigo->MoveRight();
        comer();
        personaje[izquierda]->setX(movimiento->x());
        personaje[izquierda]->setY(movimiento->y());

        escena->removeItem(movimiento);
        escena->addItem(personaje[izquierda]);
        movimiento=personaje[izquierda];
        x_o_y='d';

        //movimiento->setX(movimiento->x()+1);

        if (colision()) {
            personaje[base]->setX(movimiento->x());
            personaje[base]->setY(movimiento->y());
            escena->removeItem(movimiento);
            movimiento=personaje[base];
            movimiento->setX(movimiento->x()-4);
            escena->addItem(movimiento);

            //movimiento->setX(movimiento->y()); // Deshacer el movimiento
            x_o_y='z';

                        }
        else{movimiento->setX(movimiento->x()+2);}

    }}


void MainWindow::crearmapa(QGraphicsScene *escena, char tablero[31][30]){
    // Calcular el ancho y alto de cada cada cuadro en la matriz
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

 /* char MainWindow::voltear(char posicion) {
    //esta funcion elige una posicion aleatoria
    char direccionActual, nuevaDireccion;

    // Si la dirección actual es w la cambia por otra
    if (direccionActual == 'w') {
       nuevaDireccion = 's';
    }
    else if (direccionActual == 's') {
       nuevaDireccion = 'w';
    }
    else if (direccionActual == 'a') {
       nuevaDireccion = 'd';
    }
    else if (direccionActual == 'd') {
       nuevaDireccion = 'a';
    }

    return nuevaDireccion;
}


//void MainWindow::fantasmamove(int posx, int posy)
{for (int i = 0; i < 4; ++i) {
       char posicion1;
       QPointF posicion = enemigo[i]->pos();
       qreal x = posicion.x();
       qreal y = posicion.y();

       // Mover el fantasma en la dirección actual
       if (posicion1 == 'w') {
           enemigos[i]->setY(enemigos[i]->y() - 2);
       } else if (posicion1 == 's') {
           enemigos[i]->setY(enemigos[i]->y() + 2);
       } else if (posicion1 == 'a') {
           enemigos[i]->setX(enemigos[i]->x() - 2);
       } else if (posicion1 == 'd') {
           enemigos[i]->setX(enemigos[i]->x() + 2);
       }

       // Verificar si ha ocurrido una colisión con un muro
       if (colision()) {
           // Restaurar la posición anterior del fantasma
           enemigos[i]->setX(x);
           enemigos[i]->setY(y);

           char posicion = voltear();
           enemigos[i]->setDireccion(posicion);
       }
    }
} */


MainWindow::~MainWindow()
{   delete movimiento;//mirar si toca eliminar
    delete personaje[base];
    delete personaje[arriba];
    delete personaje[abajo];
    delete personaje[izquierda];
    delete personaje[derecha];
    delete escena;
    delete ui;
    delete enemigo;
    delete muro;
    delete bolita;
}
