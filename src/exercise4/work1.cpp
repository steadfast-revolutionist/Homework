#include <iostream>
#include <string>

using namespace std;

class Person {
  public:
    Person() = default;
    Person(string n, string s, int a) : name(n), sex(s), age(a) { }
    virtual void print() const = 0;
    virtual void doSomething() const {
      cout << "info: " << endl;
      print();
    }

  protected:
    string name;
    string sex;
    int age;
};

class Teacher : public Person {
  public:
  Teacher() : Person(), workID(""), academy("") { }
  Teacher(string n, string s, int a, string w, string c) :
          Person(n, s, a), workID(w), academy(c) { }
  void print() const override;
  void doSomething() const override {
      cout << "info: " << endl;
      print();
  }

private:
  string workID;
  string academy;
};

void Teacher::print() const {
  cout << "name: " << name << '\n'
       << "sex: " << sex << '\n'
       << "age: " << age << '\n'
       << "workID: " << workID << '\n'
       << "academy: " << academy << endl;
}

class Student : public Person {
  public:
  Student() : Person(), studyID(""), class_and_grade("") { }
  Student(string n, string s, int a, string i, string c) :
          Person(n, s, a), studyID(i), class_and_grade(c) { }
  void print() const override;
  void doSomething() const override {
      cout << "info: " << endl;
      print();
    }

private:
  string studyID;
  string class_and_grade;
};

void Student::print() const {
  cout << "name: " << name << '\n'
       << "sex: " << sex << '\n'
       << "age: " << age << '\n'
       << "studyID: " << studyID << '\n'
       << "class and grade: " << class_and_grade << endl;
}

int main()
{
  Person *ptr;
  Teacher math("laoshi", "wowan", 50, "66666", "Mathematicas");
  Student me("Wu Mingshi", "boy", 19, "2002230120", "IOT-01");

  ptr = &math;
  ptr->doSomething();

  ptr = &me;
  ptr->doSomething();

  return 0;
}