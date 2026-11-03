#include "Cola.h"
#include <iostream>

using namespace std;

template <class T> int Cola<T>::siguiente(int valor) {
    return (valor + 1) % MAXTAMQ;
}

template <class T> Cola<T>::Cola() {
    frente = 0;
    final = 0;
}

template <class T> bool Cola<T>::queue(T dato) {
    if (isFull()) {
        cout<<"La cola esta llena"<<endl;
        return false;
    }
    datos[final]=dato;
    final=siguiente(final);
    return true;
}

template <class T> T Cola<T>::dequeue() {
    if (isEmpty()) {
        cout<<"La cola esta vacia"<<endl;
        return T();
    }
    T dato=datos[frente];
    frente=siguiente(frente);
    return dato;
}

template <class T> bool Cola<T>::isEmpty() {
    return frente==final;
}

template <class T> bool Cola<T>::isFull() {
    return siguiente(final)==frente;
}

template <class T> T Cola<T>::front() {
	if (isEmpty()) {
        cout<<"La cola esta vacia"<<endl;
        return T();
    }
    return datos[frente];
}

template <class T>void Cola<T>::show() {
    int i=frente;
    while (i!=final){
        cout<<datos[i]<<" ";
        i=siguiente(i);
    }
    cout<<endl;
}

template <class T> int Cola<T>::size() {
    if (final>=frente) {
        return final-frente;
    }
    return MAXTAMQ-frente+final;
}

template class Cola<int>;
template class Cola<float>;
template class Cola<char>;

