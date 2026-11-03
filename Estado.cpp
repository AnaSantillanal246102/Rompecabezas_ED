#include "Estado.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructor
Estado::Estado(const char t[9]) {

    bool encontrados[9] = {false};
    int contadorX = 0;

    // Recorrer y validar las 9 posiciones
    for (int i = 0; i < 9; i++) {

        char ficha = t[i];

        // Copiar el tablero
        tablero[i] = ficha;

        // Validar el hueco
        if (ficha == 'X') {
            contadorX++;
        }
        // Validar que sea un numero del 1 al 8
        else if (ficha >= '1' && ficha <= '8') {

            int indice = ficha - '0';

            // Verificar si ya existe
            if (encontrados[indice]) {
                throw invalid_argument(
                    "Error: hay fichas repetidas en el tablero."
                );
            }

            encontrados[indice] = true;
        }
        else {
            throw invalid_argument(
                "Error: el tablero contiene caracteres invalidos."
            );
        }
    }

    // Verificar que exista exactamente una X
    if (contadorX != 1) {
        throw invalid_argument(
            "Error: el tablero debe contener exactamente una X."
        );
    }

    // Verificar que existan todas las fichas del 1 al 8
    for (int i = 1; i <= 8; i++) {

        if (!encontrados[i]) {
            throw invalid_argument(
                "Error: falta una o mas fichas del 1 al 8."
            );
        }
    }

    parent = nullptr;
    movimiento = ' ';
}

// Constructor de copia
Estado::Estado(const Estado& otro) {

    for (int i = 0; i < 9; i++) {
        tablero[i] = otro.tablero[i];
    }

    // No copiar el padre del otro estado
    parent = nullptr;

    // No copiar el movimiento anterior
    movimiento = ' ';
}

// Posicion del hueco
int Estado::posicionHueco() const {

    for (int i = 0; i < 9; i++) {
        if (tablero[i] == 'X') {
            return i;
        }
    }

    return -1;
}

// Comparar estados
bool Estado::esIgual(const Estado& otro) const {

    for (int i = 0; i < 9; i++) {

        if (tablero[i] != otro.tablero[i]) {
            return false;
        }
    }

    return true;
}

// Imprimir tablero
void Estado::imprimir() const {

    for (int i = 0; i < 9; i++) {

        cout << tablero[i] << " ";

        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Obtener padre
Estado* Estado::getParent() const {
    return parent;
}

// Asignar padre
void Estado::setParent(Estado* p) {
    parent = p;
}

// Obtener movimiento
char Estado::getMovimiento() const {
    return movimiento;
}

// Asignar movimiento
void Estado::setMovimiento(char m) {
    movimiento = m;
}

// Generar un nuevo estado moviendo el hueco
Estado* Estado::mover(char dir) {

    // Obtener la posicion del hueco
    int i = posicionHueco();

    // Calcular fila y columna
    int fila = i / 3;
    int col = i % 3;

    // Indice destino
    int j;

    // Determinar si el movimiento es valido
    switch (dir) {

        case 'U': // Arriba
            if (fila == 0) {
                return nullptr;
            }
            j = i - 3;
            break;

        case 'D': // Abajo
            if (fila == 2) {
                return nullptr;
            }
            j = i + 3;
            break;

        case 'L': // Izquierda
            if (col == 0) {
                return nullptr;
            }
            j = i - 1;
            break;

        case 'R': // Derecha
            if (col == 2) {
                return nullptr;
            }
            j = i + 1;
            break;

        default:
            // Direccion desconocida
            return nullptr;
    }

    // Crear una copia del estado actual
    Estado* hijo = new Estado(tablero);

    // Intercambiar el hueco con la ficha destino
    hijo->tablero[i] = hijo->tablero[j];
    hijo->tablero[j] = 'X';

    // Establecer el padre y el movimiento
    hijo->parent = this;
    hijo->movimiento = dir;

    // Regresar el nuevo estado
    return hijo;
}