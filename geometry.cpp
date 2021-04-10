#include "vector.h"
#include "geometry.h"

namespace hank{

template <typename T>
bool is_within(Triangle<T>& triangle, T& width, T& height) {
    // tests whether the geometric primitive is inside a 
    // given rectangle defined by (0,0) and (width, height)
    bool within = true;
    within &= 
        (triangle.a[0] < width) &&
        (triangle.b[0] < width) &&
        (triangle.c[0] < width);
    within &=
        (triangle.a[1] < height) &&
        (triangle.b[1] < height) &&
        (triangle.c[1] < height);
    return within;    
}

template <typename T>
Rectangle<T> find_bounding_box(Triangle<T> &triangle) {
    Vector<T, 2> rightmost;
    Vector<T, 2> leftmost;
    Vector<T, 2> top;
    Vector<T, 2> bottom;
    T width;
    T height;
    T ulx;
    T uly;

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

    if(triangle.a[1] > triangle.b[1]) {
        if(triangle.c[1] > triangle.a[1]) {
            top = triangle.c;
            bottom = triangle.b;
        } else {
            top = triangle.a;
            if(triangle.b[1] < triangle.c[1]) {
                bottom = triangle.b;
            } else {
                bottom = triangle.c;
            }
        }

    } else {
        if(triangle.b[1] > triangle.c[1]) {
            top = triangle.b;
            if(triangle.a[1] < triangle.c[1]) {
                bottom = triangle.a;
            } else {
                bottom = triangle.c;
            }
        } else {
            bottom = triangle.a;
            top = triangle.c;
        }
    }

    width = (rightmost - leftmost)[0];
    height = (top - bottom)[1];
    ulx = leftmost[0];
    uly = top[1];

    return Rectangle<T>(ulx, uly, width, height);
};

// Instantiation tricks
template Rectangle<int> find_bounding_box(Triangle<int> &triangle);
template Rectangle<float> find_bounding_box(Triangle<float> &triangle);
template Rectangle<double> find_bounding_box(Triangle<double> &triangle);

};