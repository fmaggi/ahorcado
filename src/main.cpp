#include "juego.h"
#include <iostream>

using namespace std;

int main()
{
    Juego juego;

    while(juego.estaCorriendo())
    {
        juego.actualizar();
    }
}
