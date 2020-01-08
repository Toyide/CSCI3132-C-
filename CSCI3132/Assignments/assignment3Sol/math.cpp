#include "math.h"

math::math() 
{
    INFO("Object of class math was created using the default constructor");
}

math::~math() 
{
    INFO("Object of class math deleted");
}

std::ostream& operator<<(std::ostream& stream, const math& obj)
{
    stream << obj.print();
    return stream;
}