#ifndef CIRCULO_H
#define CIRCULO_H

#include <QPoint>

class Circulo : public QPoint
{
private:
    int m_puntox;
    int m_puntoy;
    int m_tamaño;
public:
    Circulo();
    Circulo(int xpos, int ypos, int tamaño);
    int puntox() const;
    void setPuntox(int newPuntox);
    int puntoy() const;
    void setPuntoy(int newPuntoy);
    int tamaño() const;
    void setTamaño(int newTamaño);
};

#endif // CIRCULO_H
