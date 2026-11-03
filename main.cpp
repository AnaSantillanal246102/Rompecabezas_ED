//Proyecto Estructura de Datos: Rompecabezas
/*
Marlene Itzel Muñoz - 24
Ana Paula Santillan Nuñez - 246102
*/

#include <iostream>
#include <stdexcept>
#include "Estado.h"

using namespace std;

int main() {

    /*char tableroCorrecto[9] = {
        '1', '2', '3',
        '4', 'X', '6',
        '7', '5', '8'
    };

    char tableroRepetido[9] = {
        '1', '1', '3',
        '4', 'X', '6',
        '7', '5', '8'
    };

    try {

        Estado inicial(tableroCorrecto);

        cout << "Tablero valido:" << endl;
        inicial.imprimir();

        cout << "\nProbando tablero repetido:" << endl;

        Estado incorrecto(tableroRepetido);

    }
    catch (const invalid_argument& e) {

        cout << e.what() << endl;

    }
    
        char tableroInicial[9] = {
        '1', '2', '3',
        '4', 'X', '6',
        '7', '5', '8'
    };

    Estado inicial(tableroInicial);

    cout << "ESTADO INICIAL:" << endl;
    inicial.imprimir();

    char movimientos[] = {'U', 'D', 'L', 'R'};

    for (int i = 0; i < 4; i++) {

        cout << "\nMovimiento: " << movimientos[i] << endl;

        Estado* hijo = inicial.mover(movimientos[i]);

        if (hijo != nullptr) {

            hijo->imprimir();

            cout << "Movimiento registrado: "
                 << hijo->getMovimiento() << endl;

            cout << "Padre correcto: "
                 << (hijo->getParent() == &inicial ? "Si" : "No")
                 << endl;

            delete hijo;
        }
        else {
            cout << "Movimiento no valido." << endl;
        }
    }*/
    
    // ==========================================
    // PRUEBA 1: HUECO EN EL CENTRO
    // ==========================================

    cout << "==================================" << endl;
    cout << " PRUEBA 1: HUECO EN EL CENTRO" << endl;
    cout << "==================================" << endl;

    char tableroInicial[9] = {
        '1', '2', '3',
        '4', 'X', '6',
        '7', '5', '8'
    };

    Estado inicial(tableroInicial);

    cout << "\nTablero original:" << endl;
    inicial.imprimir();

    char movimientos[] = {'U', 'D', 'L', 'R'};

    for (int i = 0; i < 4; i++) {

        cout << "\nMovimiento: " << movimientos[i] << endl;

        Estado* hijo = inicial.mover(movimientos[i]);

        if (hijo != nullptr) {

            cout << "Movimiento valido." << endl;

            cout << "Tablero hijo:" << endl;
            hijo->imprimir();

            // Verificar que el padre sea el estado original
            if (hijo->getParent() == &inicial) {
                cout << "Padre correcto." << endl;
            }
            else {
                cout << "Error en el padre." << endl;
            }

            // Verificar movimiento registrado
            cout << "Movimiento registrado: "
                 << hijo->getMovimiento() << endl;

            delete hijo;
        }
        else {
            cout << "Error: movimiento no valido." << endl;
        }
    }

    // Verificar que el original no cambio
    cout << "\nTablero original despues de generar hijos:" << endl;
    inicial.imprimir();


    // ==========================================
    // PRUEBA 2: HUECO EN ESQUINA
    // ==========================================

    cout << "\n==================================" << endl;
    cout << " PRUEBA 2: HUECO EN ESQUINA" << endl;
    cout << "==================================" << endl;

    char tableroEsquina[9] = {
        'X', '1', '2',
        '3', '4', '5',
        '6', '7', '8'
    };

    Estado esquina(tableroEsquina);

    cout << "\nTablero original:" << endl;
    esquina.imprimir();

    for (int i = 0; i < 4; i++) {

        cout << "\nMovimiento: " << movimientos[i] << endl;

        Estado* hijo = esquina.mover(movimientos[i]);

        if (hijo != nullptr) {

            cout << "Movimiento valido." << endl;
            hijo->imprimir();

            cout << "Padre correcto: "
                 << (hijo->getParent() == &esquina ? "Si" : "No")
                 << endl;

            delete hijo;
        }
        else {
            cout << "nullptr: movimiento no valido." << endl;
        }
    }

    // Verificar que el tablero original sigue intacto
    cout << "\nTablero original despues de generar hijos:" << endl;
    esquina.imprimir();

    return 0;
}
