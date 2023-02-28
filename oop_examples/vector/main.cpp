#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

int main(){

    Vector v;
 
    v.print_v();

    Vector w(4.5,3,7);

    w.print_v();

    return 0;
}