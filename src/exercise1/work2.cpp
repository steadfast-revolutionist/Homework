#include <iostream>
#include <string>

using namespace std;

template <class T>
inline void mySwap(T& object1, T& object2) {
  T temp = object1;
  object1 = object2;
  object2 = temp;
}

int main()
{
  int testNum1 = 0, testNum2 = 0;
  string testStr1, testStr2;

  cin >> testNum1 >> testNum2;
  cin >> testStr1 >> testStr2;

  mySwap(testNum1, testNum2);
  mySwap(testStr1, testStr2);

  cout << testNum1 << ' ' << testNum2 << endl;
  cout << testStr1 << ' ' << testStr2 << endl;

  return 0;
}