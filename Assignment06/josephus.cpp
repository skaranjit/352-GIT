#include "josephus.h"
#include <iostream>
#include <array>

using namespace JosephusProblem;
using namespace std;

Josephus::Josephus(int number_of_people,int skip){
    count = number_of_people;
    skip_amount = skip;
    position = 0;
    iteration = 0;
    people = new bool [count];
    for (int i = 0; i <count ; i++){
        people[i] = true;
    }

}
Josephus::Josephus(const Josephus & original){
    this->people = original.people;
    this->skip_amount = original.skip_amount;
    this->position = original.position;
    this->iteration = original.iteration;
    this->count = original.count;

}
Josephus::~Josephus(){
    if (people == nullptr){
        delete[] people;
    }
}
Josephus & Josephus::operator=(const Josephus & original){
    this->people = original.people;
    this->skip_amount = original.skip_amount;
    this->position = original.position;
    this->iteration = original.iteration;
    this->count = original.count;
    return *this;
    // Josephus j2(1);
    // *this.skip_amount = original.skip_amount;
    // j2.position = original.position;
    // j2.iteration = original.iteration;
    // j2.count = original.count;
    // j2.people = new bool [j2.count];
    // return j2;

}
bool Josephus::is_alive(int who) const{
    return people[who];
}

int Josephus::size() const{
    return (count);
    
}

void Josephus::iterate(){
    
    cout<<"Iteration" << "";
    cout << this->size();
    cout << "Debug"<<endl;
    int num = 0;
    int ct = count;

    while (ct > 1){
        while(people[position] == false){
            position +=1;
            if(position > count){
                position = 0;
            }
        }
        if(num == (skip_amount -1)){
            people[position] = false;
            cout << "Person number " << position << " is out."<<endl;
            ct --;
        }
        num ++;
        if (num == skip_amount){
            num = 0;
        }
        position ++;
        if (position == count){
            position =0;
        }
        }
    for (int i = 0; i < count;i++){
        if(people[i] == true){
            throw(JosephusException(i));
        }
    } 
}      
JosephusException::JosephusException(int which_person){
    person_index = which_person;
}
int JosephusException::who(){
    return person_index;
}
