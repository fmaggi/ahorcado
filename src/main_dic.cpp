#include <iostream>
#include "diccionario.h"

using namespace std;

int main()
{
    string palabra;
    cout << "Ingrese la palabra" << endl;
    cin >> palabra;

    Diccionario dic;
    dic.agregarPalabra(palabra);

    cout << "Muchas gracias" << endl;
}