#ifndef LISTA_H
#define LISTA_H

#include "Node.h"

template <class T>
class TDA_Lista_Simple {
private:
  Node<T> *head;
  int size;

public:
  TDA_Lista_Simple();
  ~TDA_Lista_Simple();

  void insertFirst(T data);
  Node<T> *search(T data);
  Node<T> *Front();
  int getSize();
};

#endif
