#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include <string>
#include <fstream>

using namespace std;

class Diccionario
{
public:
    Diccionario();
    ~Diccionario();

    void setNivel(int nivel);

    string getPalabra();

    void agregarPalabra();
private:
    string m_palabra;

    ifstream m_dicFile;
    string m_path;
};

#endif // DICCIONARIO_H_INCLUDED
