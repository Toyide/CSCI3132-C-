/********************************/
//People and Student classes
//Inheritance, method overriding
/********************************/
#include <iostream>
#include <string>

using namespace std;
class People {
protected:
  int id;
  string name;
  string address;
public:
  People (int id, string name, string address){
      this->id = id;
      this->name = name;
      this->address = address;
  }
  void DisplayProfile();
  void UpdateAddress(string newAddr);
};

class Student : public People {
protected:
   int program;
   int semester;
   float grade;
public:
   Student (int id, string name, string address, int program, int semester, float grade) : People(id,name,address){
       this->program = program;
       this->semester = semester;
       this->grade = grade;
   }
   void DisplayProfile();
   void UpdateGrade(float grade);
};

void People::DisplayProfile(){
	cout <<"ID: "<<id<<", Name: "<<name<<endl;
	cout <<"Addr: "<<address<<endl;
}

void Student::DisplayProfile(){
	cout <<"ID: "<<id<<", Name: "<<name<<endl;
	cout <<"Addr: "<<address<<endl;
	cout <<"Program: "<<program;
	cout <<", Semester: "<<semester<<endl;
	cout <<"GPA: "<<grade<<endl;
	cout<<endl;
}		

int main(){
    People* john = new People(5542, "John Snow", "Somewhere on the wall");
    Student* bran = new Student(7944, "Brandon Stark", 	"Somewhere beyond the wall", 62255, 6, 3.98);

    john->DisplayProfile();
	
    bran->DisplayProfile();

}

/**********************************/
//Polymorphism - Virtual Functions
/**********************************/
/*
#include <iostream>

using namespace std;

class shape	{
public:
	virtual float CalcArea(float r) {return 0;} 
};
class circle : public shape{
public:
	float CalcArea(float r) { return (3.14159*r*r); }
};
int main(){
	shape *s1 = new shape;
	cout<<s1->CalcArea(2); 
}
*/

/*************************************/
//Destructors and Virtual Destructors
/*************************************/
/*
#include <iostream>
using namespace std;

class shape{
public:
	virtual ~shape(){cout<<"Shape Destructor\n";}
};

class circle : public shape{
public:
	~circle(){cout<<"Circle Destructor\n";}
};

int main(){
	shape *s1 = new shape;  //s1 points to base class object
	shape *s2 = new circle; //s2 points to derived class object
	delete s1;              //base class destructor called
	delete s2;              //derived, then base class destructor called 
}

*/

/*******************************************/
//Abstract Class and Pure Virtual Functions
/*******************************************/
/*
#include <iostream>
using namespace std;

class shape{
public:
	virtual float CalcArea(float r) = 0; //pure virtual function
};

class circle : public shape{
public:
	float CalcArea(float r){ return (3.14159*r*r); }
};

int main(){
	//shape sh;                 //error - Cannot initialize Abstract class
	//shape *sh = new shape;    //error - Cannot initialize Abstract class
	shape *s1 = new circle;     //valid
	cout<<s1->CalcArea(2)<<"\n"; //calls derived class' CalcArea()
}
*/
