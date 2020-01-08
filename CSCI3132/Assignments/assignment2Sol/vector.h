#pragma once
#include<iostream>

#define LOG(x,y) std::cout << x << y << std::endl;

#define INFO(x) std::cout << "[INFO]: " << x << std::endl;
#define WARNING(x) std::cout << "[WARNING]: "<< x << std::endl;
#define ERROR(x) std::cout << "[ERROR]: " << x << std::endl;

class vector {
// attributes
private:
    size_t _size;

public:
    int* data;
    static const size_t initialSize = 3; 

// methods
private:

public:
    vector();
    vector(size_t size);
    vector(int* data_input, size_t size);
    ~vector();
    void resize(size_t newSize);
    int getSize() const;
    void assign(int* data_input, size_t size);
    int& operator[](size_t index);
    vector add(const vector & nextObject ) const;
    vector operator+(const vector & nextObject ) const;
};

std::ostream& operator<<(std::ostream& stream, const vector& obj);