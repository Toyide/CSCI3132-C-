/*  File: employeetypes.cpp
    Implementation of classes employeetypes */

#include "employeetypes.h"

///////////////// Member functions of employee /////////////////////////////

employee::employee(string n, int i, float s)
{
    name = n;
    id = i;
    salary = s;
}

void employee::write(ostream & out) const
{
    out << "name  : " << name <<   endl;
    out << "id    : " << id  <<    endl;
    out << "salary: " << salary << endl;
}

void employee::read(istream & in)
{
    cout << "name  : ";
    in >> name;

    cout << "id  : ";
    in >> id;
    
    cout << "salary: ";
    in >> salary;
}      
//////////////////// Member functions of labourer /////////////////////////




//////////////////// Member functions of manager ///////////////////////////




//////////////////// Member functions of scientist ////////////////////////




