#include "Estado.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Estado::Estado(const char t[9]) {
	int contadorX = 0;

    // Copiar los 9 caracteres y contar las X
    for (int i = 0; i < 9; i++) {
        tablero[i] = t[i];

        if (t[i] == 'X') {
            contadorX++;
        }
    }

    // Validar que exista exactamente una X
    if (contadorX != 1) {
        throw invalid_argument(
            "Error: el tablero debe contener exactamente una X."
        );
    }

    parent = nullptr;
    movimiento = ' ';
}

int Estado::posicionHueco() const {

    for (int i = 0; i < 9; i++) {
        if (tablero[i] == 'X') {
            return i;
        }
    }

    return -1;
}

// Comparar dos estados
bool Estado::esIgual(const Estado& otro) const {

    for (int i = 0; i < 9; i++) {
        if (tablero[i] != otro.tablero[i]) {
            return false;
        }
    }

    return true;
}

// Mostrar el tablero en 3 filas
void Estado::imprimir() const {

    for (int i = 0; i < 9; i++) {

        cout << tablero[i] << " ";

        // Salto de línea cada 3 elementos
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Obtener el padre
Estado* Estado::getParent() const {
    return parent;
}

// Asignar el padre
void Estado::setParent(Estado* p) {
    parent = p;
}

// Obtener el movimiento
char Estado::getMovimiento() const {
    return movimiento;
}

// Asignar el movimiento
void Estado::setMovimiento(char m) {
    movimiento = m;
}