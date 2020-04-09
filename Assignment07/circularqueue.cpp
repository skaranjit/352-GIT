#include <iostream>
#include "circularqueue.h"
<<<<<<< HEAD
#include "exception.h"
#include <cassert>
using namespace std;
template<class T>
CircularQueue<T>::CircularQueue(){
      current = new node;
      current = NULL;
      count = 0;

}
template<class T>
void CircularQueue<T>::destroyqueue(){
    node *tmp;
    tmp = new node;
    first();
    
    while (current != NULL){
        tmp = current;
        cout << "Deleting:"<<tmp->item.name;
        current = current->next;
        delete tmp;
    }
    delete current;
    count = 0;
    
}
template<class T>
CircularQueue<T>::~CircularQueue(){
    destroyqueue();
    
=======

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
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
}

template<class T>
bool CircularQueue<T>::is_empty(){
    return (current == NULL);
}

template<class T>
void CircularQueue<T>::next(){
<<<<<<< HEAD
    if(current->next != NULL){
        current = current->next;
    }
    else{
         throw(JosephusException());
    
    }
    
=======
    current = current->next;
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
}

template<class T>
void CircularQueue<T>::prev(){
<<<<<<< HEAD
    if(current->prev != NULL)
    {
        current = current->prev;
    }
     else{
        throw(JosephusException());
    
    }
=======
    current = current->prev;
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
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
<<<<<<< HEAD
   newNode->next = NULL;
   newNode->prev = current;
=======
    newNode->next = NULL;
    newNode->prev = NULL;
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
    if(is_empty()){
        current=newNode;
    }
    else{
        current->next = newNode;
<<<<<<< HEAD
       // current->next->prev = current;
    }
    count ++;
=======
    }
    

>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
}

template<class T>
void CircularQueue<T>::add_before(T& temp){
    struct node * newNode;
    newNode = new node;
    assert(newNode != NULL);
    newNode->item = temp;
<<<<<<< HEAD
    newNode->next = current;
    newNode->prev = NULL;
    if(is_empty())
    {
        current=newNode;
    }
    else
    {
        current->prev = newNode;
       
    }
    count ++;
}
template<class T>
void CircularQueue<T>::first(){
    while (current->prev!=NULL){
        current = current->prev;
    }
}
template<class T>
void CircularQueue<T>::last(){
    while(current->next != NULL){
        current = current->next;
    }
}
template<class T>
T& CircularQueue<T>::lastitem() {
    last();
    return current->item;
}

template<class T>
void CircularQueue<T>::print(){
    node * temp;
    temp= current;
    first();
    while (current->next != NULL){
        cout << current->item.name<< endl;
        current = current->next;
    }
     cout << current->item.name<< endl;
    while (current != temp){
        current = current->prev;
    }
}
template<class T>
void CircularQueue<T>::copylist(CircularQueue<T> & cq){
   
    if(current != NULL){
        cout<<"Destroying!!!"<<endl;
        destroyqueue();
        cout<<"Destroyed!!!"<<endl;
    }
    
    if (cq.is_empty())
    {
         current = NULL;
         count = 0;

    }
    else
    {
        cq.first();
        while(cq.current->next != NULL)
        {
            add_after(cq.current->item);
            try{
                next();

            }
            catch(JosephusException je){};
            cq.current = cq.current->next;

        }
        add_after(cq.current->item);
        
    }
}
template<class T>
CircularQueue<T>::CircularQueue(CircularQueue<T> & cq)
{
    copylist(cq);
}
template<class T>
CircularQueue<T> & CircularQueue<T>::operator=(CircularQueue<T> & cq)
{
    if(this != &cq){
        copylist(cq);
    }
    return *this;
}
template<class T>
int CircularQueue<T>::Size(){
    return count;
}



=======
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
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
