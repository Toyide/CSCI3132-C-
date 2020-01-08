#include "vector.h"

vector::vector()
: _size(0)
{
    INFO("object of class vector was created using the vector() constructor");
    
}

vector::vector(size_t size) 
: _size(size)
{
    INFO("object of class vector was created using the vector(size_t) constructor");
    data = new int[_size];
}

vector::vector(int* data_input_begin, int* data_input_end)
: _size(data_input_end - data_input_begin)
{
    INFO("object of class vector was created using the vector(int*, int*) constructor");
    
    assign(data_input_begin, data_input_end);
}

vector::~vector()
{   
    delete[] data;
    INFO("object of class vector deleted");
    
}

vector::vector(const vector &v) 
{
    INFO("The copy constructor of the class vector was called");
    _size = v.get_size();
    data = new int[_size];
    for (size_t i = 0; i<_size; i++)
        data[i] = v.data[i];

}

vector& vector::operator=(const vector& other) 
{
    // check for self-assignment
    if(&other == this)
        return *this;
    // reuse storage when possible
    if(_size != other.get_size())
    {
        if (_size)
            delete[] data;
        data = new int[other.get_size()];
        _size = other.get_size();
    }
    std::copy(&other.data[0], &other.data[0] + _size, &data[0]);
    return *this;
}

void vector::resize(size_t newSize) 
{
    if (_size != newSize)
    {
        int* ptr = new int[newSize];
        size_t size = std::min(_size,newSize);
        std::memcpy(data, ptr, size*sizeof(int));
        delete[] data;
        data = ptr;
        _size = newSize;
    }
}

size_t vector::get_size() const {
    return _size;
}

void vector::assign(int* data_input_begin, int* data_input_end)
{
    if (_size)
        delete[] data;
    _size = data_input_end - data_input_begin;
    data = new int[_size];
    std::memcpy(data, data_input_begin, _size*sizeof(int));
}

int& vector::operator[](size_t index)
{
    if (index >= _size) 
    { 
        ERROR("Vector index out of bound, exiting");
        exit(0); 
    } 
    return data[index]; 
}

vector vector::add(const vector & nextObject ) const 
{
    int add_data[nextObject.get_size()];
    if ( _size == nextObject.get_size() ) {
        for (size_t i = 0; i < _size; i++)
        {
            add_data[i] = data[i] + nextObject.data[i];
        }
    } else {
        WARNING( "Size of the vectors should cbe the same" );
    }
    return vector(add_data, add_data + _size);
}

vector vector::operator+(const vector & nextObject ) const 
{
    return add(nextObject);
}

std::string vector::print() const 
{
    std::string v;
    v = "vector: size(" + std::to_string(_size) + ")\n";
    for (size_t i = 0; i < _size-1; i++)
        v = v + "data[" + std::to_string(i) + "] = " + std::to_string(data[i]) + "\n";
    v = v + "data[" + std::to_string(_size-1) + "] = " + std::to_string(data[_size-1]);
    return v;
}
