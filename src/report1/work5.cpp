#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T> void
myTest() {
  size_t length = 0;

  cout << "enter the length of the array...\n";
  cin >> length;

  vector<T> test(length);

  cout << "now we enter the items of the array one by one...\n";
  for (auto& item : test) {
    cin >> item;
  }
  
  T goal;

  cout << "what do you want to find?\n";
  if (cin >> goal) {
    size_t index = find_if(test.begin(), test.end(),
                           [goal](const T &item)
                           { return item == goal; }) -
                   test.begin();
    if (index != length) {
      cout << "we find it! the index of it is " << index << " ...\n";
    } else {
      cout << "sorry, we find nothing...\n";
    }
  } else {
    cout << "error type!\n";
  }
}

int main()
{
  cout << "Let's test type int...\n";
  myTest<int>();

  cout << "Let's test type double...\n";
  myTest<double>();

  cout << "Let's test type string...\n";
  myTest<string>();

  return 0;
}