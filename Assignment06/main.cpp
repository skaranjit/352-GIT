#include <iostream>
#include "josephus.h"
using namespace std;
using namespace JosephusProblem;

int main() {
	int go_on = 0;
	int number;
	int skip;
	try {
		do {
			try {
				cout << "Please enter how many people (default skip):" << endl;
				cin >> number;
				Josephus problem(number);
				while(true) {
					problem.iterate();
				};
			}
			catch (JosephusException je) {
				cout << "Survivor is: " << je.who() << endl;
			};
			try {
				cout << "Please enter how many people:" << endl;
				cin >> number;
				cout << "Please enter how many to skip each time:" << endl;
				cin >> skip;
				Josephus problem(number,skip);
				while(true) {
					problem.iterate();
				};
			}
			catch (JosephusException je) {
				cout << "Survivor is: " << je.who() << endl;
			};
			cout << "testing copy constructor" << endl;
			Josephus j1(number,skip);
			Josephus j2(j1);
			cout << "testing assignment operator" << endl;
			Josephus j3(5,2);
			j3 = j2;
			cout << "Enter a non-zero number to continue:" << endl;
			cin >> go_on;
		} while (go_on);
	}
	catch (string s) {
		cout << "error: " << s << endl;
	}
	catch (...) {
		cout << "unknown exception thrown" << endl;
	};
	return 0;
};