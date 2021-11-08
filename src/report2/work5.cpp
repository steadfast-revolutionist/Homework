#include <iostream>
#include <memory>

using namespace std;

class Worker {
  public:
    Worker() = default;
    Worker(long i, string n, int a) : 
    id(i), name(n), age(a) { }
    inline void output();
    inline int set();

  private:
    long id;
    string name;
    int age;
};

inline void
Worker::output() {
  cout << "the worker:\n\t"
       << "id: " << id << "\n\t"
       << "name: " << name << "\n\t"
       << "age: " << age << '\n';
}

inline int
Worker::set() {
  cout << "input the id: ";
  cin >> id;

  cout << "input the name: ";
  getchar();
  getline(cin, name);

  cout << "input the age: ";
  cin >> age;

  return age;
}

int read(shared_ptr<Worker>& sptr, int len) {
  int ans = 0;

  for (size_t index = 0; index != len; ++index) {
    ans += (sptr.get() + index)->set();
  }

  return ans;
}

int main()
{
  int sum = 0;

  int length = 0;
  cout << "how many workers are? ";
  cin >> length;

  shared_ptr<Worker> sptr(new Worker[length],
                         [](Worker *temp)
                          { delete[] temp; });
  sum = read(sptr, length);
  cout << static_cast<double>(sum / length) << '\n';

  sptr.reset();

  return 0;
}
