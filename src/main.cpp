#include "juego.h"

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