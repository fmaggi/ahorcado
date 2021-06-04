#include "diccionario.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

Diccionario::Diccionario()
{   
    m_palabra = "";
}

void Diccionario::agregarPalabra()
{
    cout << "Agregando palabra" << endl;
}

string Diccionario::getPalabra(int nivel)
{
    char path[] = {"res/dicN.txt"};
    char n = '0' + nivel;
    path[7] = n;

    ifstream dic(path);
    if (!dic.is_open())
    {   
        cout << "No se pudo abrir el diccionario" << endl;
        return "";
    }

    // Primera linea del diccionario te dice cuantas palabras hay en el diccionario
    int numberOfWords;
    dic >> numberOfWords;
    srand(time(0));
    int index = rand() % numberOfWords + 1;

    for (int i = 0; i < index; i++)
    {
        if (dic.eof())
            break;
        dic >> m_palabra;
    }
    dic.close();

    return m_palabra;
}