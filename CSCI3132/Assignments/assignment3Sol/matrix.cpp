#include "matrix.h"

matrix::matrix() 
: _size(0), _sizeRow(0), _sizeCol(0)
{
    INFO("object of class matrix was created using the matrix() constructor");
    mat = new vector*[_sizeRow];
}

matrix::matrix(size_t size) 
: matrix(size,size)
{
    INFO("object of class matrix was created using the matrix(size_t) constructor");
}

matrix::matrix(size_t sizeRow, size_t sizeCol)
: _sizeRow(sizeRow), _sizeCol(sizeCol)
{
    INFO("object of class matrix was created using the matrix(size_t, size_t) constructor");
    _size = _sizeRow * _sizeCol;
    mat = new vector*[_sizeRow];
    for (size_t i = 0; i < _sizeRow; i++)
    {
        mat[i] = new vector(_sizeCol);
    }
}

matrix::matrix(int* data_input, size_t sizeRow, size_t sizeCol) 
: _size(0), _sizeRow(0), _sizeCol(0)
{
    INFO("Object of class matrix was created using the matrix(int*, size_t, size_t) constructor");
    mat = new vector*[_sizeRow];
    assign(data_input, sizeRow, sizeCol);
}

matrix::matrix(vector** matDummy, size_t sizeRow, size_t sizeCol) 
: _sizeRow(sizeRow), _sizeCol(sizeCol)
{
    INFO("Object of class matrix was created using the matrix(vector**, size_t, size_t) constructor");
    _size = _sizeRow * _sizeCol;
    mat = new vector*[_sizeRow];
    for (size_t i = 0; i < _sizeRow; i++)
    {
        mat[i] = new vector(*matDummy[i]);
    }
}


matrix::~matrix()
{
    INFO("object of class matrix deleted");
    for (size_t i = 0; i < _sizeRow; i++)
        delete mat[i];
    delete mat;
}

matrix::matrix(int* data_input, size_t size)
: matrix(data_input, size, size)
{
    INFO("Object of class matrix was created using the matrix(int*, size_t) constructor");
}

void matrix::resize(size_t newSizeRow, size_t newSizeCol) 
{
    if (_sizeRow != newSizeRow || _sizeCol != newSizeCol)
    {
        vector** newMat = new vector*[newSizeRow];
        for (size_t i = 0; i < _sizeRow; i++)
        {
            newMat[i] = new vector(newSizeCol);
        }
        for (size_t i = 0; i < _sizeRow; i++)
        {
            for (size_t j = 0; j < newSizeCol; j++)
            {
                newMat[i]->data[j] = mat[i]->data[j];
            }
        }
        for (size_t i = 0; i < _sizeRow; i++)
            delete mat[i];
        delete mat;
        _sizeRow = newSizeRow;
        _sizeCol = newSizeCol;
        _size = _sizeRow*_sizeCol;
        mat = newMat;
    }
}

void matrix::assign(int* data_input, size_t sizeRow, size_t sizeCol) 
{
    for (size_t i = 0; i < _sizeRow; i++)
        delete mat[i];
    delete mat;
    _sizeRow = sizeRow;
    _sizeCol = sizeCol;
        
    _size = _sizeRow * _sizeCol;
    mat = new vector*[_sizeRow];
    for (size_t i = 0; i < _sizeRow; i++)
    {
        mat[i] = new vector(data_input + i*_sizeCol, data_input + (i+1)*_sizeCol);
    }
}

std::string matrix::print() const 
{
    std::string v;
    v = "matrix: size(" + std::to_string(_size) + ")\n";
    for (size_t i = 0; i < _sizeRow; i++)
    {
        for (size_t j = 0; j < _sizeCol; j++)
        {
            v = v + "data[" + std::to_string(i+1) + "][" + std::to_string(j+1) + "] = " + std::to_string(mat[i]->data[j]) + "\n";
        }
    }
    return v;
}

vector& matrix::operator[](size_t index)
{
    if (index >= _size) 
    { 
        ERROR("Matrix index out of bound, exiting");
        exit(0); 
    } 
    return **(mat+index); 
}

matrix matrix::add(const matrix & nextObject ) const 
{
    matrix m(_sizeRow, _sizeCol);
    if ( _sizeRow == nextObject.get_sizeRow() && _sizeCol == nextObject.get_sizeCol()) {
        for (size_t i = 0; i < _sizeRow; i++)
        {
            for (size_t j = 0; j < _sizeCol; j++)
                m.mat[i]->data[j] = mat[i]->data[j] + nextObject.mat[i]->data[j];
        }
    } else {
        WARNING( "Size of the vectors should be the same" );
    }
    return matrix(m.mat, _sizeRow, _sizeCol);
}

matrix matrix::operator+(const matrix & nextObject ) const 
{
    return add(nextObject);
}

size_t matrix::get_size() const { return _size;}
size_t matrix::get_sizeRow() const { return _sizeRow;}
size_t matrix::get_sizeCol() const { return _sizeCol;}

