#include "juego.h"
#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;

Juego::Juego()
{
    string nombre;

    cout << "Ingrese su nombre\n";
    cin >> nombre;

    cout << nombre << ", que nivel queres jugar?: \n";
    cout << "\tNivel 1: palabras de hasta 7 letras (inclusive).\n";
    cout << "\tNivel 2: palabras de 8 a 11 letras (inclusive).\n";
    cout << "\tNivel 3: palabras de más de 11 letras.\n";
    cin >> m_nivel;

    while(m_nivel > 3 || m_nivel < 1)
    {
        cout << "Nivel incorrecto " << nombre << endl;
        cin >> m_nivel;
    }
    
	// Formula que nos da 10 intentos en el primer nivel, 8 en el segundo y 6 en el tercero
	m_intentos = 12 - m_nivel * 2;

    m_estaCorriendo = true;

    // jugador no tiene que ser un puntero
    m_jugador.setNombre(nombre);
    m_jugador.setVidas(m_intentos);

    m_dic.setNivel(m_nivel);
    m_palabra = m_dic.getPalabra();
    
    m_palabraOculta = m_palabra;
    for (int i = 0; i < m_palabra.length(); i++)
        m_palabraOculta[i] = '-';
}

void Juego::mostrar()
{
    cout << m_palabraOculta << endl << m_jugador.getVidas() << "/" << m_intentos << " intentos restantes"<< endl;
}

void Juego::actualizar()
{   
	cout << "Ingrese la letra o palabra para adivinar" << endl;
	cin >> m_input;

	if (m_input.length() > 1)
		checkPalabra(m_input);
	else
		checkLetra(m_input[0]);
	
    if (m_jugador.getEstado() != Estado::jugando) // estado puede ser jugando, gano o perdio
		cerrar();
}

void Juego::checkLetra(char letra)
{
	bool adivino = false;
	if (m_jugador.letraUsada(letra))
	{
		cout << "Ya usaste esta letra!" << endl;
		return;
	}
	for (int i = 0; i < m_palabra.length(); i++)
	{
		if (letra == m_palabra[i])
		{	
			adivino = true;
			m_palabraOculta[i] = letra;
			if (m_palabraOculta == m_palabra)
				m_jugador.setEstado(Estado::gano);
		}
	}
	if (!adivino)
		--m_jugador;
}

void Juego::checkPalabra(string palabra)
{
	if (palabra == m_palabra)
		m_jugador.setEstado(Estado::gano);
	else
		m_jugador.setEstado(Estado::perdio);
}

void Juego::mostrarResultado()
{
	if (m_jugador.getEstado() == Estado::gano)
		cout << "Felicitaciones " << m_jugador.getNombre() << ", ganaste!" << endl;
	else
	{
		cout << "Perdiste " << m_jugador.getNombre() << "! :(" << endl;
		cout << "La palabra era " << m_palabra << endl;
	}
}

bool Juego::estaCorriendo()
{
    return m_estaCorriendo;
}

void Juego::cerrar()
{
    m_estaCorriendo = false;
}
