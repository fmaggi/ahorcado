#include "juego.h"
#include "diccionario.h"
#include <iostream>

using namespace std;

int main()
{
    Juego juego;

    int jugar = juego.init();
    if (!jugar)
        return 0;

    juego.empezarJuego();

    while(juego.estaCorriendo())
    {
        juego.mostrar();
        juego.actualizar();
    }
}