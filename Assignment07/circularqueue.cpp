#include <iostream>
#include "circularqueue.h"

using namespace std;
template<class T>
CircularQueue<T>::CircularQueue() {
      current = NULL;

}
template<class T>
CircularQueue<T>::~CircularQueue(){
    node * tmp;
    while (current != NULL){
        tmp = current;
        while (current != NULL){
            tmp = current;
            current=current->prev;
            delete tmp;
        }
        current = current->next;
        delete tmp;
    }
}

template<class T>
bool CircularQueue<T>::is_empty(){
    return (current == NULL);
}

template<class T>
void CircularQueue<T>::next(){
    current = current->next;
}

template<class T>
void CircularQueue<T>::prev(){
    current = current->prev;
}

template<class T>
T& CircularQueue<T>::curr(){
    return(current->item);
}

template<class T>
void CircularQueue<T>::add_after(T& temp){
    struct node * newNode;
    newNode = new node;
    assert(newNode != NULL);
    newNode->item = temp;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(is_empty()){
        current=newNode;
    }
    else{
        current->next = newNode;
    }
    

}

template<class T>
void CircularQueue<T>::add_before(T& temp){
    struct node * newNode;
    newNode = new node;
    assert(newNode != NULL);
    newNode->item = temp;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(is_empty()){
        current=newNode;
    }
    else{
        current->prev = newNode;
    }
}

// template<class T>
// CircularQueue<T>::CircularQueue(CircularQueue<T> & cq){
//     node *newNode;
//     node *currenttmp;
//     if(current != NULL){

//     }
// }