#include <iostream>
#include <ctime>
#include "date.h"
#include "dateError.h"
#include <string>
#include <cmath>
#include<stdexcept>

using namespace std;

using namespace DateNameSpace;

format Date::OrderFlag;
format Date::dayofWeekFlag;
format Date::monthFlag;
format Date::deliFlag;
airthematic Date::x;
int Date::flag;
Date::Date(){
   tm *current;
   time_t lt;
   lt = time(0);
   current = localtime(&lt);
   Year = current->tm_year + 1900;
   Month = current->tm_mon+1;
   Day = current->tm_mday;
   getDayOfWeek();
}
Date::Date(int d,int m, int y ){
    Year = y;
    Month = m;
    Day = d;
    getDayOfWeek();

}

int Date::getDay(){
    return Day;
}
int Date::getMonth(){
    return Month;
}
int Date::getYear(){
    return Year;
}
//Validation of DAY;
bool Date::validateDate(int m ,int d, int y){
   
    if (m == 1 || (3 || (5 || (7 || (8 || (10 || (12)))))))
		{
			if (d <= 31)
			{
				return true;
			}
		}
	else if (m == 4 || (6 || (9 || (11))))
	{
		if (d <= 30)
		{
			return true;
    	}
		else
		{
            int leapyear = 0;
            if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
	        {
		        leapyear = 1;
            }
			if (leapyear == 1)
			{
				if (d <= 29)
				{
					return true;
				}
			}
			if (leapyear == 0)
			{
				if (d <= 28)
                    return true;
            }
    	}
    }
    return false;
}
void Date::setDate(int m, int d, int y){
    if ((m<1) || (m>12)){
    throw DateException("exception: Month Error");
    }
    else{
        Month = m;
    }
   if (validateDate(m,d,y) == false){
       throw DateException("Exception: Day Error");
   }
   else{
    Day = d;
   }
    getDayOfWeek();
    
    
    Year = y;
       

}

