#ifndef VISITADOS_H
#define VISITADOS_H

#include "Lista.h"
#include "Estado.h"

class Visitados {
private:
    Lista<Estado*> lista;

public:

    void insertar(Estado* estado) {
        lista.insertLast(estado);
    }

    bool contiene(const Estado& estado) {
        for (int i = 0; i < lista.Size(); i++) {

            Node<Estado*>* actual = lista.get(i);

            if (actual->getData()->esIgual(estado)) {
                return true;
            }
        }

        return false;
    }

    int size() {
        return lista.Size();
    }
};

#endif