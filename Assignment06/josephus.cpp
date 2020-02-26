#include "josephus.h"
#include <iostream>
using namespace JosephusProblem;
using namespace std;

Josephus::Josephus(int number_of_people,int skip){
    count = number_of_people;
    skip_amount = skip;
    position = 0;
    iteration = 1;
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
    return count;
}

void Josephus::iterate(){
    for (iteration;iteration<=count;iteration++){
        position = (position+skip_amount)%iteration;
    }

    // while (ct > 1){
    //     if(position >= ct){
    //         position = 0;
    //     }
    //     if ( iteration == skip_amount){
    //         iteration = 1;
    //         people[position] = false;
    //         ct -=1;
    //     }
    //     else{
    //         position++;
    //         iteration++;
    //     }
    // }
    for (int i = 0;i<count;i++){
        if(i != position){
            people[i] = false;
        }
    }
    for(int i = 0;i<count;i++){
        cout<<people[i]<<endl;
    }
    throw (JosephusException(position+1));

}
JosephusException::JosephusException(int which_person){
    person_index = which_person;
}
int JosephusException::who(){
    return person_index;
}
