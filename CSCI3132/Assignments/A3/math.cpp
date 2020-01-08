#include "math.h"

//default math
math::math(){
    INFO("Object of class math was created using the default constructor");
}
//deconstructor
math::~math(){
    INFO("Object of class math deleted");
}
//print
std::string math::print() const{
    std::string v;
	v = "This is math class print\n";
    return v;
}

size_t math::get_size() const {
    return 0;
}

std::ostream& operator<<(std::ostream& stream, const math& obj){
    stream << obj.print();
    return stream;
}