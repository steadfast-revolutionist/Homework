#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    Student() = default;
    Student(string n, string i, char g, int a) :
            name(n), id(i), gender(g), age(a) { }
    virtual Student& set() = 0;
    virtual void info() const = 0;

  protected:
    string name;
    string id;
    char gender;
    int age;
};

class Undergraduate final : public Student {
  public:
    Undergraduate() = default;
    Undergraduate(string n, string i, char g, int a, string d) :
                  Student(n, i, g, a), department(d) { }
    Undergraduate &set() override;
    void info() const override;

  private:
    string department;
};

class Graduate final : public Student {
  public:
    Graduate() = default;
    Graduate(string n, string i, char g, int a, string s, string r) :
            Student(n, i, g, a), supervisor(s), research(r) { }
    Graduate &set() override;
    void info() const override;

  private:
    string supervisor;
    string research;
};

#define input(obj)      \
  cout << #obj << ": "; \
  cin >> obj;

#define output(obj) ( cout << #obj << ": " << obj << '\n' )

#define student(str) \
  str##put(name);    \
  str##put(id);      \
  str##put(gender);  \
  str##put(age);

Undergraduate& Undergraduate::set() {
  student(in);
  input(department);
  return *this;
}

Graduate& Graduate::set() {
  student(in);
  input(supervisor);
  input(research);
  return *this;
}

void Undergraduate::info() const {
  student(out);
  output(department);
}

void Graduate::info() const {
  student(out);
  output(supervisor);
  output(research);
}

#undef input()
#undef output()
#undef student()

int main()
{
  Undergraduate now;
  Graduate future;

  now.set();
  future.set();

  now.info();
  future.info();

  return 0;
}