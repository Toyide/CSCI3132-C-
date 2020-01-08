#pragma once

#include<iostream>
#include<string>

#define INFO(x) std::cout << "[INFO]: " << x << std::endl;
#define WARNING(x) std::cout << "[WARNING]: "<< x << std::endl;
#define ERROR(x) std::cout << "[ERROR]: " << x << std::endl;

template<typename T>
class vector
{
// attributes
private:
    size_t m_size;
public:
    T* data;

public:
    vector()
    : m_size(0)
    {
        INFO("object of class vector was created using the vector() constructor");
        data = new T[m_size];
    }

    vector(size_t size) 
    : m_size(size)
    {
        INFO("object of class vector was created using the vector(size_t) constructor");
        data = new T[m_size];
    }

    vector(T* data_input_begin, T* data_input_end)
    : m_size(data_input_end - data_input_begin)
    {
        INFO("object of class vector was created using the vector(T*, T*) constructor");
        assign(data_input_begin, data_input_end);
    }

    ~vector()
    {
        INFO("object of class vector deleted");
        delete[] data;
    }

    vector(const vector &v) 
    {
        INFO("The copy constructor of the class vector was called");
        m_size = v.getSize();
        data = new T[m_size];
        for (size_t i = 0; i<m_size; i++)
            data[i] = v.data[i];
    }

    vector& operator=(const vector& other) 
    {
        // check for self-assignment
        if(&other == this)
            return *this;
        // reuse storage when possible
        if(m_size != other.getSize())
        {
            if (m_size)
                delete[] data;
            data = new T[other.getSize()];
            m_size = other.getSize();
        }
        std::copy(&other.data[0], &other.data[0] + m_size, &data[0]);
        return *this;
    }

    void resize(size_t newSize) 
    {
        if (m_size != newSize)
        {
            T* ptr = new T[newSize];
            size_t size = std::min(m_size,newSize);
            std::copy(&data[0], &data[0] + size, &ptr[0]);
            delete[] data;
            data = ptr;
            m_size = newSize;
        }
    }

    size_t getSize() const { return m_size; };

    void assign(T* data_input_begin, T* data_input_end)
    {
        if (m_size != data_input_end - data_input_begin)
            delete[] data;
            m_size = data_input_end - data_input_begin;
            data = new T[m_size];
        std::copy(data_input_begin, data_input_end, &data[0]);
    }

    T& operator[](size_t index)
    {
        if (index >= m_size) 
        { 
            ERROR("Vector index out of bound, exiting");
            exit(0); 
        } 
        return data[index]; 
    }

    vector add(const vector & nextObject ) const 
    {
        T add_data[nextObject.getSize()];
        if ( m_size == nextObject.getSize() ) {
            for (size_t i = 0; i < m_size; i++)
            {
                add_data[i] = data[i] + nextObject.data[i];
            }
        } else {
            WARNING( "Size of the vectors should cbe the same" );
        }
        return vector(add_data, add_data + m_size);
    }

    vector operator+(const vector & nextObject ) const 
    {
        return add(nextObject);
    }

    void BubbleSort() 
    { 
        for (int i = 0; i < m_size - 1; i++) 
            for (int j = m_size - 1; i < j; j--) 
                if (data[j] < data[j - 1]) 
                    std::swap(data[j], data[j - 1]); 
    }

    T* Rotate(T* first, T* n_first, T* last)
    {
        if(first == n_first) return last;
        if(n_first == last) return first;

        T* read      = n_first;
        T* write     = first;
        T* next_read = first; // read position for when "read" hits "last"

        while(read != last) {
            if(write == next_read) next_read = read; // track where "first" went
            std::iter_swap(write++, read++);
        }

        // rotate the remaining sequence into place
        Rotate(write, next_read, last);
        return write;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& stream, const vector<T>& obj)
{
    stream << "vector: size(" << obj.getSize() << ")" << std::endl;
    for (int i = 0; i < obj.getSize()-1; i++)
        stream << "data[" << i << "] = " << obj.data[i] << std::endl;
    stream << "data[" << obj.getSize()-1 << "] = " << obj.data[obj.getSize()-1];
    return stream;
}