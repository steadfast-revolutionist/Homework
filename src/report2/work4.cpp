#include <iostream>
#include <cmath>

using namespace std;

class Ball {
  public:
    Ball() = default;
    Ball(int r) : radius(r) { }
    inline Ball &setRadius(double r);
    inline Ball &setRadius();
    inline double area();
    inline double volume();
    void information();

  private:
    double radius = 5;
};

inline Ball&
Ball::setRadius(double r) {
  radius = r;

  return *this;
}

inline Ball&
Ball::setRadius() {
  cout << "input the new radius ";
  cin >> radius;

  return *this;
}

inline double
Ball::area() {
  return 4 * M_PI * pow(radius, 2);
}

inline double
Ball::volume() {
  return 4 * M_PI * pow(radius, 3) / 3;
}

inline void
Ball::information() {
  cout << "the information of the ball\n\t";

  cout << "radius: " << radius << "\n\t"
       << "area: " << area() << "\n\t"
       << "volume: " << volume() << "\n";
}

int main()
{
  Ball ball1(3);
  Ball ball2;

  ball2.information();
  ball1.information();

  ball1.setRadius(7);
  ball2.setRadius();

  ball1.information();
  ball2.information();

  return 0;
}