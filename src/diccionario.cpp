#include "diccionario.h"
#include <iostream>
#include <cstring>

using namespace std;

Diccionario::Diccionario(int nivel)
{
    m_palabra = "hola";
}

void Diccionario::agregarPalabra()
{
    cout << "Agregando palabra" << endl;
}

string Diccionario::getPalabra()
{
    return m_palabra;
}