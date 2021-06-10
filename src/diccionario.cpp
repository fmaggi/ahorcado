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

void Diccionario::agregarPalabra(const string& palabra)
{
    int nivel;
    if (palabra.length() <= 7)
        nivel = 1;
    else if (palabra.length() <= 11)
        nivel = 2;
    else 
        nivel = 3;

    m_path[7] = '0' + nivel;

    int numeroDepalabras;

    ifstream in(m_path);
    if (!in.is_open())
        numeroDepalabras = 0;
    else
        in >> numeroDepalabras;

    ofstream temp("res/temp.txt");
    if (!temp.is_open())
    {
        cout << "Ha habido un error" << endl;
        return;
    }
    
    numeroDepalabras++;
    temp << numeroDepalabras;
    temp << '\n';

    string line;
    while (in >> line)
    {
        line += '\n';
        temp << line;
    }
    temp << palabra;

    temp.close();
    in.close();
    rename("res/temp.txt", m_path.c_str());
}

string Diccionario::getPalabra()
{   
    ifstream m_dicFile(m_path);
    if (!m_dicFile.is_open())
    {   
        cout << "No se pudo abrir el diccionario" << endl;
        cout << "Utilice el programa del diccionario para generarlos" << endl;
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
