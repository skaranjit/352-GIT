#include <iostream>
#include "person.h"
<<<<<<< HEAD
#include "circularqueue.cpp"
#include <list>
#include <fstream>
using namespace std;
void iterate();
int main() {
	CircularQueue<Person> queue;
	cout << "Which file should we read the names from?" << endl;
	string filename;
	cin >> filename;
	Person p1;
	cout << queue.is_empty()<<endl; //queue is empty returns 1;
	ifstream inFile;
	inFile.open(filename);
	if(!inFile){
		cerr << "Unable to open file "<<filename<<endl;
		exit(1);
	}
	string name;
	int ct = 1;
	while (getline(inFile,name)){
		cout << "Running for "<<ct<<endl;
		p1.name = name;
		p1.alive = true;
		queue.add_after(p1);
		try{queue.next();}
		catch(JosephusException je){}
		ct++;
	}
	inFile.close();
	cout << "Debug 1 COmplete"<<endl;
	
	
	queue.first();
	queue.print();
	//cout<<queue.curr().name<<endl;

	
=======
#include "circularqueue.h"
using namespace std;

int main() {
	CircularQueue<Person> people;
	cout << "Which file should we read the names from?" << endl;
	string filename;
	cin >> filename;
	Person p1 = {"Suman Karanjit", true};
	Person p2 = {"Bipin Kharel", true};
	Person p3 = {"Nepun Dahal", true};
	Person p4 = {"Suman Koirala", true};
	Person p5 = {"asd asdasd", true};
	CircularQueue<Person> queue;
	cout << queue.is_empty()<<endl;
	cout << queue.curr().name;
	queue.add_after(p1);
	cout << queue.is_empty()<<endl;
	cout << queue.curr().name;
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522

	// write code here to do the following:
	//   read from the file,
	//   create the people,
	//   add them to the queue,
	//   in the order that they were in the file
	cout << "How many are we skipping each time?" << endl;
	int skip_amount;
	cin >> skip_amount;
<<<<<<< HEAD
	
	
	// CircularQueue<Person> queue2(queue);
	
	// queue2.print();
	// CircularQueue<Person> queue3;
	// CircularQueue<Person> queue4;
	// queue3 = queue;
	// queue3.print();
	int size = queue.Size();
	int ct1 = 1;
	string * nameList;
	nameList = new (nothrow) string[size];
	string name2 = queue.lastitem().name;
	queue.first();
	while (size-ct1 != 0){
		
		for(int i=0;i<skip_amount-1;i++)
		{
		    try
			{
				cout<<"Current:"<<queue.curr().name<<" "<<endl;
				
				queue.next();
			}
			catch (JosephusException je)
			{
				queue.first();
			}
			
            while (queue.curr().alive == false)
			{
                try
				{
					queue.next();
				}
				catch (JosephusException je)
				{
					queue.first();
				}
            }
            
        }
		
		queue.curr().alive = false;
		cout << "Just killed " << queue.curr().name << endl;
		ct1++;
		try
		{
			queue.next();
			while (queue.curr().alive == false)
			{
                try
				{
					queue.next();
				}
				catch (JosephusException je)
				{
					queue.first();
				}	
			}
		}
		catch (JosephusException je)
		{
				queue.first();
				while (queue.curr().alive == false)
				{
                 	queue.next();		
				}	
		}
	}
	while(queue.curr().alive == false){
			
		
		try{
		queue.next();}
		catch(JosephusException je){ queue.first();} 
		
	}
	cout<<queue.curr().name<< " is the survivor."<<endl;

	// write code here to go through, killing appropriately
	//   in a loop, until there is only one surivor
	// the following is just for testing, delete it:
	// string name = "Bob";
	// // for each person killed, output the following:
	// cout << "Just killed " << name << endl;
	// // when you're done killing, output the following:
	// cout << "The survivor is " << name << endl;
	// after you're all done:
	// output the names in alphabetical order
	// (just the names, nothing else)
	int i =0;
	queue.first();
	while (size!=0){
		nameList[i] = queue.curr().name;
		try{
			queue.next();
		}
		catch(JosephusException je){
		
		}
		size --;
		i ++;
	}

	//nameList[size-1] = queue.curr().name;
	cout << "\n\nBelow are the names in Asscending order:\n\n"<<endl;
	for (unsigned int i = 0; i < queue.Size(); i++) {
		for (unsigned int j = 0; j < queue.Size(); j++) {
			if (nameList[i].at(0) < nameList[j].at(0)) {
				string tmp = nameList[i];
				nameList[i] = nameList[j];
				nameList[j] = tmp;
			}
		}

	}

	for (int i =0;i<queue.Size();i++){
		cout<<nameList[i]<<endl;
	}
	delete[] nameList;
=======
	// write code here to go through, killing appropriately
	//   in a loop, until there is only one surivor
	// the following is just for testing, delete it:
	string name = "Bob";
	// for each person killed, output the following:
	cout << "Just killed " << name << endl;
	// when you're done killing, output the following:
	cout << "The survivor is " << name << endl;
	// after you're all done:
	// output the names in alphabetical order
	// (just the names, nothing else)
>>>>>>> 1c5b46782265b9a3a71cd679feedf0a2ce857522
	return 0;
};
