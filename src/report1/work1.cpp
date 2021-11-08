#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct student {
  char fname[20];
  char lname[20];
  char grade;
  int age;
};

void set(student& self) {
  cout << "What is your first name? ";
  fgets(self.fname, 19, stdin);
  self.fname[strlen(self.fname) - 1] = '\0';

  cout << "What is your last name? ";
  fgets(self.lname, 19, stdin);
  self.lname[strlen(self.lname) - 1] = '\0';

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