#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <cmath>

namespace hank {

template <typename T>
class Vector3 {
  public:
    T x;
    T y;
    T z;

    Vector3() {};
    Vector3(T _x, T _y, T _z): 
      x(_x), y(_y), z(_z) {};
    Vector3(const Vector3<T>& rhs) {
      this->x = rhs.x;
      this->y = rhs.y;
      this->z = rhs.z;
    };

    T length() {
      return std::sqrt(
        this->x * this->x + 
        this->y * this->y + 
        this->z * this->z);
    }

    Vector3<T> norm() {
      T len = this->length();
      return Vector3<T>(this->x / len,
                        this->y / len,
                        this->z / len);
    }

    Vector3<T> operator/(T a) {
      return Vector3<T>(this->x / a,
                        this->y / a,
                        this->z / a);
    }

    Vector3<T> operator+(const Vector3<T>& a) {
      return Vector3<T>(this->x + a.x,
                        this->y + a.y,
                        this->z + a.z);   
    };

    Vector3<T> operator*(T a) {
      return Vector3<T>(this->x * a,
                        this->y * a,
                        this->z * a);
    };
    
    Vector3<T> operator-(const Vector3<T>& a) {
      return Vector3<T>(this->x - a.x,
                        this->y - a.y,
                        this->z - a.z);
    };

    friend std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) {
      os << "vector(" << v.x << ", " << v.y << ", " << v.z << ")";
      return os;
    }

    friend Vector3<T> operator*(T a, const Vector3<T>& b) {
      return Vector3<T>(
        a * b.x,
        a * b.y,
        a * b.z
      );
    };
};

};

#endif /* VECTOR_H_ */