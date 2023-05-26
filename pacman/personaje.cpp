#include "personaje.h"

personaje::personaje()
{

    personaje_p[n_base]=new objetos(":/base",n_ancho_sprite,n_alto_sprite);//la imagen que queremos proyectar del pacman
    movimiento = personaje_p[n_base];//paara ensayar funcion comer

    velocidad=2;//esto representa la cantidad de pixeles que avanza
    comida_t=0;//vamos a utilizar esto para los tiempos de comida
    comida=false;//quiere significar que no hay comida
    direccion='z';//significa la direccion de movimiento

    principal_personaje();

    //ahora agregamos qtimer
    //tiempo = new QTimer;
    //inicializamos el Qtimer
    //connect(tiempo,SIGNAL(timeout()),this,SLOT(mover()));//1puntero que cuenta,2 tipo de modo
            //3 clase en la que se encuentra, 4 el nombre de ejecucion que se ejecuta

    //inicializamos el conteo de qtimer
      //      x_o_y='z';
        //    tiempo->start(80);//definimos cada cuanto se repite en milisegundos

}

/*
void personaje::keyPressEvent(QKeyEvent *teclas)
{

    if (teclas->key() == Qt::Key_W) { // Arriba
        personaje_p[n_arriba]->setY(movimiento->y());//le damos la pocicion en x y y del personaje
        personaje_p[n_arriba]->setX(movimiento->x());
        movimiento=personaje_p[n_arriba];
        x_o_y='w';
        movimiento->setY(movimiento->y()-velocidad);
}

     else if (teclas->key() == Qt::Key_S) { // Abajo
        personaje_p[n_abajo]->setY(movimiento->y());//le damos la pocicion en x y y del personaje
        personaje_p[n_abajo]->setX(movimiento->x());
        movimiento=personaje_p[n_abajo];
        x_o_y='s';
        movimiento->setY(movimiento->y()+velocidad);}


     else if (teclas->key() == Qt::Key_A) { // Izquierda

        personaje_p[n_derecha]->setY(movimiento->y());//le damos la pocicion en x y y del personaje
        personaje_p[n_derecha]->setX(movimiento->x());
        movimiento=personaje_p[n_derecha];
        x_o_y='a';
        movimiento->setX(movimiento->x()-velocidad);}

     else if (teclas->key() == Qt::Key_D) { // Derecha

        personaje_p[n_izquierda]->setX(movimiento->x());
        personaje_p[n_izquierda]->setY(movimiento->y());
        movimiento=personaje_p[n_izquierda];
        x_o_y='d';
        movimiento->setX(movimiento->x()+velocidad);}


}*/

void personaje::principal_personaje()
{
    personaje_p[n_arriba]=new objetos("://arriba",n_ancho_sprite,n_alto_sprite);
    personaje_p[n_abajo]=new objetos("://abajo",n_ancho_sprite,n_alto_sprite);
    personaje_p[n_derecha]=new objetos("://derecha",n_ancho_sprite,n_alto_sprite);
    personaje_p[n_izquierda]=new objetos("://izquierda",n_ancho_sprite,n_alto_sprite);

}

objetos *personaje::get_personaje_p(int numero_p)
{
    return personaje_p[numero_p];
}

