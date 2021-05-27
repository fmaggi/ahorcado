#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Jugador
{
public:
    Jugador();
    Jugador(const char* nombre, int intentos);

    bool probarLetra(char letra);
    void arriesgarPalabra();
private:
    char m_letrasArriesgadas[26];
    const char* m_nombre;
    int m_intentos;
};

#endif // JUGADOR_H_INCLUDED
