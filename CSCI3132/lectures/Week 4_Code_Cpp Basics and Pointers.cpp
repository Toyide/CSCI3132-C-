/************************/
//Example: C++ Data types
/************************/
#include <iostream>

int main() {
    char ch;
    short s;
    int i;
    long l;
    float f;
    double d;
    long double ld;
    
	std::cout<<"char = "<<sizeof(ch) 
	    <<"\nshort = " << sizeof(s) 
	    <<"\nint = " << sizeof(i) 
	    <<"\nfloat = " << sizeof(f) 
	    <<"\nlong = " << sizeof(l)
	    <<"\ndouble = " << sizeof(d) 
	    <<"\nlong double = " << sizeof(ld) ;
}

/************************/
//Example: Factorial
/************************/
/*
#include <iostream>

int main() {
    long fact = 1; //try using int, long long, long double
    for (int i = 1; i <= 20; i++)
    {
    	fact *= i;
    }
    std::cout << "\nFactorial = " << fact << " and size of variable = "<<sizeof(fact)<<"\n";
}
*/

/************************/
//Example: Arrays
/************************/
/*
#include <iostream>

int foo [] = {1, 2, 3, 4, 5, 6};
int n, result=1;

int main ()
{
  for ( n=0 ; n<6 ; ++n )
  {
    result *= foo[n];
  }
  std::cout << result;
  return 0;
}
*/

/*************************************/
//Exercise: Copying Character Sequence
/*************************************/
/*
#include <iostream>

int main()
{
	char my_char_arr[]  = "Object Orientation";
	char your_char_arr[19];
	for (int i = 0; i < 19; ++i) {
		your_char_arr [i] = my_char_arr[i];
	}
	std::cout << your_char_arr;
	return 0;
}
*/

/**********************/
//Example: Pointers
/**********************/
/*
#include <iostream>
int main() {
	int x1, x2;
	int * p1;
	p1 = &x1;	//p1 = address of x1
	*p1 = 10;	//value pointed to by p1=> x1=10
	p1 = &x2;	//p1 = address of x2
	*p1 = 20;	//value pointed to by p1=> x2=20
	std::cout<<"\nValue of x1 = "<<x1;
	std::cout<<"\nValue of x2 = "<<x2;
	return 0;
}
*/

/**********************/
//Exercise: Pointers
/**********************/
/*
#include <iostream>
int main() {
	int x1=10, x2=20;
	int * p1, * p2;
	p1 = &x1;
	p2 = &x2;
	*p1 = 100;
	*p2 = *p1;
	p1 = p2;
	*p1 = 200;
	std::cout<<"\nValue of x1 = "<<x1;
	std::cout<<"\nValue of x2 = "<<x2;
	return 0;
}
*/

/*****************************/
//Example: Arrays and Pointers
/*****************************/
/*
#include <iostream>
int main() {
	char arr[5];
	char * ptr;
	ptr = arr;  *ptr = 'H';
	ptr++;  *ptr = 'E';
	ptr = &arr[2];  *ptr = 'L';
	ptr = arr + 3;  *ptr = 'L';
	ptr = arr;  *(ptr + 4) = 'O';
	for (int n = 0; n<5; n++)
		std::cout << arr[n];
}
*/

/**************************************/
//Example: Pointer as Function Argument
/**************************************/
/*
#include <iostream>
void chg_ptr(int* ptr)
{
	*ptr = 200;	//change value of ptr
}
int main()
{
	int n = 1;
	int *p = &n;
	std::cout << *p << "\n";	//outputs 1
	chg_ptr(p);		//change value pointed to by p
	std::cout << *p << "\n";	//outputs 200
	return 0; 
}
*/

/*************************/
//Example: const Pointers
/*************************/
/*
#include <iostream>
using namespace std;
void chg_ptr(int* ptr)
{
	*ptr = 200;	//change value of ptr
}
void const_ptr(const int* ptr)
{
	*ptr = 200;	//error
}
int main()
{
	int n = 1;
	int *p = &n;
	cout << *p << endl;	//outputs 1
	chg_ptr(p);		    //change value pointed to by p
	cout << *p << endl;	//outputs 200
	const_ptr(p);		//Error!
	return 0; 
}
*/

/*************************/
//Example: Dynamic Memory
/*************************/
/*
#include <iostream>
using namespace std;
int main() {
	int i, n;
	cout << "Enter size of array: ";
	cin >> i;
	int * p = new (nothrow) int[i]; //may need header <new>
	if (p == nullptr)
		cout << "Error: memory could not be allocated";
	else
	{
		for (n = 0; n < i; n++)
		{
			p[n] = n;
			cout << p[n];
		}
	}
	delete[] p;
	return 0;
}
*/

/*************************************/
//Example: Dynamic Memory for Objects
/*************************************/
/*
#include <iostream>
class Box
{
   public:
      Box() { 
         std::cout << "Constructor called!\n"; 
      }
      ~Box() { 
         std::cout << "Destructor called!\n"; 
      }
};
int main( )
{
   Box* myBoxArray = new Box[4];
   delete [] myBoxArray; // Delete array
   return 0;
}
*/

/**********************************/
//Exercise: Dynamic Array Printing
/**********************************/
/*
#include <iostream>
using namespace std;
void Func(int n, int* p){
    for (int i=0; i<n; i++,p++){
        cout<<*p<<" ";
    }}
int main(){
	int i;
	cout << "Enter size of array: ";
	cin >> i;
	int * p = new (nothrow) int[i]; //may need header <new>
	for (int n = 0; n < i; n++)	{  p[n] = n; }
	Func(i,p);
	delete[] p;
	return 0;
}
*/

/**********************************/
//Fun with Pointers 1
/**********************************/
/*
#include <iostream>
using namespace std;
int main(){
    int i = 3;
    int *j;
    int **k;
    j=&i;
    k=&j;
    cout<<k<<" "<<*k<<" "<<**k<<endl;
    return 0;
}
*/

/**********************************/
//Fun with Pointers 2
/**********************************/
/*
#include <iostream>

int main(){
	int i = 5;
	int *p;
	p = &i;
	std::cout<<*&p<<" "<<&*p<<"\n";
	return 0;
}
*/

/**********************************/
//Fun with Pointers 3
/**********************************/
/*
#include <iostream>

int main(){
	short a = 320;
	char *ptr;
   	ptr =( char *)&a;
   	std::cout<<*ptr<<"\n";
	return 0;
}
*/

