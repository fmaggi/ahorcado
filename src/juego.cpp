#include "juego.h"
#include <cstring>

using namespace std;

Juego::Juego()
{
    init(0, 0, "");
}

Juego::Juego(int nivel, int intentos, const char* nombre)
{
    init(nivel, intentos, nombre);
}

void Juego::init(int nivel, int intentos, const char* nombre)
{
    m_estaCorriendo = true;
    m_nivel = nivel;

    m_jugador = new Jugador(nombre, intentos);

    //strcpy(m_palabra, m_dic.getPalabra(nivel));
}

Juego::~Juego()
{
    delete m_jugador;
}

void Juego::actualizar()
{
}

bool Juego::estaCorriendo()
{
    return m_estaCorriendo;
}

void Juego::cerrar()
{
    m_estaCorriendo = false;
}
