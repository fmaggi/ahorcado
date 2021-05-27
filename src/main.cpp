#include "juego.h"
#include <iostream>

using namespace std;

int main()
{
    int nivel, intentos;
    char nombre[20];

    cout << "Bienvenido al ahorcado\n";
    cout << "Ingrese su nombre\n";
    cin >> nombre;

    cout << nombre << ", que nivel queres jugar?: \n";
    cout << "\tNivel 1: palabras de hasta 7 letras (inclusive).\n";
    cout << "\tNivel 2: palabras de 8 a 11 letras (inclusive).\n";
    cout << "\tNivel 3: palabras de más de 11 letras.\n";
    cin >> nivel;

    cout << nombre << ", cuantos intentos queres?\n";
    cin >> intentos;

    Juego juego(nivel, intentos, nombre);

    while(juego.estaCorriendo())
    {
        juego.actualizar();
    }
}
