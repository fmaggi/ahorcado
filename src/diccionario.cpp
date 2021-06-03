#include "diccionario.h"
#include <iostream>

using namespace std;

Diccionario::Diccionario(int nivel)
{
    m_palabra = "palabra";
}

void Diccionario::agregarPalabra()
{
    cout << "Agregando palabra" << endl;
}

string Diccionario::getPalabra()
{
    return m_palabra;
}