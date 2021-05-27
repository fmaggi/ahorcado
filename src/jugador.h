#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Juagdor
{
public:
    Jugador();
    Jugador(const char* nombre, intentos);

    bool probarLetra(char letra);
    void arriesgarPalabra();
private:
    char m_letrasArriesgadas[27];
    const char* m_nombre;
    int m_intentos;
}

#endif // JUGADOR_H_INCLUDED
