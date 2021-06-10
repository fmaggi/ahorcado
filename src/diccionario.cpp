#include "diccionario.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

Diccionario::Diccionario()
{   
    m_path = "res/dicN.txt";
    m_palabra = "";
}

Diccionario::~Diccionario()
{   
}

void Diccionario::setNivel(int nivel)
{
    m_path[7] = '0' + nivel;
}

void Diccionario::agregarPalabra()
{
    cout << "Agregando palabra" << endl;
}

string Diccionario::getPalabra()
{   
    ifstream m_dicFile(m_path);
    if (!m_dicFile.is_open())
    {   
        cout << "No se pudo abrir el diccionario" << endl;
        return "";
    }

    // Primera linea del diccionario te dice cuantas palabras hay en el diccionario
    int numberOfWords;
    m_dicFile >> numberOfWords;
    srand(time(0));
    int index = rand() % numberOfWords + 1;

    for (int i = 0; i < index; i++)
    {
        if (!m_dicFile.eof())
            m_dicFile >> m_palabra;
    }
    m_dicFile.close();

    return m_palabra;
}
