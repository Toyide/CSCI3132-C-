/* File : testdate.cpp
Application program using class time
Programmer : your name Date : */
#include "date.h"
int main (void)
{
    ofstream fout("date.txt");
    date d(12 , 6 , 2016);
    date e(14 , 9 , 2018);
    fout << "For the date " ;
    d.write( fout ) ;
    fout << endl ;
    fout << "Day number is " << d.day_number() << endl;
    fout << "\nFor the date " ;
    e.write(fout);
    fout << endl;
    fout << "Day number is "<< e.day_number() << endl;
    fout << "\nDays between " ;
    d.write(fout) ;
    fout << " and ";
    e.write(fout);
    fout << " = " << d.days_between(e) << endl;
    fout.close();
    return 0 ;
}