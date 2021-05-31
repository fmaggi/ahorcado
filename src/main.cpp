#include "juego.h"
#include "diccionario.h"
#include <iostream>

using namespace std;

int main()
{
    int jugar;
    cout << "Bienvenido al ahorcado!" << endl;
    cout << "Para comenzar a jugar inrgese 1\nPara agregar una palabra al diccionario ingrese 0" << endl;
    cin >> jugar;
    if (!jugar)
    {
        Diccionario::agregarPalabra();
        return 0;
    }

    Juego juego;

    while(juego.estaCorriendo())
    {
        juego.actualizar();
    }
}