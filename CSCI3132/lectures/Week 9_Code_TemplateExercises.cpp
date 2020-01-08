/****************************************************/
//Exercise 2: Template function with static variable
/****************************************************/
#include <iostream>
template <class T>
void GrowShape(const T&g){
        static T size = 1;
        size *= g;
        std::cout<<size<<std::endl;
}
int main(){
    int x = 2;
    float y = 1.1;
    GrowShape(x);
    GrowShape(x);
    GrowShape(y);
    GrowShape(y);
    GrowShape(x);
}

/****************************************************/
//Exercise 3: Template Class with static variable
/****************************************************/
/*
#include <iostream>
using namespace std;
 
template <class T>
class shape{
protected:
    T dim;
public:
    shape(const T&d):dim(d){}
    void GrowShape(const T&g){
        static int count = 0;
        dim *= g;        
        count++;
        cout<<count<<": "<<dim<<endl;
    }
};
int main()
{
    shape<int> s(1);
    s.GrowShape(2);
    s.GrowShape(3);
    s.GrowShape(4);
    shape<float> f(1.0f);
    f.GrowShape(1.1f);
    f.GrowShape(2.2f);
}
*/
