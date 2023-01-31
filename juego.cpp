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
    m_color = Qt::black;
    m_width = 3;
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
    m_imagen->fill(Qt::white);
    m_circulo->setPuntoy(m_circulo->puntoy()-1);
    if(m_circulo->puntoy() >= 33){
         dibujar();
    }else{
        QMessageBox::information(this, "Aviso", "Circulo fuera del limite");
        return;
    }
}


void Juego::on_btnAbajo_released()
{
    m_imagen->fill(Qt::white);
    m_circulo->setPuntoy(m_circulo->puntoy()+1);
    if(m_circulo->puntoy() <= 350){
        dibujar();
    }else{
        QMessageBox::information(this, "Aviso", "Circulo fuera del limite");
        return;
    }
}


void Juego::on_btnIzqueirda_released()
{
    m_imagen->fill(Qt::white);
    m_circulo->setPuntox(m_circulo->puntox()-1);
    if(m_circulo->puntox() >= 12){
         dibujar();
    }else{
        QMessageBox::information(this, "Aviso", "Circulo fuera del limite");
        return;
    }
}


void Juego::on_btnDerecha_released()
{
    m_imagen->fill(Qt::white);
    m_circulo->setPuntox(m_circulo->puntox()+1);
    if(m_circulo->puntox() <= 400){
         dibujar();
    }else{
        QMessageBox::information(this, "Aviso", "Circulo fuera del limite");
        return;
    }
}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
        m_color = config->color().name();
        m_width = config->dimension();
    }
    dibujar();
}


void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar()
{
    QPen pincel;
    pincel.setWidth(m_width);
    pincel.setColor(m_color);
    pincel.setJoinStyle(Qt::MiterJoin);

    m_painter->setPen(pincel);
    m_painter->drawEllipse(m_circulo->puntox(), m_circulo->puntoy(), m_circulo->tamaño(), m_circulo->tamaño());
    update();
}

