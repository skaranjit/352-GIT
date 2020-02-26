#ifndef DATEERROR_H
#define DATEERROR_H
#include <iostream>

using namespace std;

class DateException{
    public:
        DateException(const string& m);
        string what();

    private:
        string msg;
};




#endif