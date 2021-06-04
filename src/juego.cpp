#include "juego.h"
#include <iostream>
#include <cstring>

using namespace std;

Juego::Juego()
{
    bool m_estaCorriendo = false;

    int m_nivel = 0;
    int m_intentos = 0;

    string m_palabra = "";
    m_palabraOculta = nullptr;

    m_jugador = nullptr;
    m_dic = new Diccionario();
}

Juego::~Juego()
{
    if (m_jugador != nullptr)
        delete m_jugador;


    delete m_dic;

    if (m_palabraOculta != nullptr)
        delete[] m_palabraOculta;
}

int Juego::init()
{
    int jugar;
    cout << "Bienvenido al ahorcado!" << endl;
    cout << "Para comenzar a jugar inrgese 1\nPara agregar una palabra al diccionario ingrese 0" << endl;
    cin >> jugar;
    if (!jugar)
    {
        m_dic->agregarPalabra();
        cout << "Para salir ingrese 0\nPara empezar una partida ingrese 1" << endl;
        cin >> jugar;
    }
    return jugar;
}

void Juego::empezarJuego()
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

    m_palabra = m_dic->getPalabra(m_nivel);
    
    m_palabraOculta = new char[m_palabra.length() + 1];
    memset(m_palabraOculta, '-', m_palabra.length());
    m_palabraOculta[m_palabra.length()] = '\0';
}

void Juego::mostrar()
{
    cout << m_palabra << endl;
    cout << m_palabraOculta << "      "  << endl << m_jugador->getVidas() << "/" << m_intentos << " intentos restantes"<< endl;
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
