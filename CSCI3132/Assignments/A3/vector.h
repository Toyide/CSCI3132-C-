#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include "math.h"

class vector : public math 
{
// attributes
private:
    size_t _size;
public:
    int* data;
// methods
private:


public:
    vector();
    vector(size_t size);
    vector(int* data_input_begin, int* data_input_end);
    ~vector();
    vector(const vector &v);
    vector& operator=(const vector& other);
    void resize(size_t newSize);
    size_t get_size() const override;
    void assign(int* data_input_begin, int* data_input_end);
    int& operator[](size_t index);
    vector add(const vector & nextObject ) const;
    vector operator+(const vector & nextObject ) const;
    std::string print() const override;
};

