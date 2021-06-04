#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include <string>

using namespace std;

class Diccionario
{
public:
    Diccionario();

    string getPalabra(int nivel);

    void agregarPalabra();
private:
    string m_palabra;
};

#endif // DICCIONARIO_H_INCLUDED
