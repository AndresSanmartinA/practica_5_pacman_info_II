#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "objetos.h"
#include "personaje.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);//esto biene por defecto y va de primmerito
    escena=new QGraphicsScene ;//esta se encarga lo que vamos a ver en Gviu

    //definimos las dimenciones de la escena
    int x_inicial=0,y_inicial=0;//el sistema de referencia inicial
    //definimos el tamaño de la escena
    int ancho, alto;//hacedemos a la careterisrica de ancho y alto de gviw
    //tambien le podemos asiganar tamaño de la siguiente manera

    ancho=ui->graphicsView->width();
    alto=ui->graphicsView->height();
    escena->setSceneRect(x_inicial,y_inicial,ancho-2,alto-2);//le restamos 2 bits en los bordos para que no aparezcan scrolls


    control_maestro_p = new control_maestro(this);
    control_maestro_p->agregarMovimiento();

}
void MainWindow::keyPressEvent(QKeyEvent* event)
{
    // Pasamos el evento de la tecla presionada al control maestro
    control_maestro_p->keyPressEvent(event);
}
void MainWindow::tamaño_de_la_escena(int x_inc,int y_inc,int ancho,int alto)
{
        escena->setSceneRect(x_inc, y_inc, ancho, alto);

        // Establecer el tamaño deseado para QGraphicsView
        ui->graphicsView->setFixedSize(ancho+2, alto+2);//le sumamos para evitar los escrolls

        // Cargar la escena en QGraphicsView
        ui->graphicsView->setScene(escena);
}

void MainWindow::agg_a_escena(objetos *item)
{
    escena->addItem(item);
}

void MainWindow::dll_de_escena(objetos *item)
{
    escena->removeItem(item);
}

void MainWindow::actualizar_escena()
{
    // Cargar la escena en QGraphicsView
    ui->graphicsView->setScene(escena);
}


MainWindow::~MainWindow()
{

    delete escena;
    delete ui;
}

QGraphicsScene *MainWindow::getEscena()
{
    return escena;
}

Ui::MainWindow *MainWindow::getUI()
{
return ui;
}
