#include "juego.h"
#include <iostream>
#include <cstring>

using namespace std;

Juego::Juego()
{
    string nombre;

    cout << "Ingrese su nombre\n";
    cin >> nombre;

    cout << nombre << ", que nivel queres jugar?: \n";
    cout << "\tNivel 1: palabras de hasta 7 letras (inclusive).\n";
    cout << "\tNivel 2: palabras de 8 a 11 letras (inclusive).\n";
    cout << "\tNivel 3: palabras de más de 11 letras.\n";
    cin >> m_nivel;

    while(m_nivel > 3 || m_nivel < 1)
    {
        cout << "Nivel incorrecto " << nombre << endl;
        cin >> m_nivel;
    }

    cout << "cuantos intentos queres?\n";
    cin >> m_intentos;

    m_estaCorriendo = true;

    // jugador no tiene que ser un puntero
    m_jugador.setNombre(nombre);
    m_jugador.setVidas(m_intentos);

    m_dic.setNivel(m_nivel);
    m_palabra = m_dic.getPalabra();
    
    m_palabraOculta = m_palabra;
    for (int i = 0; i < m_palabra.length(); i++)
        m_palabraOculta[i] = '-';
}

void Juego::mostrar()
{
    cout << m_palabra << endl;
    cout << m_palabraOculta << endl << m_jugador.getVidas() << "/" << m_intentos << " intentos restantes"<< endl;
}

void Juego::actualizar()
{   
    --m_jugador;

    if (m_jugador.perdio())
    {
        cout << "Se te acabaron los intentos " << m_jugador.getNombre() << endl; 
        cerrar();
    }
}

bool Juego::estaCorriendo()
{
    return m_estaCorriendo;
}

void Juego::cerrar()
{
    m_estaCorriendo = false;
}
