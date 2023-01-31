#include "circulo.h"

int Circulo::puntox() const
{
    return m_puntox;
}

void Circulo::setPuntox(int newPuntox)
{
    m_puntox = newPuntox;
}

int Circulo::puntoy() const
{
    return m_puntoy;
}

void Circulo::setPuntoy(int newPuntoy)
{
    m_puntoy = newPuntoy;
}

int Circulo::tamaño() const
{
    return m_tamaño;
}

void Circulo::setTamaño(int newTamaño)
{
    m_tamaño = newTamaño;
}

Circulo::Circulo()
{
    m_puntox = 40;
    m_puntoy = 40;
    m_tamaño = 80;
}

Circulo::Circulo(int xpos, int ypos, int tamaño)
{
    this->m_puntox = xpos;
    this->m_puntoy = ypos;
    this->m_tamaño = tamaño;
}
