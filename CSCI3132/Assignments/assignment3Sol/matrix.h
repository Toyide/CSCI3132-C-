#pragma once 
#include <iostream>
#include <string>
#include <cstring>
#include "math.h"
#include "vector.h"

class matrix : public math
{
// attributes
private:
    size_t _size;
    size_t _sizeRow;
    size_t _sizeCol;
public:
    vector** mat;

// methods
private:

public:
    matrix();
    matrix(size_t size);
    matrix(size_t sizeRow, size_t sizeCol);
    matrix(int* data_input, size_t sizeRow, size_t sizeCol);
    matrix(int* data_input, size_t size);
    matrix(vector**, size_t, size_t);
    ~matrix();
    vector& operator[](size_t index);
    size_t get_size() const override;
    size_t get_sizeRow() const;
    size_t get_sizeCol() const;
    void assign(int* data_input, size_t sizeRow, size_t sizeCol);
    void resize(size_t newSizeRow, size_t newSizeCol);
    matrix add(const matrix & nextObject ) const;
    matrix operator+(const matrix & nextObject ) const;
    std::string print() const override;
};