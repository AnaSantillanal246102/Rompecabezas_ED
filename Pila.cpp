#include "Pila.h"
#include "Estado.h"

template <class T>
TDA_Stack<T>::TDA_Stack() {
  TOP = INITIAL_VALUE;
}

template <class T>
bool TDA_Stack<T>::isEmpty() {
  return TOP == INITIAL_VALUE;
}

template <class T>
bool TDA_Stack<T>::isFull() {
  return TOP == TAM - 1;
}

template <class T>
bool TDA_Stack<T>::Push(T elemento) {
  if (isFull())
    return false;

  arrStack[TOP++] = elemento;

  return true;
}

template <class T>
T TDA_Stack<T>::Pop() {
  if (isEmpty())
    throw "POP no realizado por pila vacia";

  T aux;
  aux = arrStack[--TOP];

  return aux;
}

template class TDA_Stack<Estado *>;
