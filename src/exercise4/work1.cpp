#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

class Person {
  public:
    Person() = default;
    Person(string n, string s, int a) : name(n), sex(s), age(a) { }
    

  private:
    string name;
    string sex;
    int age;
};