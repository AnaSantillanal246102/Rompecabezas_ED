#ifndef NODE_H
#define NODE_H


template <class T>
class Node {
private:
  T data;
  Node<T> *next;

public:
  Node(T d);
  Node(T d, Node<T> *n);

  T getData();
  void setData(T data);

  Node<T> *getNext();
  void setNext(Node<T> *n);
};

template <class T>
Node<T>::Node(T d) {
  data = d;
  next = nullptr;
}

template <class T>
Node<T>::Node(T d, Node<T> *n) {
  data = d;
  next = n;
}

template <class T>
T Node<T>::getData() {
  return data;
}

template <class T>
void Node<T>::setData(T data) {
  this->data = data;
}

template <class T>
Node<T> *Node<T>::getNext() {
  return next;
}

template <class T>
void Node<T>::setNext(Node<T> *n) {
  next = n;
}

#endif
