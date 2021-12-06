#include <iostream>
#include <string>

using namespace std;
#define cout(p) cout << #p << ": " << p << endl;

class Person {
  public:
    Person() = default;
    string get_name() const { return name; }
    int get_age() const { return age; }
    char get_sex() const { return sex; }
    void set_value() { cin >> name >> age >> sex; }
    void display() {
      cout(name);
      cout(age);
      cout(sex);
    }

  protected:
    string name;
    int age;
    char sex;
};

class Student : public Person {
  public:
    Student() = default;
    int get_num() const { return num; }
    string get_address() const { return address; }
    void set_others() { cin >> num >> address; }
    void display() {
      cout(name);
      cout(age);
      cout(sex);
      cout(num);
      cout(address);
    }

  private:
    int num;
    string address;
};

#undef cout(p)

int main()
{
  Student me;
  me.set_value();
  me.display();
  me.set_others();
  me.display();

  return 0;
}
