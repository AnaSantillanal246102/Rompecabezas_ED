//Proyecto Estructura de Datos: Rompecabezas
/*
Marlene Itzel Muñoz - 24
Ana Paula Santillan Nuñez - 246102
*/
#include <iostream>
#include "Estado.h"

using namespace std;

int main(int argc, char** argv) {
    // Crear el tablero inicial
    char tableroInicial[9] = {
        '1', '2', '3',
        '4', 'X', '6',
        '7', '5', '8'
    };

    // Crear el tablero objetivo
    char tableroObjetivo[9] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', 'X'
    };

    // Crear los estados
    Estado inicial(tableroInicial);
    Estado objetivo(tableroObjetivo);

    // Imprimir estado inicial
    cout << "===== ESTADO INICIAL =====" << endl;
    inicial.imprimir();

    cout << "Posicion del hueco: "
         << inicial.posicionHueco() << endl;

    // Imprimir estado objetivo
    cout << "\n===== ESTADO OBJETIVO =====" << endl;
    objetivo.imprimir();

    cout << "Posicion del hueco: "
         << objetivo.posicionHueco() << endl;

    // Comparar ambos estados
    cout << "\n===== COMPARACIONES =====" << endl;

    cout << "Inicial es igual al objetivo: "
         << (inicial.esIgual(objetivo) ? "true" : "false")
         << endl;

    cout << "Inicial es igual a si mismo: "
         << (inicial.esIgual(inicial) ? "true" : "false")
         << endl;

    cout << "Objetivo es igual a si mismo: "
         << (objetivo.esIgual(objetivo) ? "true" : "false")
         << endl;

	return 0;
}