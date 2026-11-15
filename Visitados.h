#ifndef VISITADOS_H
#define VISITADOS_H

#include "Lista.h"
#include "Estado.h"

class Visitados{
private:
    Lista<Estado*> lista;
public:
    void insertar(Estado* estado);
    bool contiene(const Estado& estado);
    int size();
};

#endif
