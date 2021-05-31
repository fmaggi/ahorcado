#include "jugador.h"
#include <cstring>

using namespace std;

Jugador::Jugador(const string& nombre)
{
    m_nombre = nombre;
    memset(m_letrasArriesgadas, 0, 26);
}

string& Jugador::getNombre()
{
    return m_nombre;
}

bool Jugador::probarLetra(char letra)
{

}
