#include <iostream>

using namespace std;

template <typename T>
inline T getMax(T& num1, T& num2) {
  return (num1 > num2) ? num1 : num2;
}

template <typename C>
inline C getMax(C& num1, C& num2, C& num3) {
  C temp = (num1 > num2) ? num1 : num2;

  return (temp > num3) ? temp : num3;
}

int main()
{
  int a = 211, b = 666, c = 985;

  cout << getMax(a, b) << endl;
  cout << getMax(a, b, c) << endl;

  return 0;
}