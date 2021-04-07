#include "geometry.h"

namespace hank{

template <typename T>
Rectangle<T> find_bounding_box(const Triangle<T> &triangle) {
    Vector<T, 2> rightmost;
    Vector<T, 2> leftmost;
    Vector<T, 2> top;
    Vector<T, 2> bottom;
    T width;
    T height;

    if(triangle.a[0] > triangle.b[0] ) {
        if(triangle.c[0] > triangle.a[0]) {
            rightmost = triangle.c;
            // we know that c[0] > a[0] > b[0] => b is the leftmost
            leftmost = triangle.b; 
        } else {
            // we know that a[0] > b[0] && a[0] > c[0] => find min(b[0], c[0]) == leftmost
            rightmost = triangle.a;
            if(triangle.b[0] < triangle.c[0]) {
                leftmost = triangle.b;
            } else {
                leftmost = triangle.c;
            }
        }
    } else {
        if(triangle.b[0] > triangle.c[0]) {
            // here we know that b[0] >= a[0] and b[0] > c[0]
            rightmost = triangle.b;
            if(triangle.a[0] < triangle.c[0]) {
                leftmost = triangle.a;
            } else {
                leftmost = triangle.c;
            }
        } else {
            // here we know that b[0] >= a[0] and c[0] >= b[0]
            leftmost = triangle.a;
            rightmost = triangle.c;
        }
    };

    width = (rightmost - leftmost)[0];

    return Rectangle<T>(ulx, uly, width, height);
};


};