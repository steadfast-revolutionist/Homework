#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct student {
  string fname;
  string lname;
  char grade;
  int age;
};

void read(shared_ptr<student>& sptr, const int& len) {
  for (size_t count = 0; count < len; ++count) {
    cout << "Student #" << count + 1 << ":\nWhat is your first name? ";
    getchar();
    getline(cin, (sptr.get() + count)->fname);

    cout << "What is your last name? ";
    getline(cin, (sptr.get() + count)->lname);

    cout << "What letter grade do you deserve? ";
    cin >> (sptr.get() + count)->grade;

    cout << "What is your age? ";
    cin >> (sptr.get() + count)->age;
  }
}

void print(shared_ptr<student>& sptr, const int& len) {
  cout << "All students:\n";
  for (size_t count = 0; count < len; ++count) {
    cout << "Name: " << (sptr.get() + count)->fname << ", "
         << (sptr.get() + count)->lname << " Grade: "
         << static_cast<char>((sptr.get() + count)->grade + 1) << " Age: "
         << (sptr.get() + count)->age << '\n';
  }
}

int main()
{
  size_t length = 0;

  cout << "How many students do you wish to catalog? ";
  cin >> length;

  shared_ptr<student> sptr(new student[length],
                           [](student *temp)
                           { delete[] temp; });

  read(sptr, length);
  print(sptr, length);

  sptr.reset();

  return 0;
}
