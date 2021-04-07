#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <cmath>
#include <initializer_list>

namespace hank {

template <typename T, unsigned int N>
class Vector {
  private:
    T elem[N];
  public:
    
    Vector(std::initializer_list<T> l) {
      int idx = 0;
      for(auto it = std::begin(l); it != std::end(l); ++it) {
        if(idx >= N)
          break;
        this->elem[idx] = *it;
        idx++;
      }
      // handle the case where we only initialize part of the vector,
      // for now, the rest of the elements are just zeroes.
      while(idx < N) {
        this->elem[idx] = 0;
        idx++;
      }
    };

    Vector() {};

    Vector(const Vector<T, N>& rhs) {
      for(int c = 0; c < N; c++) {
        this->elem[c] = rhs.elem[c];
      }
    }

    T& operator[] (int index) {
      return this->elem[index];
    }

    Vector<T, N> operator+(const Vector<T, N>& a) {
      Vector<T, N> ret;
      for(int c = 0; c < N; c++)
        ret.elem[c] = this->elem[c] + a.elem[c];
      return ret;
    };

    Vector<T, N> operator-(const Vector<T, N>& a) {
      Vector<T, N> ret;
      for(int c = 0; c < N; c++)
        ret.elem[c] = this->elem[c] - a.elem[c];
      return ret;
    };

    Vector<T, N> operator*(T a) {
      Vector<T, N> ret;
      for(int c = 0; c < N; c++)
        ret.elem[c] = this->elem[c] * a;
      return ret;
    };

    Vector<T, N> operator/(T a) {
      Vector<T, N> ret;
      for(int c = 0; c < N; c++)
        ret.elem[c] = this->elem[c] / a;
      return ret;
    };

    T l2_norm() {
      T l2_squared;
      for(int c = 0; c < N; c++)
        l2_squared += this->elem[c] * this->elem[c];
      return std::sqrt(l2_squared);
    };

    Vector<T, N> normalize() {
      T sf = this->l2_norm();
      Vector<T, N> ret;
      for(int c = 0; c < N; c++)
        ret.elem[c] = this->elem[c] / sf;
      return ret;
    };

    T dot(const Vector<T, N>& other) {
      T ret;
      for(int c = 0; c < ret; c++)
        ret += this->elem[c] * other.elem[c];
      return ret;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T, N>& v) {
      os << "vector(" << v.elem[0];
      for(int c = 1; c < N; c++) {
        os << ", " << v.elem[c];
      }
      os << ")";
      return os;
    };

    friend Vector<T, N> operator*(T a, const Vector<T, N>& b) {
      Vector<T, N> ret;
      for(int c = 0; c < N; c++)
        ret.elem[c] = a * b.elem[c];
      return ret;
    };

};


};


#endif /* VECTOR_H_ */