#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Triangle {
  public:
    // structure function
    Triangle() = default;
    Triangle(T a, T b, T c) : side1(a), side2(b), side3(c) { }
    // normal member function
    inline void set(T a, T b, T c)
      { side1 = a; side2 = b; side3 = c; }
    bool isTriangle();
    double area();

  private:
    T side1;
    T side2;
    T side3;
};

template <typename T>
inline bool Triangle<T>::isTriangle() {
  return (side1 + side2 > side3) && (abs(side1 - side2) < side3);
}

template <typename T>
inline double Triangle<T>::area() {
  // Use Helen's formula
  double key = (side1 + side2 + side3) / 2.0;

  return sqrt(key * (key - side1) * (key - side2) * (key - side3));
}

template <typename T>
void myTest(Triangle<T> &testObject) {
  if (testObject.isTriangle()) {
    cout << "It's a true triangle!\nand its area is "
         << testObject.area() << "...\n";
  } else {
    cout << "It's not a true triangle...\n"
         << "of course we cannot get its area\n";
  }
}

int main()
{
  Triangle<int> test1(1, 2, 3);
  Triangle<double> test2;

  test2.set(2.0, 3.0, 4.0);

  myTest<int>(test1);
  myTest<double>(test2);

  return 0;
}
