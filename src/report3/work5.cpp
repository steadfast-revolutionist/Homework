#include <cstdio>
#include <iostream>

using namespace std;

class Time {
  friend ostream &operator<<(ostream &, const Time &);
  friend istream &operator>>(istream &, Time &);

  public:
    Time() = default;                                            //默认构造函数
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {} //含参构造函数
    Time(const Time &);                                          //拷贝构造函数
    Time &operator=(const Time &);                               //拷贝赋值运算符
    Time &operator++();
    Time &operator--();
    Time &operator+(const Time &);
    Time &operator-(const Time &);
    bool operator>(const Time &);
    bool operator==(const Time &other)
    {
      return hour == other.hour && minute == other.minute && second == other.second;
    }

  private:
    int hour = 0;
    int minute = 0;
    int second = 0;
    Time &trim();
};

Time& Time::trim() {
  if (second >= 60) {
    second -= 60;
    if (++minute >= 60) {
      minute -= 60;
      ++hour;
    }
  } else if (second < 0) {
    second += 60;
    if (--minute < 0) {
      minute += 60;
      --hour;
    }
  }
  return *this;
}

Time::Time(const Time& other) {
  hour = other.hour;
  minute = other.minute;
  second = other.second;
}

Time& Time::operator=(const Time& other) {
  hour = other.hour;
  minute = other.minute;
  second = other.second;

  return *this;
}

Time& Time::operator++() {
  second++;
  trim();

  return *this;
}

Time& Time::operator--() {
  second--;
  trim();

  return *this;
}

Time& Time::operator+(const Time& other) {
  second += other.second;
  minute += other.minute;
  hour += other.hour;
  trim();

  return *this;
}

Time& Time::operator-(const Time& other) {
  second -= other.second;
  minute -= other.minute;
  hour -= other.hour;
  trim();

  return *this;
}

ostream& operator<<(ostream& os, const Time& time) {
  os << time.hour << ':' << time.minute << ':' << time.second;
  return os;
}

istream& operator>>(istream& is, Time& time) {
  is >> time.hour >> time.minute >> time.second;
  return is;
}

bool Time::operator>(const Time& other) {
  auto key1 = hour * 1000 + minute * 10 + second;
  auto key2 = other.hour * 1000 + other.minute * 10 + other.second;
  return key1 > key2;
}

int main()
{
  Time time1(15, 46, 57);
  Time time2;
  cin >> time2;
  Time time3 = time1 + time2;
  cout << time1 << '\n'
       << time2 << '\n'
       << time3 << '\n';
  cout << (time1 == time2 ? "equal" : "unequal") << '\n';

  return 0;
}