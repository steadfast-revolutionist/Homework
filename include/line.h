#ifndef LINE_H
#define LINE_H

#include <iostream>

template <typename T>
class Line {
  public:
    Line() = default;
    Line(T tempA, T tempB, T tempC) : a(tempA), b(tempB), c(tempC) { }
    inline Line<T> input(const T &a, const T &b, const T &c)
                  { return Line<T>(a, b, c); }
    inline void input() {
      std::cout << "Please input the line\n";
      std::cin >> this->a >> this->b >> this->c;
    }
    inline void input(const T, const T, const T);
    inline void output();
    T a;
    T b;
    T c;
};

template <typename T> inline void 
Line<T>::input(const T newA, const T newB, const T newC) {
  this->a = newA;
  this->b = newB;
  this->c = newC;
}

template <typename T> inline void
Line<T>::output() {
  std::cout << a << 'x' << ((b < 0) ? ("-" + b) : ("+" + b))
            << (c < 0 ? ("-" + c) : ("+" + c)) << '\n';
}

#endif