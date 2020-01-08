
/***************************************/
//Area of Square and Circle - Solution 1
/***************************************/
#include<iostream>
class Square {
private: float side;
public:
	void SetSide(float x) {
		side = x;
	}

	float GetArea() {
		return side*side;
	}
};

class Circle {
private: float radius;
public:
	void SetRadius(float x) {
		radius = x;
	}

	float GetArea() {
		return 3.14159*radius*radius;
	}
};


int main() {
	Circle c;
	Square s;
	int i;
	std::cin>>i;
	
	c.SetRadius(i);
	s.SetSide(i);
	std::cout<<"Area of circle = "<<c.GetArea()
	        <<"\nArea of square = "<<s.GetArea();
}

/***************************************/
//Area of Square and Circle - Solution 2
/***************************************/
/*
#include<iostream>
class Shape {
private: float dim;
public:
	void SetDim(float x) {
		dim = x;
	}

	float GetAreaSq() {
		return dim*dim;
	}
	
	float GetAreaCirc(){
		return 3.14159*dim*dim;
	}
};

int main() {
	Shape sh;
	int i;
	std::cin>>i;
	
	sh.SetDim(i);
	std::cout<<"Area of circle = "<<sh.GetAreaCirc()
	        <<"\nArea of square = "<<sh.GetAreaSq();
}
*/
/***************************************/
//Area of Square and Circle - Solution 3
/***************************************/
/*
#include<iostream>

class Shape {
protected: float dim;
public:
	void SetDim(float x) {
		dim = x;
	}
};

class sq : public Shape {
public:
	float GetArea() {
		return dim*dim;
	}
};

class circ : public Shape {
public:
	float GetArea(){
		return 3.14159*dim*dim;
	}
};

int main() {
	float i;
	std::cin>>i;
	
	circ c;
	sq s;
	c.SetDim(i);
	s.SetDim(i);
	std::cout<<"Area of circle = "<<c.GetArea()
	        <<"\nArea of square = "<<s.GetArea();
}
*/
/***************************************/
//Exercise: Person->Child->Daughter,Son
/***************************************/
/*
#include<iostream>
#include<string>

class Person
{
private:
    std::string name;
public:
std::string GetName()
{return name;}

void SetName(std::string nm)
{name = nm;}
};

class Child : public Person
{};

class Daughter : public Child
{};

class Son : public Child
{};

int main()
{
    Person p;
    p.SetName("Khurram");
    std::cout <<p.GetName();
    system("pause");

}
*/
/**********************************************/
//Multiple Inheritance Example - Colored Shapes
/**********************************************/
/*
#include<iostream>
#include<string>

using namespace std;

class shape {
protected:
   float dim;
public:
   shape() {
      dim = 1;
      cout << "\nDefault dimension is "<<dim<<endl;
   }
   void SetDim(float n) {
      dim = n;
   }
};

class color {
protected:
   string m_clr;
public:
   color() {
      m_clr = "White";
      cout << "\nDefault color is "<<m_clr<<endl;
   }
   void SetColor(string l_clr) {
      m_clr = l_clr;
   }
   string GetColor() {
      return m_clr;
   }
};

class sq : public shape, public color {
public:
   sq() {
      m_clr = "Green";
      cout<< "\nDefault square is "<<m_clr<<endl;
   }
   float CalcArea() {
      return dim*dim;
   }
};

class circ : public shape, public color {
public:
   circ() {
      m_clr = "Red";
      cout << "\nDefault circle is "<<m_clr<<endl;
   }
   float CalcArea() {
      return 3.14159*dim*dim;
   }
};

int main() {
   float n;
   string clr;
   cout << "Enter dimension: ";
   cin >> n;
   cout << "Enter color: ";
   cin >> clr;
   circ c;
   sq s;
   c.SetColor(clr);
   s.SetDim(n);
   cout << "\nArea of the "<<c.GetColor()<<" Circle is: " << c.CalcArea() <<"\n";
   cout << "\nArea of the "<<s.GetColor()<<" Square is: " << s.CalcArea() << "\n";
}
*/