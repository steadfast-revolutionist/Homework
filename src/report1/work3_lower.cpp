#include <iostream>
#include <string>

using namespace std;

struct student {
  string fname;
  string lname;
  char grade;
  int age;
};

void read(student* ptr, const int& len) {
  for (size_t temp = 0; temp != len; ++temp) {
    cout << "Student #" << temp + 1 << ":\nWhat is your first name? ";
    cin >> ptr[temp].fname;

    cout << "What is yourlast name? ";
    cin >> ptr[temp].lname;

    cout << "What letter grade do you deserve? ";
    cin >> ptr[temp].grade;

    cout << "What is your age? ";
    cin >> ptr[temp].age;
  }
}

void print(const student* ptr, const int& len) {
  cout << "All students:\n";
  for (size_t count = 0; count < len; ++count) {
    cout << "Name: " << ptr[count].fname << ", "
         << ptr[count].lname << " Grade: "
         << ptr[count].grade << " Age: "
         << ptr[count].age << '\n';
  }
}

int main()
{
  int length = 0;

  cout << "How many students do you wish to catalog? ";
  cin >> length;

  student *ptr = new student[length];

  read(ptr, length);
  print(ptr, length);

  delete[] ptr;

  return 0;
}
