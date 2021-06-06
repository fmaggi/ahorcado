#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "jugador.h"
#include "diccionario.h"

#include <string>

class Juego
{
public:
    Juego();
    ~Juego();

    /*
    *   Inicializa el juego. Le da la opcion al usuario de comenzar una partida o agregar una palabra al diccionario.
    *   No se puede hacer en el constructor ya que devuleve un valor
    * 
    *   @returns Si el usuario decidio comenzar una partida o no. 
    */
    int init();

    /*
    * Comienza la partida. Crea el jugador y pide la palabra al diccionario.
    */
    void empezarJuego();

    void mostrar();
    void actualizar();

    bool estaCorriendo();
    void cerrar();

    bool checkLetra(char letra);

private:
    bool m_estaCorriendo;

    int m_nivel;
    int m_intentos;

    string m_palabra;
    char* m_palabraOculta;

    Jugador* m_jugador;
    Diccionario m_dic;
};


#endif // JUEGO_H_INCLUDED
