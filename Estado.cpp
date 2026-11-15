#include "Estado.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Estado::Estado(const char t[9]) {

  bool encontrados[9] = {false};
  int contadorX = 0;

  for (int i = 0; i < 9; i++) {

    char ficha = t[i];

    tablero[i] = ficha;

    if (ficha == 'X') {
      contadorX++;
    }

    else if (ficha >= '1' && ficha <= '8') {

      int indice = ficha - '0';

      if (encontrados[indice]) {
        throw invalid_argument(
            "Error: hay fichas repetidas en el tablero.");
      }

      encontrados[indice] = true;
    } else {
      throw invalid_argument(
          "Error: el tablero contiene caracteres invalidos.");
    }
  }

  if (contadorX != 1) {
    throw invalid_argument(
        "Error: el tablero debe contener exactamente una X.");
  }

  for (int i = 1; i <= 8; i++) {

    if (!encontrados[i]) {
      throw invalid_argument(
          "Error: falta una o mas fichas del 1 al 8.");
    }
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

bool Estado::esIgual(const Estado &otro) const {

  for (int i = 0; i < 9; i++) {

    if (tablero[i] != otro.tablero[i]) {
      return false;
    }
  }

  return true;
}

void Estado::imprimir() const {

  for (int i = 0; i < 9; i++) {

    cout << tablero[i] << " ";

    if ((i + 1) % 3 == 0) {
      cout << endl;
    }
  }
}

Estado *Estado::getParent() const {
  return parent;
}

char Estado::getMovimiento() const {
  return movimiento;
}

Estado *Estado::mover(char dir) {

  int i = posicionHueco();

  // Calcular fila y columna
  int fila = i / 3;
  int col = i % 3;

  // Indice destino
  int j;

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
    return nullptr;
  }

  Estado *hijo = new Estado(tablero);

  // Intercambiar el hueco con la ficha destino
  hijo->tablero[i] = hijo->tablero[j];
  hijo->tablero[j] = 'X';

  // Establecer el padre, el movimiento
  hijo->parent = this;
  hijo->movimiento = dir;

  return hijo;
}

// Una inversion es un par de fichas donde la mayor aparece antes que la menor.
int Estado::contarInversiones() const {

  int inversiones = 0;

  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {

      if (tablero[i] != 'X' && tablero[j] != 'X' && tablero[i] > tablero[j]) {
        inversiones++;
      }
    }
  }

  return inversiones;
}
