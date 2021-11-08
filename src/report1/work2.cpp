#include <iostream>
#include <string>

using namespace std;

struct student {
  string fname;
  string lname;
  char grade;
  int age;
};

void set(student &self) {
  cout << "What is your first name? ";
  getline(cin, self.fname);

  cout << "What is your last name? ";
  getline(cin, self.lname);

  cout << "What letter grade do you deserve? ";
  cin >> self.grade;

  cout << "What is your age? ";
  cin >> self.age;
}

void print(student& self) {
  cout << "Name: " << self.lname << ", " << self.fname << '\n'
       << "Grade: " << static_cast<char>(self.grade + 1) << '\n'
       << "Age: " << self.age << '\n';
}

int main()
{
  student self;

  set(self);
  print(self);

  return 0;
}