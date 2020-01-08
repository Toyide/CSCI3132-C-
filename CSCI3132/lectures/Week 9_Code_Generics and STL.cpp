/*************************************/
// Overloaded template function
/*************************************/
#include <iostream>
#include <string>
using namespace std;
char* prod(char* x, char *y) { 
	char * p = new char[2];
	p[0]=*x;	p[1]=*y;
	return p;
 }
template <class T>
T prod(T x, T y) { return x*y; }
int main() {
	int x = 1, y = 2;  char a='A', b='B'; 	cout << prod(x, y) << " " << prod(&a, &b) << endl;
	return 0;
}

/*************************************/
// Template Point Class and its use
/*************************************/
/*
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Point {
private:
    T ptX;
    T ptY;
public:
    Point() {  ptX = 0; ptY = 0;  }
    Point(T x, T y) {  ptX = x; ptY = y;  }
    Point(const Point & pt) {
	    ptX = pt.ptX; //could also use ptX = pt.GetX();
	    ptY = pt.ptY; //could also use ptY = pt.GetY();
	}
	T GetX() { return ptX; }
	T GetY() { return ptY; }

	void SetPoint(T x, T y) { ptX = x; ptY = y; }
	void ShowPoint() { 
		cout << "(" << ptX << ", " << ptY << ")\n"; 
	}
	Point & operator* (T val1) {
		ptX = ptX * val1;
		ptY = ptY * val1;
		return *this;
	}
	Point & operator= (const Point & p) {
		ptX = p.ptX;
		ptY = p.ptY;
		return *this;
	}
	Point & operator*= (const T & i) {
		ptX *= i;
		ptY *= i;
		return *this;
	}
};

int main() {
	int x = 2, y = 5;
	double dx = 2.2, dy = 3.3;
	Point<int> pt;	//note the type parameter
	pt.SetPoint(x, y);
	pt *= 2;
	pt.ShowPoint();
	
	Point<double> dpt;
	dpt.SetPoint(dx, dy);
	dpt = dpt * 2;
	dpt.ShowPoint();
}
*/

/*************************************************/
// Vector - Example 1: Using STL vector container
/*************************************************/
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class People {
protected:
	int id;
	string name;
	string address;
public:
	People (int id, string name, string address){ 
	    this->id=id; 
	    this->name=name; 
	    this->address=address;
	}
};

int main(){
   vector <People> myPeople;
   People p1(1,"Alpha","Here");
   myPeople.push_back(p1);
   People * p2 = new People(2, "Beta", "There");
   myPeople.push_back(*p2);
   cout << "Total People: " << myPeople.size()<<endl;
   cout << "Max Size: " << myPeople.max_size() << endl;

   while(!myPeople.empty()) {
      myPeople.pop_back();
	cout << "People remaining: " << myPeople.size()<< endl;
   }
   return 0;
}
*/

/***********************************************************/
// Vector - Example 2: Using Iterator with vector container 
/***********************************************************/
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class People {
protected:
	int id;
	string name;
	string address;
public:
	People (int id, string name, string address){ 
	    this->id=id; 
	    this->name=name; 
	    this->address=address;
	}
	void DisplayProfile(){
	    cout <<"ID: "<<id<<", Name: "<<name<<endl;
	    cout <<"Addr: "<<address<<endl;
    }
};

int main(){
    vector <People> myPeople;
    People p1(1,"Alpha","Here");
    myPeople.push_back(p1);
    People * p2 = new People(2, "Beta", "There");
    myPeople.push_back(*p2);
    vector<People>::iterator it;
    for (it = myPeople.begin(); 
        it != myPeople.end(); it++) {
	    it->DisplayProfile();
    }
    return 0;
}
*/

/***************************************************************/
// Vector - Example 3: Accessing vector elements using iterator    
/***************************************************************/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class People {
protected:
	int id;
	string name;
	string address;
public:
	People (int id, string name, string address){ 
	    this->id=id; 
	    this->name=name; 
	    this->address=address;
	}
	void SetName(string s){ name = s; }
	void DisplayProfile(){
	    cout <<"ID: "<<id<<", Name: "<<name<<endl;
	    cout <<"Addr: "<<address<<endl;
    }
};

int main(){
	vector <People> myPeople;
	People p1(1,"Alpha","Here");
	myPeople.push_back(p1);
	People * p2 = new People(2, "Beta", "There");
	myPeople.push_back(*p2);
	vector<People>::iterator it;
	it = myPeople.end() - 1;
	string nm = "I am Theta";
	it->SetName(nm);
	it->DisplayProfile();
	return 0;
}
*/

/*********************************************************/
// Vector Exercise - Assigning a vector in reverse order  
/*********************************************************/
/*
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    for (int i=0; i<10; i++)
    vec.push_back(i);
    vector<int>::iterator it;	//could say auto it=vec.begin(); …
    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
    }
    cout << "Now reversing order\n";
    vector<int> newvec;
    newvec.insert(newvec.begin(), vec.rbegin(), vec.rend());
    for (it = newvec.begin(); it != newvec.end(); it++)
    {
        cout << *it << endl;
    }
}
*/

/***********************/
// Deque Example   
/***********************/
/*
#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> d = {10, 20, 30, 40, 50};
    d.push_front(60);
    d.push_back(0);
    for(int n : d) {
        cout << n << '\n';
    }
}
*/

/***********************/
// Map Example   
/***********************/
/*
#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;
int main(){
	map<string, int> mpPlanets;
	mpPlanets.insert(make_pair("Mercury", 1));
	mpPlanets.insert(make_pair("Venus", 2));
	mpPlanets["Earth"] = 4;
	mpPlanets["Mars"] = 4;
	mpPlanets["Jupiter"] = 5;
	mpPlanets["Saturn"] = 6;
	mpPlanets["Uranus"] = 7;
	mpPlanets["Neptune"] = 8;
	mpPlanets["Earth"] = 3;
    
    map<string, int>::iterator it = mpPlanets.begin();
    while (it != mpPlanets.end()){
     	cout<<it->first<<" - "<<it->second<<endl;
    		it++;
    	}
    
    if (mpPlanets.find("Earth") != mpPlanets.end())
    	cout << "We found 'Earth‘"<< endl;
    if (mpPlanets.find("Sun") == mpPlanets.end())
    	cout << "'Sun' not found" << endl;
    return 0;
}
*/

/***********************/
// Example: Reverse Map     
/***********************/
/*
#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;
struct RevOrder
{
	bool operator()(const string & left, const string & right) const
	{
		return (left > right);
	}
};

int main(){
	map< string, int, RevOrder > mpPlanets;
//	map<string, int> mpPlanets;
	mpPlanets.insert(make_pair("Mercury", 1));
	mpPlanets.insert(make_pair("Venus", 2));
	mpPlanets["Earth"] = 4;
	mpPlanets["Mars"] = 4;
	mpPlanets["Jupiter"] = 5;
	mpPlanets["Saturn"] = 6;
	mpPlanets["Uranus"] = 7;
	mpPlanets["Neptune"] = 8;
	mpPlanets["Earth"] = 3;

    map<string, int>::iterator it = mpPlanets.begin();
    while (it != mpPlanets.end()){
     	cout<<it->first<<" - "<<it->second<<endl;
    		it++;
    	}
    
    if (mpPlanets.find("Earth") != mpPlanets.end())
    	cout << "We found 'Earth‘"<< endl;
    if (mpPlanets.find("Sun") == mpPlanets.end())
    	cout << "'Sun' not found" << endl;
    return 0;
}
*/
