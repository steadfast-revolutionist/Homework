#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include "line.h"

template <typename T>
class Point {
  public:
    Point() = default;
    Point(T tempX, T tempY) : x(tempX), y(tempY) { }
    inline Point<T> input(const T &x, const T &y)
                    { return Point(x, y); }
    inline void input() {
      std::cout << "Please input the point\n";
      std::cin >> x >> y;
    }
    inline void input(const T, const T);
    inline void output() {
      std::cout << '(' << x << ", " << y << ")\n";
    }
    T x;
    T y;
};

template <typename T> inline void
Point<T>::input(const T newX, const T newY) {
  x = newX;
  y = newY;
}

#endif