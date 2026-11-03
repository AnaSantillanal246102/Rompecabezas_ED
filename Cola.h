#ifndef COLA_H
#define COLA_H
#include <iostream>
using namespace std;
const int MAXTAMQ=181441;
template <class T> class Cola {
private:

    T datos[MAXTAMQ];
    int frente;
    int final;
    int siguiente(int valor);


public:
    Cola();
    bool queue(T dato);
    T dequeue();
    bool isEmpty();
    bool isFull();
    T front();
    int size();
    void show();
    
};


#endif