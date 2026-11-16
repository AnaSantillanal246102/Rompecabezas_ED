#include "Lista.h"
#include "Estado.h"

template <class T>
TDA_Lista_Simple<T>::TDA_Lista_Simple() {
  head = NULL;
  size = 0;
}

template <class T>
TDA_Lista_Simple<T>::~TDA_Lista_Simple() {
  Node<T> *aux = head;

  while (aux != NULL) {
    Node<T> *sig = aux->getNext();
    delete aux;
    aux = sig;
  }
}

template <class T>
void TDA_Lista_Simple<T>::insertFirst(T data) {
  Node<T> *newNode;
  newNode = new Node<T>(data);
  newNode->setNext(head);
  head = newNode;
  size++;
}

template <class T>
Node<T> *TDA_Lista_Simple<T>::search(T data) {
  Node<T> *index = head;

  while (index != NULL) {
    if (index->getData()->esIgual(*data)) {
      return index;
    }
    index = index->getNext();
  }

  return NULL;
}

template <class T>
Node<T> *TDA_Lista_Simple<T>::Front() {
  return head;
}

template <class T>
int TDA_Lista_Simple<T>::getSize() {
  return size;
}

template class TDA_Lista_Simple<Estado *>;
