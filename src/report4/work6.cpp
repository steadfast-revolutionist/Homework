#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item {
  int first;
  int second;
};

int main()
{
  vector<item> test(10);

  for (auto& i : test) {
    cin >> i.first >> i.second;
  }

  stable_sort(test.begin(), test.end(),
              [](const item &pair1, const item &pair2)
              { return (pair1.first < pair2.first) ||
                       (pair1.first == pair2.first &&
                        pair1.second < pair2.second); });

  for (auto i : test) {
    cout << '(' << i.first << ',' << i.second << ")\n";
  }

  return 0;
}