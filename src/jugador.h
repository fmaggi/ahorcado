#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Jugador
{
public:
    Jugador();
    Jugador(const char* nombre);

    bool probarLetra(char letra);
private:
    char m_letrasArriesgadas[26];
    const char* m_nombre;
};

#endif // JUGADOR_H_INCLUDED
