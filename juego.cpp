#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    m_circulo = new Circulo;
    m_imagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    m_imagen->fill(Qt::white);
    m_painter = new QPainter(m_imagen);
    m_painter->setRenderHint(QPainter::Antialiasing);

    this->dibujar();
}

Juego::~Juego()
{
    delete ui;
}

void Juego::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //Dibujar la imagen
    painter.drawImage(0,0,*m_imagen);
    //Aceptar el evento
    event->accept();
}


void Juego::on_btnArriba_released()
{

}


void Juego::on_btnAbajo_released()
{

}


void Juego::on_btnIzqueirda_released()
{

}


void Juego::on_btnDerecha_released()
{

}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar()
{
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::black);
    pincel.setJoinStyle(Qt::MiterJoin);

    m_painter->setPen(pincel);
    m_painter->drawEllipse(m_circulo->puntox(), m_circulo->puntoy(), m_circulo->tamaño(), m_circulo->tamaño());
    update();
}

