// File:     fraction.h
// Author:   Suman Karanjit
// Date:     01/21/2020

// Description
// This file contains the specification for a fraction class

#ifndef H_FRACTION
#define H_FRACTION

#include<iostream>
using namespace std;
enum format {mixed,decimal,improper};
class fraction{
    
    public:
        // method - constructor
        // description - construct a new Fraction object
        // preconditions - none
        // postconditions - Fraction object created and initialized 
        //    to a numerator  of either the argument or 0 by default and 
        //    denominator to either the argument or 1 by default. OR creating fraction
        //    object with double value provided in the argument.
        // method input - numerator/denominator: int
        // method output - none
        fraction();
        fraction(int,int);
        fraction(double);
        // method - setFraction
        // description - set fraction object numerator and denominator
        // preconditions - Fraction object have been initialized 
        // postconditions - Fraction object numerator and denominator changed to assigned value.
        // method input - numerator and demominator : int
        // method output - none
        void setFraction(int,int);
        void setFraction(double);
        // method - getNumerator
        // description - fraction object numerator returned
        // preconditions - Fraction object have been initialized 
        // postconditions - Fraction object numerator returned.
        // method input - none
        // method output - numerator: int
        int getNumerator();
        // method - setDenominator()
        // description - Fraction object denominator will be set to new value 
        // preconditions - Fraction object have been initialized 
        // postconditions - Fraction object denominator returned
        // method input - none
        // method output -  demominator : int
        void setNumerator(int);
        // method - getDenominator()
        // description - Fraction object denominator returned
        // preconditions - Fraction object have been initialized 
        // postconditions - Fraction object numerator will be set to new value.
        // method input - none
        // method output - none
        int getDenominator();
        // method - setDenominator()
        // description - Fraction object denominator will be set to value provided. If 0 is provided it will auto assign 1.
        // preconditions - Fraction object have been initialized 
        // postconditions - Fraction object denominator returned
        // method input - none
        // method output -  none
        void setDenominator(int);
        // method - devimalValue
        // description - Fraction object decimal value is returned
        // preconditions - Fraction object have been initialized 
        // postconditions - Fraction object decimal value is returned
        // method input - none
        // method output -  decimalvalue: double
        double decimalValue();
        // method - reduce
        // description - Fraction object will be reduce to the smallest fraction.
        // preconditions - Fraction object have been initialized 
        // postconditions -Numerator and denominatore will be changed to smallest.
        // method input - none
        // method output - none
        void reduce();
        // method - ostream operator for << 
        // description - Overload << operator for the fraction as a friend function for output the fraction using cout.
        // preconditions - Fraction object have been initialized
        // postconditions -None
        // method input - none
        // method output - output fraction object as a string.
        friend ostream & operator <<(ostream &out, const fraction &f);
        // method - istream operator >> 
        // description - Overload >> operator for the fraction object for input through cin.
        // preconditions - Fraction object have been initialized 
        // postconditions - fraction object will be updated.
        // method input - none
        // method output - none
        friend istream & operator >> (istream &in, fraction & f);
        // method - static outputFormat()
        // description - Overload >> operator for the fraction object for input through cin.
        // preconditions - Fraction object have been initialized 
        // postconditions - fraction object will be update to output in improper format
        // method input - none
        // method output - none
        static void outputFormat(format f);
    private:
        int numerator;   //Numerator of the fraction
        int denominator; //Denominator of the fraction
        static format flag;

};


#endif