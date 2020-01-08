#pragma once
#include<iostream>

#define LOG(x,y) std::cout << x << y << std::endl;

#define INFO(x) std::cout << "[INFO]: " << x << std::endl;
#define WARNING(x) std::cout << "[WARNING]: "<< x << std::endl;
#define ERROR(x) std::cout << "[ERROR]: " << x << std::endl;

//CSCI 3132 A4 B00639491 YIDE GE
template <class T>

class vector {
// attributes
    private:
        size_t _size;

    public:
        T* data;
        static const size_t initialSize = 3; 

    // methods
    private:

    public:

        //default
        vector(){
            data =0;
            _size=initialSize;
            INFO("object of class vector was created using the vector() constructor");
        };
        //(size)
        vector(size_t size){
            data= new T [size];
            _size=size;
            INFO("object of class vector was created using the vector(size_t) constructor");
        };
        //(T*, size)
        vector(T* data_input, size_t size){
            _size=size;
            data= new T [size];
            data = data_input;
            
            INFO("object of class vector was created using the vector(T*, T*) constructor");
        };
        //(T*, T*)
        vector(T* data_input, T* b){
            data = new T [b-data_input];
            _size=b-data_input;
            assign(data_input, b);

            INFO("object of class vector was created using the vector(T*, T*) constructor");
        };

        
        //deconstructor
        ~vector(){
            INFO("object of class vector deleted");
            _size=0;
            delete[] data;
        };
        //resize
        void resize(size_t newSize){
            T* ptr = new T [newSize];
            int size = std::min(_size,newSize);
            for (int i = 0; i < size; i++)
            {
                ptr[i] = data[i];
            }
            delete[] data;
            data = ptr;
            _size = newSize;
            
        };
        //get size
        int getSize() const{
            return _size;
        };
        //assign (T， SIze)
        void assign(T& data_input, size_t size){
            data = new T [size];
            resize(size);
            for (int i = 0; i < _size; i++)
            {
                data[i] = data_input[i];
            }
        };
        //assign (T*,T*)
        void assign(T* data_input, T* b){
            data = new T [b-data_input];
            resize(b-data_input);
            for (int i = 0; i < _size; i++)
            {
                data[i] = data_input[i];
            }
        };

        // overloaded []
        T& operator[](size_t index){
            if (index >= _size) 
            { 
                ERROR("Vector index out of bound, exiting");
                exit(0); 
            } 
            return data[index]; 
        };

        //add
        vector add(const vector & nextObject ) const{
            
            T* add_data = new T [nextObject.getSize()];
            
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
        };
    
        //overloaded +
        vector operator+(const vector<T> & nextObject ) const{
            
            return add(nextObject);
        };
        //BubbleSort
        void BubbleSort(){
            bool swapped= true;
            int j = 0;
            T temp;

            while (swapped) {
                swapped = false;
                j++;
                for (int i = 0; i < _size - j; ++i) {
                    if (data[i] > data[i + 1]) {
                        temp = data[i];
                        data[i] = data[i + 1];
                        data[i + 1] = temp;
                        swapped = true;
                    }
                }
            }
        };
       //left rotate recursion 
        void leftRotatebyOne(T* arr, T n) { 
            T temp = arr[0];
            int i; 
            for (i = 0; i < n - 1; i++) 
                arr[i] = arr[i + 1]; 
                  
            arr[i] = temp; 
        };
          
        //Rotate
        void Rotate(T* arr, T* d, T* n){ 
            T a= d-arr;
            T b= n-arr;
            for (int i = 0; i < a; i++) 
                leftRotatebyOne(arr, b); 
        };


};
template <typename N>
std::ostream& operator<<(std::ostream& stream, const vector<N>& obj){
    stream << "vector: size(" << obj.getSize() << ")" << std::endl;
    for (int i = 0; i < obj.getSize()-1; i++)
        stream << "data[" << i << "] = " << obj.data[i] << std::endl;
    stream << "data[" << obj.getSize()-1 << "] = " << obj.data[obj.getSize()-1];
    return stream;

};

 