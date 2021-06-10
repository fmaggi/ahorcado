#include "jugador.h"
#include <cstring>

using namespace std;

Jugador::Jugador()
{   
    m_vidas = 0;
    m_nombre = "";
    memset(m_letrasArriesgadas, 0, 26);
}

void Jugador::setNombre(const string& nombre)
{
    m_nombre = nombre;
}

string& Jugador::getNombre()
{
    return m_nombre;
}

void Jugador::setVidas(int intentos)
{
    m_vidas = intentos;
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

bool Jugador::perdio()
{
    return m_vidas == 0;
}

bool Jugador::letraUsada(string letra)
{
	char temp;
	if (letra.length() > 1){
		return false;
	}
	temp = letra[0];
    int index = temp - 'a';
    if (!(m_letrasArriesgadas[index]))
    {
        m_letrasArriesgadas[index] = true;
        return false;
    }
    return true;
}
