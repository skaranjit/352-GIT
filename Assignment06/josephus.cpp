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
    int ct =0;
    cout<<"Iteration" << " ";
    cout << iteration<<endl;
    int num = position;
    
        for(int i=0;i<skip_amount-1;i++){
            num +=1;
            while (people[num] == false){
                num+=1;
                if (num >= count){
                    num = 0;
                }
            }
            
        }
        cout <<"Debuging before: "<< num<<endl;
        if (num < count){
            while (people[num]==false){
                num += 1;
            }
            cout <<"Debuging after1: "<< num<<endl;
        
        }
        else{
            num -= count;
            while (people[num]==false){
                if (num >= count){
                    num = 0;
                }
                num +=1;
            }
            cout <<"Debuging after2: "<< num<<endl;
        
        }
        cout << count<<" " << num<<endl;
        people[num] = false;
        cout <<"Person in "<<num<< " position died"<<endl;
        if(num+1 >= count){
            num = position+skip_amount - count;
            num = num -1;
        }
        position = num;
        if (position >= count){
            position = 0;
            cout << "Debuging Position: "<< position<<endl;

        }
        for (int i=0;i<count;i++){
            cout << people[i]<<endl;
        }
        while(people[position] == false){
            position +=1;
            if(position >= count){
                position = 0;
    
            }
            cout << "Debug2: "<< position<<endl;
        }
        iteration ++;
    for (int i = 0; i < count;i++){
        if(people[i] == true){
            ct ++;
        }
    }
    if (ct == 1){
        throw(JosephusException(position));
    }
}      
JosephusException::JosephusException(int which_person){
    person_index = which_person;
}
int JosephusException::who(){
    return person_index;
}
