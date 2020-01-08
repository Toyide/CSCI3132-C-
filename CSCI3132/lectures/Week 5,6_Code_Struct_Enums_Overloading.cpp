/**********************************/
//Address book example - corrected
/**********************************/
#include <iostream>
#include <string>
using namespace std;
struct AddrBook {
	string name;
	string addr;
	long phone;
	string email;
};
int main(){
	AddrBook contact1;
	contact1.name = "Khurram";
	contact1.addr = "6050 University Ave";
	contact1.phone = 9021234567;
	contact1.email = "mymail@mymail.com";
	cout<<contact1.name<<"\t"
	<<contact1.addr<<"\t"
	<<contact1.phone<<"\t"
	<<contact1.email<<"\n";
	return 0;
}	

/**********************************/
//Address book with pointers
/**********************************/
/*
#include <iostream>
#include <string>
using namespace std;
struct AddrBook_t {
	string name;
	string addr;
	long long phone;
};
int main(){
	AddrBook_t * contact1 = new AddrBook_t;
	contact1->name = "Khurram";
	(*contact1).addr = "6050 University Ave";
	contact1->phone = 9021234567;
	cout << contact1->name<<"\t"
		<<contact1->addr<<"\t"
		<<(*contact1).phone<<"\n";
	return 0;
}
*/
/**********************************/
//Array of Address book struct
/**********************************/
/*
#include <iostream>
#include <string>
using namespace std;
struct AddrBook_t {
    string name;
	string addr;
	long long phone;
} contact[3];

void PrintContact(AddrBook_t *cont) {
	cout << cont->name << " " << cont->addr << " " << cont->phone << endl;
}

int main(){
    for (int i = 0; i < 3; i++) {
    	cout << "\nEnter name: ";
    	getline(cin, contact[i].name);
    	cout << "\nEnter address: ";
    	getline(cin, contact[i].addr);
    	cout << "\nEnter phone: ";
    	cin>>contact[i].phone;
    }
    for (int i = 0; i < 3; i++) {
    	AddrBook_t * addrb = &contact[i];
    	PrintContact(addrb);
    } 
    return 0; 
}
*/
/**********************************/
//Enumeration example
/**********************************/
/*
#include <iostream>
using namespace std;
enum directions_t {
    NORTH, 
    SOUTH, 
    EAST, 
    WEST
};

int main(){
    directions_t direc = NORTH;	
	int i_direc = 33;	
    i_direc = EAST;
    cout<<direc<<endl;	
	cout<<i_direc<<endl;
    return 0;
}
*/
/***********************************/
//Function overloading - Example 1
/***********************************/
/*
#include <iostream> 
using namespace std; 
  
int add(int a, int b) {
       return (a + b);
}

int add(int a, int b, int c) {
       return (a + b +c);
}

int main() {
       int a = 3, b = 2;
       cout << add(a, b) << '\n';		
       int c = 1;
       cout << add(a, b, c) << '\n';		
       return 0;
}
*/
/***********************************/
//Function overloading - Example 2
/***********************************/
/*
#include <iostream> 
using namespace std; 
  
int divide(int a, int b){
       return (a/b);
}

double divide(double a, double b){
       return (a/b);
}

int main(){
       int a = 3, b = 2;
       cout << divide(a, b) << '\n';
       double c = 3.0, d = 2.0;
       cout << divide(c, d) << '\n';
       return 0;
}
*/
/***********************************/
//Function overloading - Example 2
/***********************************/
/*
#include <iostream> 
using namespace std; 
  
double multiply(int a, double b) {
	return (a * b);
}

double multiply(double a, int b) {
	return (a * b);
}

int main() {
	int a = 3;
	double b = 2.0;
	cout << multiply(a, b) << '\n';
	cout << multiply(b, a) << '\n';
	return 0;
}
*/
/***********************************/
//Function overloading - Example 3
/***********************************/
#include <iostream> 
using namespace std; 
  
double multiply(int a, double b) {
	return (a * b);
}

double multiply(double a, int b) {
	return (a * b);
}

int main() {
	int a = 3;
	double b = 2.0;
	cout << multiply(a, b) << '\n';
	cout << multiply(b, a) << '\n';
	return 0;
}
*/
/***********************************/
//Numeric Promotion - Example 2
/***********************************/
/*
#include <iostream>
#include <typeinfo> // for typeid()

int main()
{
	long l(3);
	double d(4.0);
	short s(2);
	std::cout << typeid(l+d+s).name() 
		<< " " << l+d+s << std::endl; 
	return 0;
}
*/
/***********************************/
//Function Template - Example
/***********************************/
/*
#include <iostream>
#include <typeinfo> // for typeid()
using std::cout;
template <class T>
T multiply(T a, T b) {
	T result = a * b;
	return result;
}
int main() {
	int a = 3, b=2;
	double c = 2.0, d = 5.0;
	cout << multiply<int>(a, b) << '\n';
	cout << multiply<double>(c, d) << '\n';
	return 0;
}
*/
/***********************************/
//Function Template - Exercise
/***********************************/
/*
#include <iostream>
#include <typeinfo> // for typeid()
using std::cout;
template <class T, class U>
	T multiply(T a, U b) {
	return a*b;
}
int main() {
	int a = 3, b=2;
	double c = 1.1, d = 2.2;
	cout << multiply(a, b) << '\n';
	cout << multiply(c, d) << '\n';
	cout << multiply(a, c) << '\n';
	cout << multiply(d, b) << '\n';
	return 0;
}
*/
/***********************************************/
//Operator Overloading - Complex Number Example
/***********************************************/
/*
#include <iostream>
using namespace std;

struct Complex {
   Complex (double r, double i) : real(r), imag(i) {}
   Complex operator+ (Complex &num);
   void Display() {cout<<real<<", "<<imag<<endl;}
private:
   double real, imag;
};

// Operator overloaded using a member function
Complex Complex::operator+ (Complex &num) {
   return Complex(real + num.real, imag + num.imag);
}
int main() {
   Complex a = Complex( 3.0, 4.0 );
   Complex b = Complex( 2.0, 5.0 );
   Complex c = Complex( 0.0, 0.0 );

   c = a + b;	//outputs 5.0, 9.0 i.e. 5+9i
   c.Display();
}
*/
/************************************************/
//Operator Overloading - Complex Number Exercise
/************************************************/
/*
#include <iostream>
using namespace std;

class Point {
public:  
   Point (double x, double y) : ptX(x), ptY(y) {}
   Point operator* (int i);
   Point operator/ (int i);
   void Display() {cout<<ptX<<", "<<ptY<<endl;}
private:
   double ptX, ptY;
};

Point Point::operator* (int i) {
   ptX *= i;
   ptY *= i;
   return *this;
}

Point Point::operator/ (int i) {
   ptX /= i;
   ptY /= i;
   return *this;
}

int main() {
   Point p1 = Point(5.0, 10.0 );
   Point p2 = Point(0.0, 0.0 );
   p2 = p1 * 2;	//outputs 10.0, 20.0
   p2.Display();
   p2 = p1 / 5; //outputs 2.0, 4.0
   p2.Display();
}
*/