#include "vector.h"
#include "matrix.h"
#include <string>

int main(int argc, char **argv) 
{
    std::string s = argv[1];
    if (s == "1")
    {
        // 1- Test the default constructor
        INFO(" ---------- matrix 1 ----------");
        matrix m1;
        INFO(m1);
    }
    else if (s == "2")
    {
        // 2- access the members
        INFO(" ---------- matrix 2 ----------");
        matrix m2(2,2);
        m2.mat[0][0] = 1;
        INFO(m2.mat[0]->data[0]);
    }
    else if (s == "3")
    {
        // 3- overload the [] operator 
        INFO(" ---------- matrix 3 ----------");
        matrix m3(2,2);
        m3[0][0] = 5;
        INFO(m3[0][0]);
    }
    else if (s == "4")
    {
        // 4- assign an array to matrix using a constructor
        INFO(" ---------- matrix 4 ----------");
        int c[] = {8,7,6,5,4,3,2,1};
        matrix m4(c,2,4);
        INFO(m4);
    }
    else if (s == "5")
    {
        // 5- use the assign function to assign an array to a matrix
        INFO(" ---------- matrix 5 ----------");
        int d[] = {8,7,6,5,4,3,2,1};
        matrix m5;
        m5.assign(d,2,4);
        INFO(m5);
    }
    else if (s == "6")
    {
        // 6- Test the resize function 
        INFO(" ---------- matrix 6 ----------");
        int d[] = {8,7,6,5,4,3,2,1};
        matrix m6;
        m6.assign(d,2,4);
        m6.resize(2,5);
        m6[0][4] = 0;
        m6[1][4] = 0;
        INFO(m6);
    }
    else if (s == "7")
    {
        // 7- test the constructor that takes vectors to build a matrix.
        INFO(" ---------- matrix 7 ----------");
        vector** mat = new vector*[2];
        int row1[] = {8,7,6,5,4,3,2,1};
        mat[0] = new vector(row1,row1+8);
        int row2[] = {1,2,3,4,5,6,7,8};
        mat[1] = new vector(row2,row2+8);
        matrix m7(mat, 2, 8);
        INFO(m7);
        delete mat[0];
        delete mat[1];
    }
    else if (s == "8")
    {
        // 8- test add function and overload + operator
        INFO(" ---------- matrix 8 ----------");
        int e[] = {8,7,6,5,4,3,2,1};
        matrix ma(e,2,4);
        int f[] = {1,2,3,4,5,6,7,8};
        matrix mb(f,2,4);
        matrix m8 = ma + mb;
        INFO(m8);
    }
    else 
    {
        return 0;
    }
    return 0;
}