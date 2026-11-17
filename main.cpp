// Proyecto Estructura de Datos: Rompecabezas
/*
Marlene Itzel Muñoz - 247554
Ana Paula Santillan Nuñez - 246102
*/
#include "Rompecabezas.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

using namespace std;

bool leerTablero(const string &mensaje, char tablero[9]);

const char OBJETIVO[9] = {
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', 'X'};

void probarTablero(const char tablero[9], const char objetivo[9]) {
  try {
    Rompecabezas juego;
    bool resuelto = juego.resolver(tablero, objetivo);  //entrada objetivo por teclado

    if (resuelto) {
      juego.mostrarSolucion();
    } else {
      cout << "Este tablero NO tiene solucion." << endl;
    }

    cout << "Estados expandidos: " << juego.getEstadosExpandidos() << endl;
    cout << "Estados visitados:  " << juego.getEstadosVisitados() << endl;
  } catch (const invalid_argument &error) {
    cout << error.what() << endl;
  }
}

void probarTablero(const char tablero[9]) {
  try {
    Rompecabezas juego;

    bool resuelto = juego.resolver(tablero, OBJETIVO);

    if (resuelto) {
      juego.mostrarSolucion();
    } else {

      cout << "Este tablero NO tiene solucion." << endl;
    }

    cout << "Estados expandidos: " << juego.getEstadosExpandidos() << endl;
    cout << "Estados visitados:  " << juego.getEstadosVisitados() << endl;
  } catch (const invalid_argument &error) {
    cout << error.what() << endl;
  }
}

int main() {
  const int NUM_PRUEBAS = 7;
  const char pruebas[NUM_PRUEBAS][10] = {
      "1234X6758", // 2 movimientos
      "X23146758", // 4 movimientos
      "4128X3765", // 10 movimientos
      "8641X2753", // 18 movimientos
      "2134X5678", // sin solucion
      "12345678X", // 0 movimientos
      "1234X6755"  // falta el 8 y el 5 se repite
  };

  int opcion;
  do {
    cout << "\n===== ROMPECABEZAS DE 8 PIEZAS =====" << endl;
    cout << "1. Correr tableros de prueba" << endl;
    cout << "2. Escribir mi propio tablero" << endl;
    cout << "3. Ingresar un objetivo contra el que comparar" << endl;
    cout << "0. Salir" << endl;
    cout << "Opcion: ";

    cin >> opcion;

    if (opcion == 1) {
      for (int i = 0; i < NUM_PRUEBAS; i++) {
        cout << "\n----- Prueba " << i + 1 << ": " << pruebas[i] << " -----" << endl;
        probarTablero(pruebas[i]);
      }
    } else if (opcion == 2) {
      string entrada;
      cout << "Escribe las 9 casillas por filas, sin espacios (ej. 1234X6758): ";
      cin >> entrada;

      if (entrada.length() != 9) {
        cout << "Error: deben ser exactamente 9 caracteres." << endl;
      } else {
        char tablero[9];
        for (int i = 0; i < 9; i++) {
          tablero[i] = toupper(entrada[i]);
        }
        cout << endl;
        probarTablero(tablero);
  		}
	} else if (opcion == 3) {
	    char inicial[9];
	    char objetivo[9];
	
	    if (leerTablero("Tablero inicial (ej. 1234X6758): ", inicial) &&
	        leerTablero("Tablero objetivo (ej. 87654321X): ", objetivo)) {
	        cout << endl;
	        probarTablero(inicial, objetivo);
	    }
	
	} else if (opcion != 0) {
	    cout << "Opcion no valida." << endl;
	}
  } while (opcion != 0);
}

bool leerTablero(const string &mensaje, char tablero[9]){
  string entrada;
  cout << mensaje;
  cin >> entrada;

  if (entrada.length() != 9) {
    cout << "Error: deben ser exactamente 9 caracteres." << endl;
    return false;
  }

  for (int i = 0; i < 9; i++) {
    tablero[i] = toupper(entrada[i]);
  }
  return true;
}
