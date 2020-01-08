/*  File: employeetypes.h
    Program to illustrate derived classes */

#ifndef EMPLOYEETYPES_H
#define EMPLOYEETYPES_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class employee {
private:
    string name;  // last name
    int id;       // employee id number
    float salary; // employee salary
    
public:
    employee(string n="none", int i=0, float s=0.0);
    void write(ostream & out) const;
    void read(istream & in);
};

class manager : public employee {  
private:
    string title;       // vice-president etc
public:
    manager(string n="none", int i=0, float s=0.0, string t="none");
    void write(ostream & out) const;
    void read(istream & in);
};

class scientist : public employee{  
private:
    int pubs;           // number of publications

public:
    scientist(string n="none", int i=0, float s=0.0, int p=0);
    void write(ostream & out) const;
    void read(istream & in);
};

class labourer : public employee {    
private:
    string dept;
      
public:
    labourer(string n="none", int i=0, float s=0.0, string d="none");
    void write(ostream & out) const;
    void read(istream & in);
};

#endif /* EMPLOYEETYPES_H */

