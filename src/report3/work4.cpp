#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

#define print_self ( cout << __PRETTY_FUNCTION__ << endl )

class Complex {
  public:
    Complex() { print_self; };    //默认构造函数
    Complex(double i) : imag(i) { print_self; } //含参构造函数
    Complex(double r, double i) : real(r), imag(i) { print_self; } //含参构造函数
    Complex(const Complex &temp) 
      { real = temp.real; imag = temp.imag; print_self; } //拷贝构造函数
    Complex& operator=(const Complex& temp)
      { real = temp.real; imag = temp.imag; print_self; return *this; } //拷贝赋值运算符
      //重载四则运算运算符
      Complex operator+(const Complex &);
      Complex operator-(const Complex &);
      Complex operator*(const Complex &);
      Complex operator/(const Complex &);
      ~Complex() { print_self; }    //析构函数

    private:
      double real = 0;
      double imag = 0;

    friend ostream &operator<<(ostream &, const Complex &);       //重载输出流运算符
    friend istream &operator>>(istream &, Complex &); //重载输入流运算符
};

Complex Complex::operator+(const Complex& other) {
  return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) {
  return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) {
  auto treal = real * other.real - imag * other.imag;
  auto timag = real * other.imag + imag * other.real;

  return Complex(treal, timag);
}

Complex Complex::operator/(const Complex& other) {
  auto key = pow(other.real, 2) + pow(other.imag, 2);
  auto treal = (real * other.real + imag * other.imag) / key;
  auto timag = (imag * other.real - real * other.imag) / key;

  return Complex(treal, timag);
}

ostream& operator<<(ostream& os, const Complex& test) {
  os << '(' << test.real << ',' << test.imag << "i)";

  return os;
}

istream& operator>>(istream& is, Complex& test) {
  is >> test.real >> test.imag;

  return is;
}

int main()
{
  Complex num1(3, 4);
  cout << num1 << endl;
  Complex num2;
  cin >> num2;
  cout << num2 << endl;
  cout << num1 + num2 << endl;
  cout << num1 - num2 << endl;
  cout << num1 * num2 << endl;
  cout << num1 / num2 << endl;

  return 0;
}
