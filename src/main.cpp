#include "juego.h"

using namespace std;

int main()
{
    Juego juego;

    while(juego.estaCorriendo())
    {
        juego.mostrar();
        juego.actualizar();
    }
}