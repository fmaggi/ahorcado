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

string& Jugador::getNombre()
{
    return m_nombre;
}

bool Jugador::probarLetra(char letra)
{

}
