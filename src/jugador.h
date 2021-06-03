#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <string>

using namespace std;

class Jugador
{
public:
    Jugador(const string& nombre, int intentos);

    string& getNombre();
    int getVidas();

    bool probarLetra(char letra);
private:
    bool m_letrasArriesgadas[26];

    int m_vidas;
    string m_nombre;
};

#endif // JUGADOR_H_INCLUDED
