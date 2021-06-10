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
    --m_jugador;
	
	cout << "Ingrese la letra o palabra para adivinar" << endl;
	cin >> m_input;
	
	while(m_jugador.letraUsada(m_input)){
		cout << "La letra ya fue usada, elija otra" << endl;
		cin >> m_input;
	}
	
	if (m_input.length() > 1){
		if(m_input == m_palabra){
			m_jugador.setVidas(-1);
		}
		else{
			m_jugador.setVidas(0);
		}
	};
	
	if(m_palabra.find(m_input) != string::npos){
		for(int i = 0; i < m_palabra.length(); i++){
			if(m_palabra[i] == m_input[0]){
				m_palabraOculta[i] = m_palabra[i];
			}
		}
	}
	
	else{
		cout << "Letra Incorrecta!" <<endl;
	}
	
	if(m_palabraOculta == m_palabra){
		m_jugador.setVidas(-1);
	}
	
    if (m_jugador.getVidas() <= 0)
    {
		if (m_jugador.getVidas() == 0){
			cout << "Se te acabaron los intentos " << m_jugador.getNombre() << endl; 
			cerrar();
		}
		else{
			cout << "Felicidades " << m_jugador.getNombre() << ". Ganaste!!!!" <<endl;
			cerrar();
		}
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
