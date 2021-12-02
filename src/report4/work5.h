#ifndef WORK_WORK5_H
#define WORK_WORK5_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define input(obj)                      \
  {                                     \
    cout << "please enter " #obj " : "; \
    cin >> obj;                         \
    getchar();                          \
  }

#define output(obj) cout << #obj " : " << obj << endl;

#define basic_ioput(io) \
  io##put(ID);          \
  io##put(name);        \
  io##put(sex);         \
  io##put(birthday);    \
  io##put(position);    \
  io##put(salary);

#define read(file, obj) file << #obj " : " << obj << '\n';

#define basic_read(file) \
  read(file, ID);        \
  read(file, name);      \
  read(file, sex);       \
  read(file, birthday);  \
  read(file, position);  \
  read(file, salary);

void choose(fstream* file) {
  char symbol;
  cout << "Do you want to keep the old information? [Y/n] ";
  symbol = getchar();
  if (symbol != 'Y') {
    file->open("info.txt", ios::out | ios::trunc);
    cout << "cleared done...\n";
  }
  file->open("info.txt", ios::out | ios::app);
}

class Date {
  friend istream &operator>>(istream &, Date &);
  friend ostream &operator<<(ostream &, const Date &);

  public:
    Date() = default;
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

  private:
    int year;
    int month;
    int day;
};

istream& operator>>(istream& is, Date& emmm) {
  is >> emmm.year >> emmm.month >> emmm.day;
  return is;
}

ostream& operator<<(ostream& os, const Date& emmm) {
  os << "year: " << emmm.year << '\n'
     << "month: " << emmm.month << '\n'
     << "day: " << emmm.day;
  return os;
}

class Employee {
  public:
    Employee() = default;
    Employee(string i, string n, string s, Date b, string p, int m) :
      ID(i), name(n), sex(s), birthday(b), position(p), salary(m) { }
    virtual Employee &set() = 0;
    virtual void info() const = 0;
    virtual bool save() const = 0;

  protected:
    string ID;
    string name;
    string sex;
    Date birthday;
    string position;
    int salary;
};

class Technician : virtual public Employee {
  public:
    Technician() : Employee(), work_time(0.0) { }
    Technician(string i, string n, string s, Date b, string p, int m, double w) : 
      Employee(i, n, s, b, p, m), work_time(w) { }
    Technician &set() override;
    void info() const override;
    bool save() const override;

  protected:
    double work_time;
};

Technician& Technician::set() {
  basic_ioput(in);
  input(work_time);
  return *this;
}

void Technician::info() const {
  basic_ioput(out);
  output(work_time);
}

bool Technician::save() const {
  try {
    fstream outfile;
    choose(&outfile);
    basic_read(outfile);
    read(outfile, work_time);
    outfile.close();
    return true;
  }
  catch (std::exception &err)
  {
    return false;
  }
}

class Manager : virtual public Employee {
  public:
    Manager() : Employee(), sale(0), department("") { }
    Manager(string i, string n, string s, Date b, string p, int m,
      int sa, string d) :
        Employee(i, n, s, b, p, m), sale(sa), department(d) { }
    Manager &set() override;
    void info() const override;
    bool save() const override;

  protected:
    int sale;
    string department;
};

Manager& Manager::set() {
  basic_ioput(in);
  input(sale);
  input(department);
  return *this;
}

void Manager::info() const {
  basic_ioput(out);
  output(sale);
  output(department);
}

bool Manager::save() const {
  try {
    fstream outfile;
    choose(&outfile);
    basic_read(outfile);
    read(outfile, sale);
    read(outfile, department);
    outfile.close();
    return true;
  }
  catch (std::exception &err)
  {
    return false;
  }
}

class SalesManager final
  : virtual public Technician, virtual public Manager {
    public:
      SalesManager() : Technician(), Manager() { }
      SalesManager(string i, string n, string s, Date b, string p, int m,
        double w, int sa, string d) : 
          Technician(i, n, s, b, p, m, w), Manager(i, n, s, b, p, m, sa, d) { }
      SalesManager &set() override;
      void info() const override;
      bool save() const override;
};

SalesManager& SalesManager::set() {
  basic_ioput(in);
  input(work_time);
  input(sale);
  input(department);
  return *this;
}

void SalesManager::info() const {
  basic_ioput(out);
  output(work_time);
  output(sale);
  output(department);
}

bool SalesManager::save() const {
  try {
    fstream outfile;
    choose(&outfile);
    basic_read(outfile);
    read(outfile, work_time);
    read(outfile, sale);
    read(outfile, department);
    outfile.close();
    return true;
  }
  catch (std::exception &err)
  {
    return false;
  }
}

bool distill() {
  try {
    ifstream infile;
    string temp;

    infile.open("info.txt");
    while(!infile.eof()) {
      getline(infile, temp);
      cout << temp << '\n';
    }
    infile.close();
    return true;
  }
  catch (std::exception &err)
  {
    return false;
  }
}

#endif