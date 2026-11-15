#ifndef LISTA_H
#define LISTA_H

#include "Node.h"
template <class T> class Lista{
	private:
		Node<T> *head;
		int size;
	public:
		Lista(); 
		~Lista();
		void insertFirst(T data); void insertLast (T data);
		void insertAfter (Node<T> *previous, T data);
		Node<T> *getLast();
		Node<T> *search (T data);
		Node<T> *get(int position);
		void deleteNode(T data);
		bool isEmpty();
		void deleteList();
		void print();
		int Size();

};
#endif