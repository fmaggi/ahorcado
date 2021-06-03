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

    m_jugador = new Jugador(nombre, m_intentos);
    m_dic = new Diccionario(m_nivel);

    m_palabra = m_dic->getPalabra();

    m_palabraOculta = new char[m_palabra.length()];
    memset(m_palabraOculta, '-', m_palabra.length());
}

Juego::~Juego()
{
    delete m_jugador;
    delete m_dic;
    delete[] m_palabraOculta;
}

void Juego::mostrar()
{
    cout << m_palabraOculta << "      " << m_jugador->getVidas() << "/" << m_intentos << " intentos restantes"<< endl;
}

void Juego::actualizar()
{   
    cerrar();
}

bool Juego::estaCorriendo()
{
    return m_estaCorriendo;
}

void Juego::cerrar()
{
    m_estaCorriendo = false;
}
