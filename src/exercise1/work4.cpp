#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

template <class T>
int myFind(T* ptr, int length, T goal) {
  int index = 0;

  while (index != length) {
    if (ptr[index] == goal) {
      return index;
    }
    ++index;
  }

  return -1;
}

template <class T>
int myCount(T* ptr, int length, T goal) {
  int index = 0, count = 0;

  while (index != length) {
    if (ptr[index] == goal) {
      ++count;
    }
    ++index;
  }

  return count;
}

template <typename T>
void myTest(T* ptr, int length, T goal) {
  auto key = myFind(ptr, length, goal);
  cout << "for goal " << goal << ":\n";
  if (key == -1) {
    cout << "not find...\n";
  } else {
    cout << "find in index " << key << "\nand it has appeared "
         << myCount(ptr, length, goal) << " times...\n";
  }
}

int main()
{
  int test1[] = {2, 0, 0, 2, 2, 3, 0, 1, 2, 0};
  char test2[] = {'w', 'a', 'n', 'g', 'y', 'u', 'y', 'a', 'n'};

  myTest<int>(test1, sizeof(test1) - 1, 2);
  myTest<char>(test2, sizeof(test2) - 1, 'x');

  return 0;
}
