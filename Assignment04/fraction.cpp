#include "fraction.h"
#include "usefulFunc.h"
#include <iomanip>
#include <cmath>
#include <string>
format fraction::flag;
fraction::fraction(){
    numerator = 0;
    denominator = 1;
}
fraction::fraction(int a, int b){
    numerator = a;
    if (b != 0){
    denominator =b;}
    else denominator = 1;
    
}
fraction::fraction(double a){
    denominator = 1000;
    double b = a * 1000.00;
    numerator = (int)b;

    reduce();
}
void fraction::setFraction(int a, int b){
    numerator = a;
    denominator = b;
}
void fraction::setFraction(double a){
    denominator = 1000;
    double b  = a*1000.00;
    numerator = (int)b;
    fraction::reduce();

}
int fraction::getNumerator(){
    return numerator;
}
void fraction::setNumerator(int a){ 
    numerator = a;
}

int fraction::getDenominator(){
    return denominator;
}
void fraction::setDenominator(int a){
    denominator = a;
}
double fraction::decimalValue(){
    return (double)numerator/denominator;
}
void fraction::reduce(){
    int x = calcGCD(numerator,denominator);
    numerator = numerator/x;
    denominator = denominator/x;
}
ostream & operator <<(ostream &out, const fraction &f) 
{
    if (f.flag == improper){
        out << f.numerator;
        out << "/";
        out << f.denominator<<endl;
        return out;

    }
    else if (f.flag == decimal){
        out << fixed<<setprecision(2)<<(double)f.numerator/f.denominator;
    }
    else
    {
        if (abs(f.numerator) >= abs(f.denominator)){
            if(f.numerator%f.denominator > 0){
            out << f.numerator/f.denominator;
            out << " "<<abs(f.numerator%f.denominator);
            out <<"/"<<f.denominator;
            return out;}
            else{
                out<<f.numerator/f.denominator;
                return out;

            }
        }
        else{
        out << f.numerator;
        out << "/";
        out << f.denominator<<endl;
        return out;
        }
    }

    
}
istream & operator >> (istream &in, fraction & f)
{
    cout << "Enter fraction in 'x/y' format";
    string temp;
    cin >> temp;
    string::size_type sz;
    f.numerator = stoi(temp,&sz);
    f.denominator = stoi(temp.substr(sz+1));
}



void fraction::outputFormat(format f)
{
    switch (f)
    {
    case (improper):
        flag = improper;
        cout << flag;
        break;

    case (decimal):
        flag = decimal;
        cout << flag;
        break;
    default:
        flag= mixed;
        break;
    }

}
