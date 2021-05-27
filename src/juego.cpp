#include "juego.h"
#include <cstring>
#include <iostream>

using namespace std;

Juego::Juego()
{
    char nombre[20];

    cout << "Bienvenido al ahorcado\n";
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

    cout << cuantos intentos queres?\n";
    cin >> m_intentos;

    m_estaCorriendo = true;

    m_jugador = new Jugador(nombre);

    //strcpy(m_palabra, m_dic.getPalabra(m_nivel));
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
