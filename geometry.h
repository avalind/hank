#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include "vector.h"

namespace hank {

template <typename T>
struct Triangle {
  Vector<T, 2> a;
  Vector<T, 2> b;
  Vector<T, 2> c;

  Triangle() {};

  Triangle(Vector<T, 2> _a,
           Vector<T, 2> _b, 
           Vector<T, 2> _c):
    a(_a), b(_b), c(_c) {};
};

template <typename T>
Triangle<T> make_2d_triangle(T a1, T a2, T b1, T b2, T c1, T c2) {
  return Triangle<T>(
    Vector<T, 2>({a1, a2}),
    Vector<T, 2>({b1, b2}),
    Vector<T, 2>({c1, c2})
  );
};

template <typename T>
struct Rectangle {
  Vector<T, 2> upper_left;
  T width;
  T height;

  Rectangle() {};
  Rectangle(T ulx, T uly, T width, T height) {
    this->upper_left = Vector<T, 2>({ulx, uly});
    this->width = width;
    this->height = height;
  }
};

template <typename T>
Rectangle<T> find_bounding_box(Triangle<T> &triangle);

template <typename T>
bool is_within(Triangle<T>& triangle, T& width, T& height);

template <typename T>
bool is_within(Rectangle<T>& rect, T& width, T& height);

};

#endif /* GEOMETRY_H_ */
