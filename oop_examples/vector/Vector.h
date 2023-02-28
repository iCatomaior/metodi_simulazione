#include <iostream>

class Vector {
    public:
        double x;
        double y;
        double z;  

        //default constructor
        Vector(){
            x=0;
            y=0;
            z=0;
        }

        Vector(double vx, double vy, double vz){
            x=vx;
            y=vy;
            z=vz;
        }

        double mod();  

        void print_v();
};