#include<iostream>
/****Flying Behaviours*******/
class FlyBehaviour{
public:
    virtual void fly() = 0;
};
class FlyWithWings : public FlyBehaviour{
public:
    void fly(){ std::cout<<"   I really fly!\n"; }
};
class FlyNoWay : public FlyBehaviour{
public:
    void fly(){ std::cout<<"   What is fly?\n"; }
};
class FlyWithRocket : public FlyBehaviour{
public:
    void fly(){ std::cout<<"   Rocket Power ... Yay!\n"; }
};

//Add more flying behaviours here

/****Quacking Behaviours*******/
class QuackBehaviour{
public:
    virtual void quack() = 0;
};

class Quack : public QuackBehaviour{
public:
    void quack(){ std::cout<<"   I really quack!\n"; }
};

class MuteQuack : public QuackBehaviour{
public:
    void quack(){ std::cout<<"   .............!\n"; }
};

class Squeak : public QuackBehaviour{
public:
    void quack(){ std::cout<<"   Squeak...Squeak!\n"; }
};


//Add more quacking behaviours here

/****Duck and all kinds of them*******/
class Duck{
    QuackBehaviour* quackBehaviour = nullptr;
    FlyBehaviour* flyBehaviour = nullptr;
    // other code
    
public:
    Duck(){}
    void setFlyBehaviour(FlyBehaviour* f) { flyBehaviour = f; }
    void setQuackBehaviour(QuackBehaviour* q) { quackBehaviour = q; }
    void performQuack(){
        quackBehaviour->quack();
    }
    void performFly(){
        flyBehaviour->fly();
    }
    virtual void display() = 0;
    ~Duck(){
        if (quackBehaviour) delete quackBehaviour;
        if (flyBehaviour) delete flyBehaviour;
    }
};

class ModelDuck : public Duck {
public:
    ModelDuck(){
        setQuackBehaviour(new Quack());
        setFlyBehaviour(new FlyNoWay());
    }
    void display(){ std::cout<<"\nModel Duck\n"; }
};

class MallardDuck : public Duck{
public:
    MallardDuck(){
        setQuackBehaviour(new Quack());
        setFlyBehaviour(new FlyWithWings());
    }
    void display(){ std::cout<<"\nMallard Duck\n"; }
};

class RubberDuck : public Duck{
public:
    RubberDuck(){
        setQuackBehaviour(new MuteQuack());
        setFlyBehaviour(new FlyNoWay());
    }
    void display(){ std::cout<<"\nRubber Duck\n"; }
};

//Add more kinds of Ducks here

/****Lets make some Ducks*******/
int main(){
    
    Duck* duck = new MallardDuck();
    duck->display();
    duck->performQuack();
    duck->performFly();
    if(duck) delete duck;

    duck = new RubberDuck();
    duck->display();
    duck->performQuack();
    duck->performFly();
    duck->setQuackBehaviour(new Squeak());
    duck->setFlyBehaviour(new FlyWithRocket());
    duck->performQuack();
    duck->performFly();
    if(duck) delete duck;
    
    duck = new ModelDuck();
    duck->display();
    duck->performQuack();
    duck->performFly();
    if(duck) delete duck;
}

