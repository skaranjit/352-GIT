
#ifndef DATE_H
#define DATE_H
#include<iostream>

namespace DateNameSpace{
    enum airthematic {Years,Months,Days};
    enum format {LittleEndian,MiddleEndian,BigEndian,Slash,Dash,Space,Text,Numeric,Weekday,NoWeekday};
class Date{
    public:
        // method - constructor
        // description - construct a new Date object
        // preconditions - none
        // postconditions - Date object created and initialized 
        //    to a year,day and month  of either the argument or 0 by default
        // method input - year/day/month: int
        // method output - none
        Date ();
        Date(int,int,int);
        // method - Get Method
        // description - Returns the integer value of either year, day or month
        // preconditions - Date object should have already initialized
        // postconditions - None
        // method input -None
        // method output - Int
        int getYear();
        int getDay();
        int getMonth();
        std::string getDayOfWeek();
        // method - Set Method
        // description - Set year,month,day to new value provided
        // preconditions - Date object should have already initialized
        // postconditions - Year,month and day changed
        // method input -day,month,year : Int,int,int
        // method output - None
        void setDate(int,int,int);
        void setToday();
        bool loopyear(int);
        static void outputFormat(format);
        static void Arithmetic(airthematic a);
        int until();
        Date operator-(int num);
        Date operator+(int num);
        Date operator+=(int num);
        Date operator-=(int);
        
        static Date Today();
        Date(const Date &d);
     
         // method - validate Date
        // description - Validate if the day is correct or not for the given month and year.
        // preconditions - month, day and year should be passed as int
        // postconditions - returns true or false
        // method input -day,month,year : Int,int,int
        // method output - bool
        bool validateDate(int,int,int);
         // method - Operators Overloading
        // description - Overloading operators
        // preconditions - Date object should have already initialized
        // postconditions - none
        // method input -day,month,year : Int,int,int
        // method output - None
        friend std::ostream & operator <<(std::ostream &out,Date &dateObj);
        friend std::istream & operator >> (std::istream &in, Date & d);  
        friend bool operator==(Date const &d1,Date const &d2);
        friend Date operator+(Date &d1,Date &d2);
        friend int operator-(Date const &d1,Date const &d2);
        friend Date operator*(Date  &d1,Date  &d2);
        friend Date operator/(Date  &d1,Date  &d2);
        friend bool operator>(Date const &d1,Date const &d2);
        friend bool operator<(Date const &d1,Date const &d2);
        friend Date operator++(Date &d,int);
        friend Date operator--(Date &d,int);
        friend Date operator++(Date &d1);
        friend Date operator--(Date &d1);
        void operator=(Date d1);
       // int calcNumDays(int,int,int);
        Date calcDate(int);
        int daysUntil();



    private:
        int Year;
        int Day;
        int Month;
        static format OrderFlag;
        static format deliFlag;
        static format monthFlag;
        static format dayofWeekFlag;
        static airthematic x;
        static int flag;
        int numofDays;
        std::string dayofWeek;

};


std::ostream & operator <<(std::ostream &out,Date &dateObj);
std::istream & operator >> (std::istream &in, Date & d); 
bool operator==(Date const &d1,Date const &d2);
Date operator+(Date const &d1,Date const &d2);
int operator-(Date const &d1,Date const &d2);
Date operator*(Date const &d1,Date const &d2);
Date operator/(Date const &d1,Date const &d2);
bool operator>(Date const &d1,Date const &d2);
bool operator<(Date const &d1,Date const &d2);
Date operator++(Date &d1,int);
Date operator--(Date &d1,int);
Date operator++(Date &d1);
Date operator--(Date &d1);
}
#endif