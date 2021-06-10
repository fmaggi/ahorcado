#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <string>

using namespace std;

class Jugador
{
public:
    Jugador();

    void setNombre(const string& nombre);
    string& getNombre();

    void setVidas(int vidas);
    int getVidas();
	char* getLetras();
	
	
    /*
    *   Disminuye las vidas, para usar por si el jugador pierde una vida  
    */
    void operator--();
    void perdioVida();

    bool perdio();


    /*
    *   Checkea si la letra ya fue usada o no por el jugador  
    *
    *   @param letra Letra a checkear, debe ser en minusucula
    *   
    *   @returns true si la letra ya fue usada, false si no 
    */
    bool letraUsada(string letra);
	
private:
    bool m_letrasArriesgadas[26];

    int m_vidas;
    string m_nombre;
};

#endif // JUGADOR_H_INCLUDED
