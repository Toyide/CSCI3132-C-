#include "matrix.h"
#include <vector>

// default
matrix::matrix() 
: _size(0){

	mat =0;
    INFO("object of class matrix was created using the matrix() constructor");
    
}
//take one size
matrix::matrix(size_t size)
:  _size(size){
    INFO("object of class vector was created using the vector(size_t) constructor");
}

//take row and col
matrix::matrix(size_t sizeRow, size_t sizeCol) 
: _size(sizeRow*sizeCol), _sizeRow(sizeRow),_sizeCol(sizeCol){
    INFO("object of class matrix was created using the matrix(size_t, size_t) constructor");
    mat = new vector* [sizeRow];
    for (int i=0; i < sizeRow; i++){
        mat[i] = new vector(sizeCol);
    }
}

//take input data and row and col, then assign the data into mat
matrix::matrix(int* data_input, size_t sizeRow, size_t sizeCol) 
: _size(sizeRow*sizeCol), _sizeRow(sizeRow),_sizeCol(sizeCol) {
    INFO("object of class vector was created using the vector(int*, size_t, size_t) constructor");
    this->assign(data_input, sizeRow, sizeCol);
}

//take input data and size then assgin the data to mat
matrix::matrix(int* data_input, size_t size)
: _size(size){
    INFO("object of class vector was created using the vector(int*, size_t) constructor");
	// assum the matrix only have 1 col
    this->assign(data_input, size, 1);
}

// take a vector data and row col, then copy all data into mat
matrix::matrix(vector** data, size_t sizeRow, size_t sizeCol) 
: _size(sizeRow*sizeCol), _sizeRow(sizeRow),_sizeCol(sizeCol) {
    INFO("Object of class matrix was created using the matrix(vector**, size_t, size_t) constructor");
    mat = new vector* [sizeRow];
    for(int i = 0; i < sizeRow; i++){
        vector* holder = new vector(*data[i]);
        mat[i] = holder;
    }
}

// deconstructor
matrix::~matrix(){
    INFO("object of class matrix deleted");
	for(int i = 0; i < _sizeRow; i++){
        delete mat[i];
    }
    delete mat;

	_size = 0;
    _sizeRow = 0;
    _sizeCol = 0;
    
}

vector& matrix::operator[](size_t index){
    return *(mat[index]);
}

size_t matrix::get_size()const { 
	return _size; 
}

size_t matrix::get_sizeRow()const { 
	return _sizeRow; 
}

size_t matrix::get_sizeCol()const {
	return _sizeCol; 
}

// put data in a vector then assign it to mat by rows
void matrix::assign(int* data_input, size_t sizeRow, size_t sizeCol){
    _size = sizeRow * sizeCol;
    _sizeRow = sizeRow;
    _sizeCol = sizeCol;
    mat = new vector* [sizeCol];
    int* startV = data_input;
    int* endV = data_input+sizeCol;
    for (int i=0; i < sizeRow; i++){
        mat[i] = new vector(startV, endV);
        startV = endV;
        endV = startV + sizeCol;
    }
}

// resize the matrix by expending the mat and copy data into the new mat
void matrix::resize(size_t newSizeRow, size_t newSizeCol){
    // resize row
    if (newSizeRow > _sizeRow){
        vector** holder = new vector*[newSizeRow];
        for(int rows=0;rows < _sizeRow; rows++){
            holder[rows] = mat[rows];
        }
        holder[newSizeRow-1] = new vector(newSizeCol);
        mat = holder;
    }
    

    //resize col
    if(newSizeCol > _sizeCol){ 
        for(int rows=0;rows < _sizeRow; rows++){

            std::vector<int> holder;
            for(int i=0;i < _sizeCol; i++){
                holder.push_back(mat[rows][0][i]);
            }
            mat[rows]->resize(newSizeCol); 
            for(int col=0; col<_sizeCol; col++){
                mat[rows][0][col] = holder[col];
            }
        }
    }
	_sizeRow = newSizeRow;
    _sizeCol = newSizeCol;
    _size = _sizeCol * _sizeRow;
}

//add two matrix by add up each elements
matrix matrix::add(const matrix & nextObject ) const{
    vector** data = new vector*[_sizeCol];
    for(int row = 0; row < _sizeRow; row++){
        int* holder = new int[_sizeCol];
        for (int col = 0; col < _sizeCol; col++){
            holder[col] = mat[row][0][col] + nextObject.mat[row][0][col];
        }
        data[row] = new vector(holder, holder+_sizeCol);
    }
    return matrix(data, _sizeRow, _sizeCol);
}

//overload +
matrix matrix::operator+(const matrix & nextObject) const{
    return this->add(nextObject);
}

std::string matrix::print() const{
    std::string v;
	v = "matrix: size(" + std::to_string(_size) + ")\n";
    for(int row = 0; row < _sizeRow; row++){
        for (int col = 0; col < _sizeCol; col++){
            v += "data[" + std::to_string(row+1) + "][" + std::to_string(col+1) +"] = " + std::to_string(mat[row]->data[col]) + "\n";
        }
    }
    return v;
}

