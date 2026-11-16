#include "Rompecabezas.h"
#include "Cola.h"
#include "Pila.h"
#include <iostream>

using namespace std;

Rompecabezas::Rompecabezas() {
  meta = nullptr;
  estadosExpandidos = 0;
}

Rompecabezas::~Rompecabezas() {
  Node<Estado *> *aux = visitados.Front();

  while (aux != nullptr) {
    delete aux->getData();
    aux = aux->getNext();
  }
}

bool Rompecabezas::tieneSolucion(const Estado &inicial, const Estado &objetivo) const {
  return inicial.contarInversiones() % 2 == objetivo.contarInversiones() % 2;
}

bool Rompecabezas::resolver(const char inicio[9], const char fin[9]) {
  Estado objetivo(fin);
  Estado *inicial = new Estado(inicio);

  visitados.insertFirst(inicial);

  if (!tieneSolucion(*inicial, objetivo)) {
    return false;
  }

  if (inicial->esIgual(objetivo)) {
    meta = inicial;
    return true;
  }

  Cola<Estado *> *frontera = new Cola<Estado *>();
  frontera->queue(inicial);

  char direcciones[4] = {'U', 'D', 'L', 'R'};

  while (!frontera->isEmpty()) {
    Estado *actual = frontera->dequeue();
    estadosExpandidos++;

    for (int i = 0; i < 4; i++) {
      Estado *hijo = actual->mover(direcciones[i]);

      if (hijo == nullptr) {
        continue;
      }

      if (visitados.search(hijo) != nullptr) {
        delete hijo;
        continue;
      }

      visitados.insertFirst(hijo);

      if (hijo->esIgual(objetivo)) {
        meta = hijo;
        delete frontera;
        return true;
      }

      frontera->queue(hijo);
    }
  }

  delete frontera;
  return false;
}

void Rompecabezas::mostrarSolucion() {
  if (meta == nullptr) {
    cout << "No hay solucion." << endl;
    return;
  }

  TDA_Stack<Estado *> camino;
  Estado *e = meta;
  while (e != nullptr) {
    camino.Push(e);
    e = e->getParent();
  }

  int paso = 0;
  while (!camino.isEmpty()) {
    Estado *actual = camino.Pop();

    if (paso == 0) {
      cout << "Inicio:" << endl;
    } else {
      cout << "Paso " << paso << ": mover X hacia ";
      switch (actual->getMovimiento()) {
      case 'U':
        cout << "ARRIBA";
        break;
      case 'D':
        cout << "ABAJO";
        break;
      case 'L':
        cout << "IZQUIERDA";
        break;
      case 'R':
        cout << "DERECHA";
        break;
      }
      cout << endl;
    }

    actual->imprimir();
    cout << endl;
    paso++;
  }

  cout << "Total de movimientos: " << paso - 1 << endl;
}

int Rompecabezas::getEstadosExpandidos() const {
  return estadosExpandidos;
}

int Rompecabezas::getEstadosVisitados() {
  return visitados.getSize();
}
