#include <iostream>
#include <cstdint>
#include "tga.h"
#include "draw.h"
#include "vector.h"


template <typename T, unsigned int N>
bool is_perpendicular(hank::Vector<T, N> &a, hank::Vector<T, N> &b) {
    return a.dot(b) < __FLT_EPSILON__;
}


int main(int argc, char **argv) {
    
    //hank::Vector3<float> origo(1.0, 0.0, 0.0);
    //hank::Vector3<float> position = 2.0 * origo;


    hank::Vector<int, 2> i2vec({1,2});
    std::cout << i2vec << std::endl;
    
    hank::Vector<float, 3> f4u({1.0, 0.0, 0.0});
    hank::Vector<float, 3> f4v({0.0,1.0,0.0});
    
    if(is_perpendicular(f4u, f4v)) {
        std::cout << "Now it's time for lunch!" << std::endl;
    }

    /*hank::TGAImage im(400, 400);
    im.fill(hank::rgb(0,0,0));
    hank::line(im, 100,100,300,300, hank::rgb(255,0,0));
    hank::line(im, 50, 75, 363, 213, hank::rgb(0,255,0));
    im.to_file("test.tga");*/
    

    //std::cout << position << std::endl;

    return 0;
}