void Date::Arithmetic(airthematic a){
    switch (a){
        case(Years):
            x=Years;
            flag = 1;
            break;
        
        case(Months):
            x=Months;
            flag = 1;
            break;
        default:
            x=Days;
            flag =1;
            break;
        
    }
}
void Date::outputFormat(format f){
    switch(f)
    {
        case(LittleEndian):
            OrderFlag = LittleEndian;
            break;
        case(BigEndian):
            OrderFlag = BigEndian;
            break;
        case(Dash):
            deliFlag = Dash;
            break;
        case(Space):
            deliFlag = Space;
            break;
        case(Text):
            monthFlag = Text;
            break;
        case(Weekday):
            dayofWeekFlag = Weekday;
            break;
        
        default:
            OrderFlag=MiddleEndian;
            dayofWeekFlag = NoWeekday;
            monthFlag = Numeric;
            deliFlag = Slash;
            break;
    }
}
bool leapyear(int year)
{
   return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
string Date::getDayOfWeek(){
   int centuries;
   int months;
   int dayofweek;
   centuries = (3-Year/100%4)*2;
   switch (Month)
   {
      case 1  : if (leapyear(Year))
                   months = 6;
                else
                   months = 0; 
                break;
      case 2  : if (leapyear(Year))
                   months = 2;
                else
                   months = 3; 
                break;
      case 3  : months = 3; break;
      case 4  : months = 6; break;
      case 5  : months = 1; break;
      case 6  : months = 4; break;
      case 7  : months = 6; break;
      case 8  : months = 2; break;
      case 9  : months = 5; break;
      case 10 : months = 0; break;
      case 11 : months = 3; break;
      case 12 : months = 5; break;
   }
    dayofweek = (centuries+Year%100+Year%100/4+months+Day)%7;
    switch (dayofweek)
     {
      case 0 : dayofWeek = "Sunday"; break;
      case 1 : dayofWeek = "Monday"; break;
      case 2 : dayofWeek = "Tuesday"; break;
      case 3 : dayofWeek = "Wednesday"; break;
      case 4 : dayofWeek = "Thursday"; break;
      case 5 : dayofWeek = "Friday"; break;
      case 6 : dayofWeek = "Saturday"; break;
    }
    return dayofWeek;
}
//start of iostream operator overload

ostream & DateNameSpace::operator<<(ostream &out,Date &dateObj){
    const char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char x;
    // if (dateObj.flag == 1)
    // {
    //    switch(Date::x){
    //     case(Years):
    //         out<<(dateObj.numofDays/30)/12<<endl;
    //         break;
    //     case (Days):
    //         out<<(dateObj.numofDays)<<endl;
    //         break;

    //     case(Months):
    //         out<<(dateObj.numofDays)/30<<endl;
    //         break;         

    // }   
    //}  
    switch (Date::dayofWeekFlag){
        case(Weekday):
            out << dateObj.dayofWeek<< ", "; 
            break;
        default: break;
    }
    switch(Date::monthFlag){
        case(Text):
            out << months[dateObj.Month - 1] << " ";
            out << dateObj.Day << "," << dateObj.Year<<endl;
            return out;
            break;
        default:
            break;
    }
    switch(Date::deliFlag){
        case(Dash):
            x = '-';
            break;
        case(Space):
            x = ' ';
            break;
        case(Slash):
            x = '/';
            break;
    }
    switch(Date::OrderFlag){
        case(LittleEndian):
            out << dateObj.Day << x << dateObj.Month <<x <<dateObj.Year<<endl;
            break;
        case(BigEndian):
            out << dateObj.Year;
            out <<x<< dateObj.Month;
            out <<x<<dateObj.Day;
            out <<endl;
            break;
        default:
            out<<dateObj.Month<<x;
            out <<dateObj.Day<<x;
            out<<dateObj.Year<<endl;
            break;
    }    
     
    return out;

}
Date Date::Today(){
     Date d1;
     return d1;

}
Date::Date(const Date &d){
    Day = d.Day;
    Year = d.Year;
    Month = d.Month;
    dayofWeek = d.dayofWeek;
}
istream & DateNameSpace::operator >> (istream &in, Date & d){
    string temp;
    in >> temp;
    string::size_type sz;
    string delimi = "/";
    sz = temp.find(delimi);
    try{
    int month = stoi(temp.substr(0,sz));
    temp.erase(0,sz + delimi.length());
    sz = temp.find(delimi);
    int day = stoi(temp.substr(0,sz));
    temp.erase(0,sz + delimi.length());
    int year = stoi(temp);
     d.setDate(month,day,year);
    }
    catch(std::invalid_argument error){
        throw DateException("Exception: Invalid Argument.");
    }
   
}
//End of iostream operator overload
void Date::setToday()
{
    tm *current;
   time_t lt;
   lt = time(0);
   current = localtime(&lt);
   Year = current->tm_year + 1900;
   Month = current->tm_mon+1;
   Day = current->tm_mday;
   getDayOfWeek();
}

//Start of Overloading Operators
bool DateNameSpace::operator==(const Date &d1,Date const &d2){
    if (d1.Year == d2.Year){
        if (d1.Month == d2.Month){
            if (d1.Day == d2.Day){
                return true;
            }
        }
    }
    return false;
}
int countLeapYears(Date d) 
{ 
    int years = d.getYear(); 
  
    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (d.getMonth() <= 2) 
        years--; 
  
    // An year is a leap year if it is a multiple of 4, 
    // multiple of 400 and not a multiple of 100. 
    return years / 4 - years / 100 + years / 400; 
} 
int calcNumDays(int y, int m, int d){
//     const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
//                            31, 31, 30, 31, 30, 31};
//     long int n1 = d1.getYear()*365 + d1.getDay(); 
  
//     // Add days for months in given date 
//     for (int i=0; i<d1.getMonth() - 1; i++) 
//         n1 += monthDays[i]; 
  
//     // Since every leap year is of 366 days, 
//     // Add a day for every leap year 
//     n1 += countLeapYears(d1); 
  
//     // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2' 
  
//     long int n2 = d2.getYear()*365 + d2.getDay(); 
//     for (int i=0; i<d2.getMonth() - 1; i++) 
//         n2 += monthDays[i]; 
//     n2 += countLeapYears(d2); 
  
//     // return difference between two counts 
//     return (n2 - n1); 
// } 
    
      m = (m + 9) % 12;
      y = y - m/10;
      return (365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 ));
     }
