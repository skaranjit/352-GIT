#include <iostream>
#include "person.h"
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

	// write code here to do the following:
	//   read from the file,
	//   create the people,
	//   add them to the queue,
	//   in the order that they were in the file
	cout << "How many are we skipping each time?" << endl;
	int skip_amount;
	cin >> skip_amount;
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
	return 0;
};
