#include <iostream>
#include <cmath>

using namespace std;

class Complex {
  public:
    Complex() = default;
    Complex(double r, double i) : real(r), imag(i) { }
    inline void SetComplex(double, double);
    inline void SetComplex();
    inline double GetReal() const { return real; }
    inline double GetImag() const { return imag; }
    void Print() const;

  private:
    double real = 0;
    double imag = 0;
};

inline void
Complex::SetComplex(double r, double i) {
  real = r;
  imag = i;
}

inline void
Complex::SetComplex() {
  cout << "Please input the real part ";
  cin >> real;

  cout << "Please input the image part ";
  cin >> imag;
}

void Complex::Print() const {
  if (imag == 0) {
    cout << '(' << real << ")\n";
  } else if (imag < 0) {
    cout << '(' << real << imag << "i)\n";
  } else {
    cout << '(' << real << '+' << imag << "i)\n";
  }
}

int main()
{
  Complex num1(2, 3);
  Complex num2;

  num1.GetImag();
  num1.GetReal();
  num2.SetComplex(3, 4);
  num1.SetComplex();

  num1.Print();
  num2.Print();

  return 0;
}