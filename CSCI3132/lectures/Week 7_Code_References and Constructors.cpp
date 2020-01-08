/***************************************/
//Using References - Square of a number 
/***************************************/
#include <iostream>
void square(int &x){
    x *= x;
}

int main(){
    int x = 10;
    square(x);
    std::cout<<x<<std::endl;
}

/***************************************/
//Using References - Square of a number 
/***************************************/
/*
#include <iostream>
using namespace std;
void Test1(int &x, int &y){
   cout << "Enter two numbers" << endl;
   cin >> x >> y;
}
void Test2(int &x, int &y, int &z){
   x *= 2;
   y *= 2;
   z *= 2;
}
void Test3(int x, int y, int z){
   x /= 2;
   y /= 2;
   z /= 2;
}
void Display(const int &x, const int &y, const int &z){
   cout << x << ", " << y << ", " << z << endl;
}
int main() {
   int a = 1, b = 1, c = 1;
   Display(a, b, c);
   Test1(a, b);
   Display(a, b, c);
   Test2(a, b, c);
   Display(a, b, c);
   Test3(a, b, c);
   Display(a, b, c);
}
*/

/***************************************/
//String Swap Using Pointers 
/***************************************/
/*
#include <iostream>
#include <string>

using namespace std;

void Swap(string* a, string *b){
    string tmpstr = *a;
    *a = *b;
    *b = tmpstr;
}
void Display(string * a, string* b){
	cout<<*a<<*b<<endl;
}
int main(){
    string str1 = " Hello ";
    string str2 = " World ";
    Display(&str1, &str2);
    Swap(&str1, &str2);
    Display(&str1, &str2);
}
*/

/***************************************/
//String Swap Using References 
/***************************************/
/*
#include <iostream>
#include <string>
using namespace std;
void Swap(string& a, string & b){
    string str = a;
    a = b;
    b = str;
}
void Display(const string& a, const string &b){
    cout<<a<<b<<endl;
}
int main(){
    string str1 = " Hello ";
    string str2 = " World ";
    Display(str1, str2);
    Swap(str1, str2);
    Display(str1, str2);
}
*/

/***************************************/
//Constructors
/***************************************/
/*
#include <iostream>
#include <string>
using namespace std;

class Point {
	double ptX, ptY;
public:
   Point() { ptX = 0; ptY = 0; }	
//   Point(double x = 0, double y = 0) : ptX(x), ptY(y) {} //Try uncommenting
   Point(double x, double y = 0) : ptX(x), ptY(y) {}
//   Point(double x, double y) : ptX(x), ptY(y) {} 	
   void Display() { cout << ptX << ", " << ptY << endl; }
};
int main() {
   Point pt1;
   Point pt2(5);
   Point pt3(7, 7);
   pt1.Display();
   pt2.Display();
   pt3.Display();
   pt3 = pt2;
   pt3.Display();
}
*/

/***************************************/
//Copy Constructor
/***************************************/
/*
#include <iostream>
#include <string>

using namespace std;

class Point {
	double ptX, ptY;
public:
	Point() { ptX = 0; ptY = 0; }
	Point(double x, double y = 0) : ptX(x), ptY(y) {}
	Point(Point & pt) {	ptX = pt.ptX; ptY = pt.ptY; }
	void Display() { cout << ptX << ", " << ptY << endl; }
};
int main() {
	Point pt1;
	pt1.Display();
	Point pt2(5);
	pt2.Display();
	Point pt3 = pt2;
	pt3.Display();
}
*/
