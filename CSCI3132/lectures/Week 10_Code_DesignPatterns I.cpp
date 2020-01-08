/**************************************/
//Singleton Design Pattern - using new
/**************************************/

#include <iostream>
class MyReg{
    static MyReg* regInstance;
    MyReg(){
        std::cout<<" Yay, I've been created";
    }
public:
    static MyReg* GetInstance();
};

MyReg* MyReg::regInstance = 0;
MyReg* MyReg::GetInstance(){
    if (regInstance == nullptr){
        MyReg* regInstance = new MyReg();            
    }
    return regInstance;
}
int main(){
    MyReg::GetInstance();
}

/***************************************/
//Singleton Design Pattern - using RAII
/***************************************/
/*#include <iostream>
class MyReg{
    MyReg(){
        std::cout<<" Yay, I've been created";
    }
public:
    static MyReg& GetInstance(){
        static MyReg regInstance;
        return regInstance;
    }
};
int main(){
    MyReg::GetInstance();
}
*/
