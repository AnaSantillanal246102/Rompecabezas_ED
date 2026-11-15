#ifndef ROMPECABEZAS_H
#define ROMPECABEZAS_H

#include "Estado.h"
#include "Lista.h"

class Rompecabezas {
private:
  TDA_Lista_Simple<Estado *> visitados;
  Estado *meta;
  int estadosExpandidos;

public:
  Rompecabezas();
  ~Rompecabezas();

  bool tieneSolucion(const Estado &inicial, const Estado &objetivo) const;
  bool resolver(const char inicio[9], const char objetivo[9]);
  void mostrarSolucion();

  int getEstadosExpandidos() const;
  int getEstadosVisitados();
};

#endif
