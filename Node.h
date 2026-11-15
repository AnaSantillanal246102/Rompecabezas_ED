#ifndef NODE_H
#define NODE_H

template <class T> class Node {
	private:
	    T data;
	    Node<T>* next;
	
	public:
	    Node(T d);	  
	    Node(T d, Node<T> *n);
	
	    T getData();
	    void setData(T d);
	
	    Node<T>* getNext();
	    void setNext(Node<T> *n);
};


#endif