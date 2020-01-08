#include "vector.h"

vector::vector() 
: vector(initialSize) 
{
    INFO("object of class vector was created using the vector() constructor");
}

vector::vector(size_t size) 
: _size(size)
{
    INFO("object of class vector was created using the vector(size_t) constructor");
    data = new int[_size];
        for (int i = 0; i < _size; i++)
    {
        data[i] = 0;
    }
}

vector::vector(int* data_input, size_t size) 
: vector(size)
{
    INFO("object of class vector was created using the vector(int*, size_t) constructor");
    for (int i = 0; i < _size; i++)
    {
        data[i] = data_input[i];
    }
}

vector::~vector()
{
    INFO("object of class vector deleted");
    delete[] data;
}

void vector::resize(size_t newSize) 
{
    int* ptr = new int[newSize];
    int size = std::min(_size,newSize);
    for (int i = 0; i < size; i++)
    {
        ptr[i] = data[i];
    }
    delete[] data;
    data = ptr;
    _size = newSize;
}

int vector::getSize() const {
    return _size;
}

void vector::assign(int* data_input, size_t size)
{
    resize(size);
    for (int i = 0; i < _size; i++)
    {
        data[i] = data_input[i];
    }
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
    int* add_data = new int[nextObject.getSize()];
    if ( _size == nextObject.getSize() ) {
        for (int i = 0; i < _size; i++)
        {
            add_data[i] = data[i] + nextObject.data[i];
        }
    } else {
        WARNING( "Size of the vectors should be the same" );
        //return vector(add_data, nextObject.getSize()); 
    }
    return vector(add_data, _size);
}

vector vector::operator+(const vector & nextObject ) const 
{
    return add(nextObject);
}

std::ostream& operator<<(std::ostream& stream, const vector& obj)
{
    stream << "vector: size(" << obj.getSize() << ")" << std::endl;
    for (int i = 0; i < obj.getSize()-1; i++)
        stream << "data[" << i << "] = " << obj.data[i] << std::endl;
    stream << "data[" << obj.getSize()-1 << "] = " << obj.data[obj.getSize()-1];
    return stream;
}