Date Date::calcDate(int g){
    int y,ddd,dd,mm,mi;
    y = (10000*g + 14780)/3652425;
    ddd = g - (365*y + y/4 - y/100 + y/400);
    if (ddd < 0) {
    y = y - 1;
    ddd = g - (365*y + y/4 - y/100 + y/400);
    }
    mi = (100*ddd + 52)/3060;
    mm = (mi + 2)%12 + 1;
    y = y + (mi + 2)/12;
    dd = ddd - (mi*306 + 5)/10 + 1;
    Date d1;
    d1.setDate(mm,dd,y);
    return d1;
}

Date DateNameSpace::operator+(Date &d1,Date &d2)
{
//     int a,b,c;
//     a = d1.calcNumDays(d1.Year,d1.Month,d1.Day);
//     b = d2.calcNumDays(d2.Year,d2.Month,d2.Day);
//     c = a+b;
//     Date d3;
//     d3.calcDate(c);
//     return d3;
// 
}

int DateNameSpace::operator-(Date const &d1,Date const &d2)
{
    int a,b,c;
    a = calcNumDays(d1.Year,d1.Month,d1.Day);
    b = calcNumDays(d2.Year,d2.Month,d2.Day);
    c = a-b;
    if (Date::x == Years){
        return (c/30)/12;
    }
    else if (Date::x == Months){
        return (c/30);
    }
    return c;
}
int Date::daysUntil(){
    Date d1;
    int TodayMonths = d1.getMonth();
    int TodayDay = d1.getDay();
    int x,result;
    int a,b;
    a = calcNumDays(d1.Year,d1.Month,d1.Day);
    if (d1.Month > Month){
        x = d1.Year + 1;
    }
    else x = d1.Year;
    b = calcNumDays(x,Month,Day);
    result = a - b;
    return abs(result);


}
Date DateNameSpace::operator*(Date &d1, Date &d2)
{
    //  int a,b,c;
    // a = d1.calcNumDays(d1.Year,d1.Month,d1.Day);
    // b = d2.calcNumDays(d2.Year,d2.Month,d2.Day);
    // c = a*b;
    // Date d3;
    // d3.calcDate(c);
    // return d3;
}
Date DateNameSpace::operator/(Date &d1, Date &d2)
{
    // int a,b,c;
    // a = d1.calcNumDays(d1.Year,d1.Month,d1.Day);
    // b = d2.calcNumDays(d2.Year,d2.Month,d2.Day);
    // c = a-b;
    // Date d3;
    // try{
    // d3.calcDate(c);
    // return d3;}
    // catch (std::exception error){
    //     cout<<"Cannot divide";
   // }

}
bool DateNameSpace::operator>(Date const &d1,Date const &d2)
{
    Date largest;
    largest = d2;
    if(d1.Year > d2.Year){
        largest = d1;
    }
    else if(d1.Year == d2.Year){
        if (d1.Month > d2.Month){
            largest = d1;
        }
        else if(d1.Month == d2.Month){
            if (d1.Day > d2.Day){
                largest = d1;
            }
        }
    }
    if (largest == d1){
        return true;
    }
    else return false;

}
bool DateNameSpace::operator<(Date const &d1,Date const &d2)
{
Date small;
    small = d2;
    if(d1.Year < d2.Year){
        small = d1;
    }
    else if(d1.Year == d2.Year){
        if (d1.Month < d2.Month){
            small = d1;
        }
        else if(d1.Month == d2.Month){
            if (d1.Day < d2.Day){
                small = d1;
            }
        }
    }
    if (small == d1){
        return true;
    }
    else return false;

}
//Date Date::operator =(const Date& d1){
  //  return d1;

