#include <iostream>
#include "vector.h"


#define LOG(x,y) std::cout << x << y << std::endl;

#define INFO(x) std::cout << "[INFO]: " << x << std::endl;
#define WARNING(x) std::cout << "[WARNING]: "<< x << std::endl;
#define ERROR(x) std::cout << "[ERROR]: " << x << std::endl;





int main(void) {
    // 1- Test the default constructor
    INFO(" ---------- Vector 1 ----------");
    vector v1;
    INFO(v1);
    // access the indices of the data vector by overloading the [] operator
    LOG("first index is: ", v1.data[0]);

    // 2- Test the destructor
    {
        vector v2;
    } // should delete the object

    // 3- Test the data vector
    LOG("first index is: ", v1.data[0]);
    v1.data[0] = 10;
    LOG("first index is: ", v1.data[0]);

    // 4- Testing the overloaded constructor which inputs the size
    INFO(" ---------- Vector 2 ----------");
    vector v2(5);
    INFO(v2);

    // 5- Testing the overloaded constructor which inputs an array 
    INFO(" ---------- Vector 3 ----------");
    int a[] = {1,2,3,4,5,6,7,8};
    vector v3(a, 8); // Using an overloaded constructor
    INFO(v3);

    // 6- Testing the overloaded array operator "[]"
    v1[0] = 50;

    // 7- Testing the overloaded shift operator "<<"
    LOG("first index is: ", v1[0]);

    // 8- Testing the assign function
    INFO(" ---------- Vector 4 ----------");
    int b[] = {8,7,6,5,4,3,2,1};
    vector v4;
    v4.assign(b, 8);
    INFO(v4);

    // 9- Testing the add function
    INFO(" ---------- Vector 5 ----------");
    vector v5 = v3.add(v4);
    INFO(v5);

    // 10- Testing the overloaded add operator "+"
    INFO(" ---------- Vector 6 ----------");
    vector v6 = v3 + v4;
    INFO(v6);

    // 11- Testing the resize function
    v4.resize(10);
    INFO(v4);

   return 0;
}