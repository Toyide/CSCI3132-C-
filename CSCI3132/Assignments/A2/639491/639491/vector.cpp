#include "vector.h"
//defult to 3
vector::vector() 
: vector(3) 
{   
    data = new int[3];
    for ( int i = 0; i < _size; i++ ) {
        data[i] = 0;
    }
    INFO("Object of class vector was created using the vector() constructor");
}
//specified size
vector::vector(size_t size)
: _size(size)
{ 
    data= new int[_size];
    for ( int i = 0; i < _size; i++ ) {
        data[i] = 0;
    }
    //create an array of size ¡°_size¡± and initialize all members with zeros
    INFO("object of class vector was created using the vector(size_t) constructor");
}
//specified size and array
vector::vector(int* a, size_t size)
: _size(size)
{ 
    data= new int[_size];
    // create an array of size and assign a to the new array
    INFO("object of class vector was created using the vector(int*, size_t) constructor");
    for (size_t i = 0; i < size; i++)
    {
        data[i] = a[i];
    }
}
//assign
void vector::assign(int* a,size_t size){
    _size=size;
    data= new int[_size];
    // create an array of size and assign a to the new array
    for (size_t i = 0; i < size; i++)
    {
        data[i] = a[i];
    }

}
//add function
vector vector::add(const vector & nextObject) const
{   
    int holder;
    if(_size>nextObject._size){
        holder = _size;
    }else{
        holder = nextObject._size;
    } 
    vector newvector(holder);
    for(int i=0; i< holder; i++){
        newvector.data[i]=data[i]+nextObject.data[i];
    }
    return newvector;
}
//+ alternative
vector vector::operator+(const vector & nextObject ) const 
{
    return add(nextObject);
}
//[]
int& vector::operator[](int i)
{
    if(i < _size){
        return data[i];
    }
    else{
        ERROR("excced index of the array.");
        return data[0];
    }
}
//resize
void vector::resize(size_t size)
{
    int holder[size];
    for (int i =0; i< _size; i++){
        holder[i]= data[i];
    }
    data=new int[size];
    
    for (int i =0; i< size; i++){
        if(i>_size){
            data[i]=0;
        }else{
            data[i]=holder[i];
        }
    }
    _size=size;
}
//deconstructor
vector::~vector()
{
    delete[] data;
    _size=0;
    INFO("object of class vector deleted");
}
//output
std::ostream& operator<<(std::ostream& stream, const vector& nextObject)
{   
    stream << "vector: size("<<nextObject._size<<")\n";
    for(int i =0; i<nextObject._size;i++){
        stream << "data[" << i << "] = " << nextObject.data[i]<<"\n";
    }
    return stream;
}
