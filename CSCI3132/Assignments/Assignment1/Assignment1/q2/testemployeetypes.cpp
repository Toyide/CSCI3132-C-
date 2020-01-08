/*  File: testemployeetypes.cpp
    Application program using classes employeetypes 

    Programmer: your name             Date:                   */

#include "employeetypes.h"

int main(void)
{
    string type;            // employee type
    ofstream fout ("employeetypesout.txt");

    while(true) { // loop until break occurs
        cout << endl << "Type of employee: "; cin >> type;
        if (type == "q") break;

        if(type == "labourer") {     
            labourer lab;
            lab.read(cin);

            cout << endl;
            lab.write(cout);
            fout << endl;
            lab.write(fout);

        } else if (type == "scientist") { 
            scientist sci;
            sci.read(cin);

            cout << endl;
            sci.write(cout);
            fout << endl;
            sci.write(fout);

        } else if (type == "manager") {        
            manager man;
            man.read(cin);

            cout << endl;
            man.write(cout);
            fout << endl;
            man.write(fout);
        }        
   }
   fout.close();   
   return 0;
}
