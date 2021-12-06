#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

#define READ(obj)         \
  cout << "\t" #obj ": "; \
  cin >> obj;

class CSolid {
  public:
    CSolid() = default;
    CSolid(double d) : density(d) { }
    virtual CSolid &set(double) = 0;
    virtual double volume() const = 0;
    double mass() const { return density * volume(); }

  protected:
    double density;
};

class Square : public CSolid {
  public:
    Square() = default;
    Square(double d, double l) : CSolid(d), len(l) { }
    Square& set(double d) override {
      density = d;
      cout << "this Square's info: \n";
      READ(len);
      return *this;
    }
    double volume() const override { return pow(len, 3); }

  private:
    double len;
};

class Sphere : public CSolid {
  public:
    Sphere() = default;
    Sphere(double d, double r) : CSolid(d), radius(r) { }
    Sphere& set(double d) override {
      density = d;
      cout << "this Sphere's info: \n";
      READ(radius);
      return *this;
    }
    double volume() const override { return 4 * M_PI * pow(radius, 3) / 3; }

  private:
    double radius;
};

class Cylinder : public CSolid {
  public:
    Cylinder() = default;
    Cylinder(double d, double h, double r) :
            CSolid(d), height(h), below_radius(r) { }
    Cylinder& set(double d) override {
      density = d;
      cout << "this Cylinder's info: \n";
      READ(height);
      READ(below_radius);
      return *this;
    }
    double volume() const override { return M_PI * pow(below_radius, 2) * height; }

  private:
    double height;
    double below_radius;
};

#undef read(obj)

void ninteraction(double* sum, double density) {
  cout << "menus: \n\t"
       << "1. Square\n\t2. Sphere\n\t3. Cylinder\n"
       << "please enter the key of the shape: ";
  bool flag = false;
  char key = getchar();
start:
  key = getchar();

  switch (key) {
    case '1': {
        Square temp1;
        *sum += temp1.set(density).mass();
        goto end;
      }
    case '2': {
        Sphere temp2;
        *sum += temp2.set(density).mass();
        goto end;
      }
    case '3': {
        Cylinder temp3;
        *sum += temp3.set(density).mass();
        goto end;
      }
    default: {
      cout << "key failed!\ninput new key again: ";
      goto start;
      break;
    }
  }
end: { }
}

int main()
{
  double density = 0.0, sum_mass = 0.0;
  bool flag = true;
  int count = 0;

  cout << "these stones' density: ";
  cin >> density;

  do {
    cout << "stone" << ++count << ": ";
    ninteraction(&sum_mass, density);
    cout << "any else? [Y/n]  ";
    getchar();
    flag = (getchar() == 'Y');
  } while (flag);

  cout << "Okay, the sum mass of these stones is " << sum_mass << endl;

  return 0;
}