#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#define LOG(x,y) std::cout << x << y << std::endl;

#define INFO(x) std::cout << "[INFO]: " << x << std::endl;
#define WARNING(x) std::cout << "[WARNING]: "<< x << std::endl;
#define ERROR(x) std::cout << "[ERROR]: " << x << std::endl;


class vector {
    
    public:
        int _size;
        int * data;
        vector();//vector()
        vector(size_t size); //vector(size)
        vector(int* a, size_t size);//vector (array, size)
        void assign(int* a,size_t size);//assign
        vector add(const vector & nextObject) const;//add
        vector operator+(const vector & nextObject ) const;//+
        int& operator[](int i);//[]
        void resize(size_t size);//resize
        ~vector();
};
//for vector output
std::ostream& operator<<(std::ostream& stream, const vector& nextObject);

#endif // end vector_H