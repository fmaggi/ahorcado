#include "jugador.h"
#include "diccionario.h"

#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

class Juego
{
public:
    Juego();
    Juego(int nivel, int intentos);

    void actualizar();

    void estaCorriendo();
    void cerrar();

    bool checkLetra(char letra);

private:
    bool m_estaCorriendo;
    int m_nivel;
    const char* m_palabra;
    Jugador m_jugador;
    Diccionario m_dic;
}


#endif // JUEGO_H_INCLUDED
