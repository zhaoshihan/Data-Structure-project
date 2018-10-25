/*
 * Node.h
 *
 *  Created on: 2017Äê10ÔÂ18ÈÕ
 *      Author: Administrator
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

using namespace std;

template<class T>
class Node
{
    public:
        Node();
        Node(const T& item, Node<T>* ptrnext = NULL);
        T data;
        // access to the next node
        Node<T>* NextNode();
        // list modification methods
        void InsertAfter(Node<T>* p);
        Node<T>* DeleteAfter();
        Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL);
    private:
        Node<T> * next;
};



#endif /* NODE_H_ */