//}
void  Date::operator=(Date d1){
    Day = d1.Day;
    Year = d1.Year;
    Month = d1.Month;
    dayofWeek = d1.dayofWeek;
}
Date DateNameSpace::operator++(Date &d1,int)
{
    int d = d1.Day;
    int m = d1.Month;
    int y = d1.Year;
    switch(Date::x){
        case(Years):
            d1.setDate(m,d,y+1);
            break;
        case(Months):
            try{
                m = m + 1;
                d1.setDate(m,1,y);
            }
            catch (DateException error){
                y = y + 1;
                if(m + 1 == 13){
                m = 1;
                }
                else{
                    m=m+1;
                }
            }
            d =1;
            d1.setDate(m,d,y);
            break; 
        default:
            try{
                d = d + 1;
                d1.setDate(m,d,y);
            }
            catch (DateException error){
            try{
                m = m + 1;
                d1.setDate(m,1,y);
            }
            catch (DateException error){
                y = y + 1;
                if(m + 1 == 13){
                m = 1;
            }
            else{
                m=m+1;
            }
            d =1;
            d1.setDate(m,d,y);
            }
            break;
            }
        }

return d1;
}
Date DateNameSpace::operator--(Date &d1,int)
{
//     int d = d1.Day;
//     int m = d1.Month;
//     int y = d1.Year;
//     try{
//         d = d - 1;
//         d1.setDate(m,d,y);
//     }
//     catch (DateException error){
//         try{
//         m -= 1;
        
//         if(d1.validateDate(m,31,y)){
//                 d= 31;
//             }
//             if(d1.validateDate(m,30,y)){
//                 d = 30;
//             }
//             if(d1.validateDate(m,29,y)){
//                 d = 29;
//             }
//             if(d1.validateDate(m,28,y)){
//                 d=28;
//             }
        
//         d1.setDate(m,d,y);
//         }
//         catch (DateException error){
//             y = y-1;
//             if(m - 1 == 0){
//                m = 1;
//             }
//         else{
//                 m=m-1;
//             }
//             if(d1.validateDate(m,31,y)){
//                 d= 31;
//             }
//             if(d1.validateDate(m,30,y)){
//                 d = 30;
//             }
//             if(d1.validateDate(m,29,y)){
//                 d = 29;
//             }
//             if(d1.validateDate(m,28,y)){
//                 d=28;
//             }
//             d1.setDate(m,d,y);

//         }
// }
// return d1;
// }
int d = d1.Day;
    int m = d1.Month;
    int y = d1.Year;
    switch(Date::x){
        case(Years):
            d1.setDate(m,d,y-1);
            break;
        case(Months):
            try{
                m = m - 1;
                if(d1.validateDate(m,31,y)){
                d= 31;
            }
            if(d1.validateDate(m,30,y)){
                d = 30;
            }
            if(d1.validateDate(m,29,y)){
                d = 29;
            }
            if(d1.validateDate(m,28,y)){
                d=28;
            }
            d1.setDate(m,d,y);
        }
        catch (DateException error){
            y = y-1;
            if(m - 1 == 0){
               m = 1;
            }
        else{
                m=m-1;
            }
            if(d1.validateDate(m,31,y)){
                d= 31;
            }
            if(d1.validateDate(m,30,y)){
                d = 30;
            }
            if(d1.validateDate(m,29,y)){
                d = 29;
            }
            if(d1.validateDate(m,28,y)){
                d=28;
            }
            d1.setDate(m,d,y);

        }
            break; 
        default:
            try{
                d = d - 1;
                d1.setDate(m,d,y);
            }
            catch (DateException error){
            try{
                m = m - 1;
                if(d1.validateDate(m,31,y)){
                d= 31;
            }
            if(d1.validateDate(m,30,y)){
                d = 30;
            }
            if(d1.validateDate(m,29,y)){
                d = 29;
            }
            if(d1.validateDate(m,28,y)){
                d=28;
            }
            d1.setDate(m,d,y);
        }
        catch (DateException error){
            y = y-1;
            if(m - 1 == 0){
               m = 1;
            }
        else{
                m=m-1;
            }
            if(d1.validateDate(m,31,y)){
                d= 31;
            }
            if(d1.validateDate(m,30,y)){
                d = 30;
            }
            if(d1.validateDate(m,29,y)){
                d = 29;
            }
            if(d1.validateDate(m,28,y)){
                d=28;
            }
            d1.setDate(m,d,y);
        }
        }
            break;
            
        }

return d1;
}
Date DateNameSpace::operator++(Date &d1)
{
    int d = d1.Day;
    int m = d1.Month;
    int y = d1.Year;
    switch(Date::x){
        case(Years):
            d1.setDate(m,d,y+1);
            break;
        case(Months):
            try{
                m = m + 1;
                d1.setDate(m,1,y);
            }
            catch (DateException error){
                y = y + 1;
                if(m + 1 == 13){
                m = 1;
                }
                else{
                    m=m+1;
                }
            }
            d =1;
            d1.setDate(m,d,y);
            break; 
        default:
            try{
                d = d + 1;
                d1.setDate(m,d,y);
            }
            catch (DateException error){
            try{
                m = m + 1;
                d1.setDate(m,1,y);
            }
            catch (DateException error){
                y = y + 1;
                if(m + 1 == 13){
                m = 1;
            }
            else{
                m=m+1;
            }
            d =1;
            d1.setDate(m,d,y);
            }
            break;
            }
        }

return d1;
}
Date DateNameSpace::operator--(Date &d1)
{
    int d = d1.Day;
    int m = d1.Month;
    int y = d1.Year;
    switch(Date::x){
        case(Years):
            d1.setDate(m,d,y+1);
            break;
        case(Months):
            try{
                m = m - 1;
                if(d1.validateDate(m,31,y)){
                d= 31;
            }
            if(d1.validateDate(m,30,y)){
                d = 30;
            }
            if(d1.validateDate(m,29,y)){
                d = 29;
            }
            if(d1.validateDate(m,28,y)){
                d=28;
            }
            d1.setDate(m,d,y);
        }
        catch (DateException error){
            y = y-1;
            if(m - 1 == 0){
               m = 1;
            }
        else{
                m=m-1;
            }
            if(d1.validateDate(m,31,y)){
                d= 31;
            }
            if(d1.validateDate(m,30,y)){
                d = 30;
            }
            if(d1.validateDate(m,29,y)){
                d = 29;
            }
            if(d1.validateDate(m,28,y)){
                d=28;
            }
            d1.setDate(m,d,y);

        }
            break; 
        default:
            try{
                d = d - 1;
                d1.setDate(m,d,y);
            }
            catch (DateException error){
            try{
                m = m - 1;
                if(d1.validateDate(m,31,y)){
                d= 31;
            }
            if(d1.validateDate(m,30,y)){
                d = 30;
            }
            if(d1.validateDate(m,29,y)){
                d = 29;
            }
            if(d1.validateDate(m,28,y)){
                d=28;
            }
            d1.setDate(m,d,y);
        }
        catch (DateException error){
            y = y-1;
            if(m - 1 == 0){
               m = 1;
            }
        else{
                m=m-1;
            }
            if(d1.validateDate(m,31,y)){
                d= 31;
            }
            if(d1.validateDate(m,30,y)){
                d = 30;
            }
            if(d1.validateDate(m,29,y)){
                d = 29;
            }
            if(d1.validateDate(m,28,y)){
                d=28;
            }
            d1.setDate(m,d,y);
        }
        }
            break;
            
        }
 
return d1;
}
int Date::until(){
    Date d1;
    int a,b;
    a = calcNumDays(d1.Year,d1.Month,d1.Day);
    b = calcNumDays(Year,Month,Day);

    int x = abs(a-b); 
    int y;
    switch(Date::x){
        case Years:
            y = x/365;
            break;
        case Months:
            y=x/30;
            break;
        default:
            y = x;;
            break;
    }
    return y;
}
Date Date::operator+(int num)
{
  if (Date::x == Days)
    Day+=num;
  else if (Date::x == Years)
  {
    if (leapyear(getYear()) && getMonth() == 2 && getDay() == 29)
    {
      
      Day-=1;
      Year+=num;
    }
    else
    {
      Year+=num;
    }
  }
    return *this;
//   }
  
}

Date Date::operator-(int num)
{
  int thisYear = getYear();
  if (Date::x == Days)
    Day = Day - num;
  else if (Date::x == Years)
  {
    if (leapyear(thisYear) && getMonth() == 2 && getDay() == 29)
    {
  
      Day = Day -1;
      Year -= num;
    }
    else
    {
      Year-=num;
    }
  }
  return *this;
}

Date Date::operator+=(int num)
{
  if (Date::x == Days)
    Day+=num;
    else if (Date::x == Years)
  {
    if (leapyear(getYear()) && getMonth() == 2 && getDay() == 29)
    {
      Day-=num;
      Year+=1;
    }
    else
    {
      Year+=num;
    }
  }
  return *this;
}

Date Date::operator-=(int num)
{
    if (Date::x == Days)
    {
    Day= Day -num;
    }
    else if (Date::x == Years)
  {
    if (leapyear(getYear()) && getMonth() == 2 && getDay() == 29)
    {
      Day-=num;
      Year-=1;
    }
    else
    {
      Year-=num;
    }
  }
  return *this;
}