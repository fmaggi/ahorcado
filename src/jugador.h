#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <string>

using namespace std;

class Jugador
{
public:
    Jugador(const string& nombre);

    string& getNombre();

    bool probarLetra(char letra);
private:
    bool m_letrasArriesgadas[26];
    string m_nombre;
};

#endif // JUGADOR_H_INCLUDED
