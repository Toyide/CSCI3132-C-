/* File: date.h
A class representing dates in the form: day , month and year

dat e s are written to a stream in the form day/month/ year

day_number( ) returns the number of days since 1/1 of the current
 year including the current day

days_between( ) returns the number of days between two dates not 
including the first day but including the last day. */

#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>
using namespace std ;
class date {
private :
    int day ;
    int month ;
    int year ;
public :
    // you fill in the method prototypes
};
#endif /* DATE_H */