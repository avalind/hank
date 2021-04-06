#include <iostream>
#include "tga.h"
#include "draw.h"
#include "vector.h"


int main(int argc, char **argv) {
    
    hank::Vector3<float> origo(1.0, 0.0, 0.0);
    hank::Vector3<float> position = 2.0 * origo;


    /*
    hank::TGAImage im(400, 400);
    im.fill(hank::rgb(0,125,125));
    im.put_pixel(200, 200, hank::rgb(255, 0, 255));
    im.to_file("test.tga");
    */

    std::cout << position << std::endl;

    return 0;
}