#include <iostream>
#include <cstring>

using namespace std;

#define print_self ( cout << __PRETTY_FUNCTION__ << endl )

class WordProcess {
  public:
    // 禁止默认构造函数 
    WordProcess() = delete;
    // 含参构造函数
    WordProcess(const char *);
    // 拷贝赋值运算符
    WordProcess &operator=(const WordProcess &);
    // 拷贝构造函数
    WordProcess(const WordProcess &);
    // 输入输出
    WordProcess &set(const char *);
    void display() const { cout << arr << endl; }
    // 析构函数
    ~WordProcess() { print_self; }

  private:
    char arr[100];
};

WordProcess::WordProcess(const char* temp) {
  strncpy(arr, temp, 100 - 1);
  print_self;
}

WordProcess&
WordProcess::operator=(const WordProcess& temp) {
  strncpy(arr, temp.arr, 100 - 1);
  print_self;

  return *this;
}

WordProcess::WordProcess(const WordProcess& temp) {
  strncpy(arr, temp.arr, 100 - 1);
  print_self;
}

WordProcess&
WordProcess::set(const char* temp) {
  strncpy(arr, temp, 100 - 1);

  return *this;
}

int main()
{
  WordProcess one("just try");
  one.display();
  one.set("another try");
  one.display();

  WordProcess another(one);
  another.display();
  another = one.set("the last try");
  one.display();
  another.display();

  return 0;
}