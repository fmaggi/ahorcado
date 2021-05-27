#include "jugador.h"
#include "diccionario.h"

#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

class Juego
{
public:
    Juego();
    Juego(int nivel, int intentos, const char* nombre);

    ~Juego();

    void actualizar();

    bool estaCorriendo();
    void cerrar();

    bool checkLetra(char letra);

private:
    bool m_estaCorriendo;
    int m_nivel;
    const char* m_palabra;
    Jugador* m_jugador;
    Diccionario m_dic;

    void init(int nivel, int intentos, const char* nombre);
};


#endif // JUEGO_H_INCLUDED
