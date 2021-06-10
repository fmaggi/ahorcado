#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include <string>

using namespace std;

class Diccionario
{
public:
    Diccionario();
    ~Diccionario();

    void setNivel(int nivel);

    string getPalabra();

    void agregarPalabra(const string& palabra);
private:
    string m_palabra;

    string m_path;
};

#endif // DICCIONARIO_H_INCLUDED