void personaje::personaje_arriba_c(char cara)
{ //delete personaje_p[n_arriba];
    if (cara=='b'){personaje_p[n_arriba]=new objetos("://arriba",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='c'){personaje_p[n_arriba]=new objetos("://arriba_c",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='C'){personaje_p[n_arriba]=new objetos("://arriba_C",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='G'){personaje_p[n_arriba]=new objetos("://arriba_G",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='F'){personaje_p[n_arriba]=new objetos("://arriba_GF",n_ancho_sprite,n_alto_sprite);}


}

void personaje::personaje_abajo_c(char cara)
{//delete personaje_p[n_abajo];
    if (cara=='b'){personaje_p[n_abajo]=new objetos("://abajo",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='c'){personaje_p[n_abajo]=new objetos("://abajo_c",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='C'){personaje_p[n_abajo]=new objetos("://abajo_C",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='G'){personaje_p[n_abajo]=new objetos("://abajo_G",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='F'){personaje_p[n_abajo]=new objetos("://abajo_GF",n_ancho_sprite,n_alto_sprite);}

}

void personaje::personaje_derecha_c(char cara)
{//delete personaje_p[n_derecha];
    if (cara=='b'){personaje_p[n_derecha]=new objetos("://derecha",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='c'){personaje_p[n_derecha]=new objetos("://derecha_c",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='C'){personaje_p[n_derecha]=new objetos("://derecha_C",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='G'){personaje_p[n_derecha]=new objetos("://derecha_G",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='F'){personaje_p[n_derecha]=new objetos("://derecha_GF",n_ancho_sprite,n_alto_sprite);}
}

void personaje::personaje_izquierda_c(char cara)
{//delete personaje_p[n_izquierda];
    if (cara=='b'){personaje_p[n_izquierda]=new objetos("://izquierda",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='c'){personaje_p[n_izquierda]=new objetos("://izquierda_c",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='C'){personaje_p[n_izquierda]=new objetos("://izquierda_C",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='G'){personaje_p[n_izquierda]=new objetos("://izquierda_G",n_ancho_sprite,n_alto_sprite);}
    else if(cara=='F'){personaje_p[n_izquierda]=new objetos("://izquierda_GF",n_ancho_sprite,n_alto_sprite);}
}



personaje::~personaje()
{
delete    personaje_p[n_base];
delete    personaje_p[n_arriba];
delete    personaje_p[n_abajo];
delete    personaje_p[n_derecha];
delete    personaje_p[n_izquierda];
}

void personaje::mover()
{/*
if(x_o_y=='w'){

    if(control_maestro::colision(movimiento->x(),movimiento->y()-velocidad,direccion)==false){
        moverV2(direccion);
    }}

else if(x_o_y=='s'){
    if(control_maestro::colision(movimiento->x(),movimiento->y()+velocidad,direccion)==false){
        moverV2(direccion);
    }
}

else if(x_o_y=='a'){

    if(control_maestro::colision(movimiento->x()-velocidad,movimiento->y(),direccion)==false){
        moverV2(direccion);
    }}

else if(x_o_y=='d'){

    if(control_maestro::colision(movimiento->x()+velocidad,movimiento->y(),direccion)==false){
        moverV2(direccion);
    }}
*/


/*
    if(x_o_y=='w'){

    movimiento->setY(movimiento->y()-velocidad);}

    else if(x_o_y=='s'){

    movimiento->setY(movimiento->y()+velocidad);}


    else if(x_o_y=='a'){

        movimiento->setX(movimiento->x()-velocidad);}

    else if(x_o_y=='d'){

            movimiento->setX(movimiento->x()+velocidad);}
*/}

void personaje::comer()
{/*comida=true;
personaje_arriba_c('c');
personaje_abajo_c('c');
personaje_izquierda_c('c');
personaje_derecha_c('c');
if(comida==true and comida_t==0){comida_t=1;
    if(direccion=='w'){personaje_arriba_c('c');}
    else if(direccion=='s'){personaje_abajo_c('c');}
    else if(direccion=='a'){personaje_izquierda_c('c');}
    else if(direccion=='d'){personaje_derecha_c('c');}
}
else if(comida==true and comida_t==1){comida_t=0;
    comida=false;
    if(direccion=='w'){personaje_arriba_c('b');}
    else if(direccion=='s'){personaje_abajo_c('b');}
    else if(direccion=='a'){personaje_izquierda_c('b');}
    else if(direccion=='d'){personaje_derecha_c('b');}
}*/}

void personaje::comer2()
{comida=true;
personaje_arriba_c('c');
personaje_abajo_c('c');
personaje_izquierda_c('c');
personaje_derecha_c('c');
comida_t=comida_t+1;
if(comida==true and comida_t==2){comida_t=0;
    comida=false;
    personaje_arriba_c('b');
    personaje_abajo_c('b');
    personaje_izquierda_c('b');
    personaje_derecha_c('b');
    /*
    if(direccion=='w'){personaje_arriba_c('b');}
    else if(direccion=='s'){personaje_abajo_c('b');}
    else if(direccion=='a'){personaje_izquierda_c('b');}
    else if(direccion=='d'){personaje_derecha_c('b');}*/
}
}
void personaje::moverV2(char direccion)
{
    if(direccion=='w'){

    movimiento->setY(movimiento->y()-velocidad);}

    else if(direccion=='s'){

    movimiento->setY(movimiento->y()+velocidad);}


    else if(direccion=='a'){

        movimiento->setX(movimiento->x()-velocidad);}

    else if(direccion=='d'){

            movimiento->setX(movimiento->x()+velocidad);}
}
