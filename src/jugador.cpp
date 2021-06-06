#include "jugador.h"
#include <cstring>

using namespace std;

Jugador::Jugador(const string& nombre, int intentos)
{   
    m_vidas = intentos;
    m_nombre = nombre;
    memset(m_letrasArriesgadas, 0, 26);
}

int Jugador::getVidas()
{
    return m_vidas;
}

void Jugador::operator--()
{
    --m_vidas;
}

void Jugador::perdioVida()
{
    --m_vidas;
}

string& Jugador::getNombre()
{
    return m_nombre;
}

bool Jugador::letraUsada(char letra)
{
    int index = letra - 'a';
    if (!(m_letrasArriesgadas[index]))
    {
        m_letrasArriesgadas[index] = true;
        return false;
    }
    return true;
}
