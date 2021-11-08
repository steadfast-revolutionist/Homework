#include <iostream>
#include <cmath>
#include "../../include/point.h"
#include "../../include/line.h"

using namespace std;

template <typename T> double
distance(const Point<T>& point, const Line<T>& line) {
  double key1 = point.x * line.a + point.y * line.b + line.c;
  double key2 = sqrt(pow(line.a, 2) + pow(line.b, 2));

  return key1 / key2;
}

int main()
{
  Point<double> point;
  Line<double> line;

  point.input();
  line.input();

  if (!distance(point, line)) {
    cout << "the point is on the line!\n";
  } else {
    cout << "The point is not on the line\n"
         << "and the distance between them is "
         << distance(point, line) << '\n';
  }

  return 0;
}