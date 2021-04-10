#include <iostream>
#include <cstdint>
#include "tga.h"
#include "draw.h"
#include "vector.h"
#include "geometry.h"


template <typename T, unsigned int N>
bool is_perpendicular(hank::Vector<T, N> &a, hank::Vector<T, N> &b) {
    return a.dot(b) < __FLT_EPSILON__;
}


int main(int argc, char **argv) {
    
    //hank::Vector3<float> origo(1.0, 0.0, 0.0);
    //hank::Vector3<float> position = 2.0 * origo;


    /*
    hank::Vector<int, 2> i2vec({1,2});
    std::cout << i2vec << std::endl;
    
    hank::Vector<float, 3> f4u({1.0, 0.0, 0.0});
    hank::Vector<float, 3> f4v({0.0,1.0,0.0});
    
    if(is_perpendicular(f4u, f4v)) {
        std::cout << "Now it's time for lunch!" << std::endl;
    }*/

    hank::Triangle<int> tri = hank::make_2d_triangle<int>(50+1,50+7,250+30,150+31,150+45,200+46);

    hank::Rectangle<int> bb = hank::find_bounding_box<int>(tri);

    hank::TGAImage im(600, 600);
    im.fill(hank::rgb(0,0,0));

    hank::draw(im, tri, hank::rgb(125,0, 255));
    hank::draw(im, bb, hank::rgb(255, 0, 255));
    im.to_file("test.tga");
    

    return 0;
}