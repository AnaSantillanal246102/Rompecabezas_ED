#include "Lista.h"
#include "Node.h"
#include <iostream>
#include "Estado.h"

using namespace std;

template <class T> Lista<T>::Lista(){
    head = nullptr;
    size = 0;
}

template <class T> Lista<T>::~Lista(){
    cout<<"-- DESTRUCTOR --"<<endl;
	this->deleteList();
}

template <class T> void Lista<T>::insertFirst(T data){
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(head);
    head = newNode;
    size++;
}

template <class T> void Lista<T>::insertLast(T data){
    if (head == nullptr) {
        this->insertFirst(data);
        return;
    }
    Node<T> *last = this->getLast();
    last->setNext(new Node<T>(data));
    size++;
}

template <class T> void Lista<T>::insertAfter(Node<T> *previous, T data){
    /*if (previous == nullptr){
    	//this->insertLast(data);
        return;
    }*/
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(previous->getNext());
    previous->setNext(newNode);
    size++;
}

template <class T> Node<T> *Lista<T>::getLast(){
    Node<T> *p = head;
    if (p == nullptr) {
    	throw "Error, lista vacia";
        //return nullptr;
    }
    while (p->getNext() != nullptr) {
        p = p->getNext();
    }
    return p;
}

template <class T> Node<T> *Lista<T>::search(T data){
    Node<T> *index = head;
    for(index = head; index != nullptr; index= index->getNext()){
        if (data == index->getData()){
            return index;
        }
    }
    return NULL;
}

template <class T> Node<T> *Lista<T>::get(int position){
    if (position < 0 || position >= size) {
        return nullptr;
    }
    Node<T> *aux = head;
    for (int i = 0; i < position; i++) {
        aux = aux->getNext();
    }
    return aux;
}

template <class T> void Lista<T>::deleteNode(T data){
    /*if (head == nullptr) {
        return;
    }*/
	Node<T> *actual, *previous;
	bool found;
	actual = head;
	previous = nullptr;
	found = false;
	
	while((actual != nullptr) && !found){
		found = (actual -> getData() == data);
		if (!found){
			previous = actual;
			actual = actual -> getNext();
		}
	}
	if (actual != nullptr){
		if (actual == head ){
			head = actual -> getNext();
		}else{
			previous ->setNext(actual->getNext());
		}
		size--;
		delete actual;
	}

}

template <class T> bool Lista<T>::isEmpty(){

    return head == nullptr;
}

template <class T> void Lista<T>::deleteList() {
    Node<T> *current = head;
	Node <T> *next;
	cout<<"-- Destruyendo lista --"<<endl;
    while (current != nullptr) {
        next = current->getNext();
		cout<<"\tDestruyendo:"<<current->getData()<<endl;
        delete current;
		current = next;
    }

    head = nullptr;
    size = 0;
}

template <class T>void Lista<T>::print(){
    Node<T> *aux = head;
    while (aux!=nullptr) {
        cout<<aux->getData()<<" ";
        aux=aux->getNext();
    }
    cout<<endl;
}

template <class T> int Lista<T>::Size(){
    return size;
}

template class Lista<int>;
template class Lista<float>;
template class Lista<char>;
template class Lista<Estado*>;
