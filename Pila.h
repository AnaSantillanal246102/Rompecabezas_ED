#ifndef PILA_H
#define PILA_H

const int TAM = 35;
const int INITIAL_VALUE = 0;

template <class T>
class TDA_Stack {
private:
  int TOP;
  T arrStack[TAM];

public:
  TDA_Stack();

  bool Push(T elemento);
  T Pop();
  bool isEmpty();
  bool isFull();
};

#endif
