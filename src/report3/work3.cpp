#include <iostream>
#include <cstring>

using namespace std;

#define print_self ( cout << __PRETTY_FUNCTION__ << endl )

class WordProcess {
  public:
    // 默认构造函数
    WordProcess() { arr = nullptr; size = 0; print_self; }
    // 含参构造函数
    WordProcess(const char *);
    // 拷贝构造运算符
    WordProcess &operator=(const WordProcess &);
    // 拷贝构造函数
    WordProcess(const WordProcess &);
    // 输入
    WordProcess &set(const char *);
    // 输出
    void display() const;
    // 析构函数
    ~WordProcess() { delete arr; print_self; }

  private:
    char *arr;
    int size;
};

WordProcess::WordProcess(const char* temp) {
  size = strlen(temp);
  arr = new char[size + 1];
  strcpy(arr, temp);
  print_self;
}

WordProcess&
WordProcess::operator=(const WordProcess& temp) {
  if (this != &temp) {
    delete[] arr;
    size = temp.size;
    arr = new char[size + 1];
    strcpy(arr, temp.arr);
  }
  print_self;

  return *this;
}

WordProcess::WordProcess(const WordProcess& temp) {
  size = temp.size;
  arr = new char[size + 1];
  strcpy(arr, temp.arr);
  print_self;
}

WordProcess&
WordProcess::set(const char* temp) {
  delete[] arr;
  size = strlen(temp);
  arr = new char[size + 1];
  strcpy(arr, temp);

  return *this;
}

void WordProcess::display() const {
  cout << "\tthe word: " << arr << "\n\tsize: " << size << endl;
}

int main()
{
  WordProcess word1("the first test");
  word1.display();
  word1.set("the second test");
  word1.display();

  WordProcess word2(word1);
  word2.display();
  word2 = word1.set("this is the last test");
  word1.display();
  word2.display();

  return 0;
}