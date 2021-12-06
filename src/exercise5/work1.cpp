#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student {
  public:
    Student() = default;
    Student(string i, string n, double g) : id(i), name(n), grade(g) {}

    Student &operator=(const Student &other)
    {
      id = other.id;
      name = other.name;
      grade = other.grade;
      return *this;
    }

    Student &read_from(fstream& ptr) {
      ptr >> id;
      ptr >> name;
      ptr >> grade;
      return *this;
    }

    void save_to(fstream &ptr) const {
      ptr << id << '\n';
      ptr << name << '\n';
      ptr << grade << '\n';
    }

    double get_grade() const { return grade; }

  private:
    string id;
    string name;
    double grade;
};

template <typename T>
void info_sort(vector<T>& test) {
  for (auto i = test.begin(); i < test.end() - 1; ++i)
    for (auto j = i + 1; j < test.end(); ++j) 
      if (i->get_grade() < j->get_grade()) {
        Student temp = *i;
        *i = *j;
        *j = temp;
      }
}

int main()
{
  fstream infile, outfile;
  infile.open("info.txt", ios::in);
  outfile.open("goal.txt", ios::out);

  int count = 0;
  infile >> count;
  outfile << count << '\n';
  vector<Student> table(count);

  for(Student& item : table) {
    item.read_from(infile);
  }

  info_sort<Student>(table);

  for(Student& item : table) {
    item.save_to(outfile);
  }

  infile.close();
  outfile.close();

  return 0;
}
