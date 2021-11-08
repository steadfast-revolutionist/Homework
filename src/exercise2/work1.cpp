#include <iostream>
#include <cmath>

using namespace std;

#define print_self ( cout << __PRETTY_FUNCTION__ << endl )

struct Point {
  friend double Length(const Point &, const Point &);
  friend istream &operator>>(istream &, Point &);

  public:
    Point() { print_self; };
    Point(double tx, double ty) : x(tx), y(ty) { print_self; }
    Point(const Point& other)
          { x = other.x; y = other.y; print_self; }
    double X() const { return x; }
    double Y() const { return y; }
    ~Point() { print_self; }

  private:
    double x;
    double y;
};

double Length(const Point& one, const Point& other) {
  double dx = pow((one.x - other.x), 2);
  double dy = pow((one.y - other.y), 2);
  return sqrt(dx + dy);
}

istream& operator>>(istream& is, Point& goal) {
  is >> goal.x >> goal.y;
  return is;
}

class Triangle {
  public:
    Triangle() { print_self; };
    Triangle(Point *p1, Point *p2, Point *p3)
            : point1(p1), point2(p2), point3(p3) { print_self; }
    bool isTrueTriangle();
    double area();
    ~Triangle()
            { print_self; delete point1; delete point2; delete point3; }

  private:
    Point* point1;
    Point* point2;
    Point* point3;
};

bool Triangle::isTrueTriangle() {
  double key1 = (point1->X() - point2->X()) / (point1->Y() - point2->Y());
  double key2 = (point2->X() - point3->X()) / (point2->Y() - point3->Y());
  return key1 != key2;
}

#define D(x, y) ( Length(*point##x, *point##y) )

double Triangle::area() {
  double key = (D(1, 2) + D(2, 3) + D(1, 3)) / 2;
  return sqrt(key * (key - D(1, 2)) * (key - D(2, 3)) * (key - D(1, 3)));
}

#undef D

static int count_triangle = 0;
static double sum_area = 0.0;

int main()
{
  char flag = '\0';
  int count = 0;
  do {
    ++count;
    Point *p1 = new Point();
    Point *p2 = new Point();
    Point *p3 = new Point();

    cin >> *p1 >> *p2 >> *p3;

    Triangle test(p1, p2, p3);

    if (test.isTrueTriangle()) {
      ++count_triangle;
      sum_area += test.area();
    }
    cout << "continue? [Y/n] ";
    cin >> flag;
  } while (flag == 'Y');
  cout << "you entered " << count << " triangles\n"
       << count_triangle << " is true, and their average area is "
       << (count_triangle == 0 ? 0 : sum_area / count_triangle) << endl;

  return 0;
}