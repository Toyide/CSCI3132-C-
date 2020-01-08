#pragma once
#include <iostream>
#include <string>

#define LOG(x,y) std::cout << x << y << std::endl;

#define INFO(x) std::cout << "[INFO]: " << x << std::endl;
#define WARNING(x) std::cout << "[WARNING]: "<< x << std::endl;
#define ERROR(x) std::cout << "[ERROR]: " << x << std::endl;

class math 
{
private:

public:
    math();
    virtual ~math();
    virtual std::string  print() const = 0;
    virtual size_t get_size() const = 0;
};

std::ostream& operator<<(std::ostream& stream, const math& obj);