#include <iostream>
#include <cmath>
#include "Vector.h"

double Vector::mod(){
    return sqrt(x*x+y*y+z*z);
}

void Vector::print_v(){
    std::cout << "(" << x << "," << y << "," << z << ")" << std::endl;
}

