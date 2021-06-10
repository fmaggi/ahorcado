#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "jugador.h"
#include "diccionario.h"

#include <string>

class Juego
{
public:
    Juego();

    void mostrar();
    void actualizar();

    bool estaCorriendo();
    void cerrar();

    void checkLetra(char letra);
    void checkPalabra(string palabra);

    void mostrarResultado();

private:
    bool m_estaCorriendo;

    int m_nivel;
    int m_intentos;

    string m_palabra;
    string m_palabraOculta;
	string m_input;
	
    Jugador m_jugador;
    Diccionario m_dic;
};


#endif // JUEGO_H_INCLUDED
