#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class MyString {
  friend ostream &operator<<(ostream &, const MyString &);
  friend istream &operator>>(istream &, MyString &);

public:
  MyString() { str_ptr = nullptr; }
  MyString(const char *);
  MyString(const MyString &);
  MyString &operator=(const MyString &);
  MyString operator+(const MyString &);
  bool operator<(const MyString &other) {
    return strcmp(str_ptr, other.str_ptr) < 0;
  }
  ~MyString() { delete[] str_ptr; }

private:
  char *str_ptr;
};

MyString::MyString(const char* strin) {
  int len = strlen(strin) + 1;
  str_ptr = new char[len];
  strcpy(str_ptr, strin);
}

MyString::MyString(const MyString& other) {
  int len = strlen(other.str_ptr) + 1;
  str_ptr = new char[len];
  strcpy(str_ptr, other.str_ptr);
}

MyString& MyString::operator=(const MyString& other) {
  if (&other != this) {
    delete[] str_ptr;
    int len = strlen(other.str_ptr) + 1;
    str_ptr = new char[len];
    strcpy(str_ptr, other.str_ptr);
  }
  return *this;
}

MyString MyString::operator+(const MyString& other) {
  if (other.str_ptr != nullptr) {
    int len = strlen(str_ptr) + strlen(other.str_ptr) + 1;
    char *sum = new char[len];

    strcpy(sum, str_ptr);
    strcat(sum, other.str_ptr);
    return MyString(sum);
  } else {
    return MyString(str_ptr);
  }
}

ostream& operator<<(ostream& os, const MyString& str) {
  os << str.str_ptr;
  return os;
}

istream& operator>>(istream& is, MyString& str) {
  char buffer[100];
  fgets(buffer, 100 - 1, stdin);
  str = MyString(buffer);
  return is;
}

int main()
{
  MyString str1;
  MyString str2("hello");
  cout << str2 << endl;

  MyString str3("cplusplus");
  cin >> str1;
  cout << str1;
  cout << str2 + MyString(" ") + (str1 < str3 ? str1 : str3) << endl;

  return 0;
}
