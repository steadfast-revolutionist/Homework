#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    Student() = default;
    Student(long i, string n, int a) : id(i), name(n), age(a) { }
    inline void SetValue();
    void Print() const;

  private:
    long id;
    string name;
    int age;
};

void Student::SetValue() {
  cout << "Please enter the id:\n";
  cin >> id;

  cout << "Please enter the name:\n";
  getchar();
  getline(cin, name);

  cout << "Please enter the age\n";
  cin >> age;
}

inline void
Student::Print() const {
  cout << "The student's information:\n\t";

  cout << "id: " << id << " name: "
       << name << " age: " << age << endl;
}

int main()
{
  Student stu1;
  Student stu2(2002230120, "Xiao Wang", 19);

  stu1.SetValue();

  stu1.Print();
  stu2.Print();

  return 0;
}