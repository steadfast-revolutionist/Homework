#include <iostream>
#include <cstring>

using namespace std;

#define print_self (cout << __PRETTY_FUNCTION__ << endl)

class Student {
  public:
    Student() = delete;
    // 含参构造函数
    Student(const char *, const char *, int, double);
    // 拷贝复制运算符
    Student &operator=(const Student &);
    // 拷贝构造函数
    Student(const Student &);
    // set系列函数
    Student &set_no(const char *tno) { strcpy(no, tno);
      return *this;
    }
    Student &set_name(const char *tname) { strcpy(name, tname); return *this;}
    Student &set_age(int tage) { age = tage; return *this;}
    Student &set_score(double tscore) { score = tscore; return *this;}
    // 展示引用计数
    int use_count() const { return *count_use_ptr; }
    // 析构函数
    ~Student() {
      cout << "\treferrance count: " << use_count() << endl;
      if (--*count_use_ptr == 0) { delete count_use_ptr; }
      print_self;
    }

  private:
    char no[10];
    char name[10];
    int age;
    double score;
    int *count_use_ptr;

    friend void display(const Student &);
};

Student::Student(const char *tno, const char *tname, int tage, double tscore) {
  count_use_ptr = new int(1);
  strcpy(no, tno);
  strcpy(name, tname);
  age = tage;
  score = tscore;
  print_self;
}

Student& Student::operator=(const Student& temp) {
  count_use_ptr = temp.count_use_ptr;
  ++(*count_use_ptr);
  cout << use_count() << endl;
  strcpy(no, temp.no);
  strcpy(name, temp.name);
  age = temp.age;
  score = temp.score;

  return *this;
}

Student::Student(const Student& temp) {
  count_use_ptr = temp.count_use_ptr;
  ++(*count_use_ptr);
  cout << use_count() << endl;
  strcpy(no, temp.no);
  strcpy(name, temp.name);
  age = temp.age;
  score = temp.score;
  print_self;
}

void display(const Student& test) {
  cout << "display:\n\tno: " << test.no
       << "\n\tname: " << test.name
       << "\n\tage: " << test.age << "\tscore: " << test.score
       << "\n\treferrance count: " << test.use_count() << endl;
}

int main()
{
  Student me("emmm", "WangYuyan", 19, 90);
  display(me);
  Student you = me;
  you.set_name("WuMingshi");
  you.set_score(80);
  display(you);
  Student he(you);
  he.set_age(20);
  he.set_score(60);
  display(he);

  return 0;
}