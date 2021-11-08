#include <iostream>
#include <cmath>

using namespace std;

class CFraction {
  public:
    CFraction() = default;
    CFraction(int n, int d) : nume(n), deno(d) { }
    inline void Set();
    inline void Set(int, int);
    inline void Get() const;
    CFraction& Simplicity();

  private:
    int nume = 0;
    int deno = 0;
};

inline void
CFraction::Set() {
  cout << "nume: ";
  cin >> nume;
  cout << "deno: ";
  cin >> deno;
}

inline void
CFraction::Set(int n, int d) {
  nume = n;
  deno = d;
}

inline void
CFraction::Get() const {
  if (deno ==0) {
    cout << "inf\n";
  } else if (nume == 0) {
    cout << "0\n";
  } else {
    cout << '(' << nume << " / " << deno << ")\n";
  }
}

CFraction& CFraction::Simplicity() {
  int n = abs(nume);
  int d = abs(deno);
  
  while (n != d && deno != 0) {
    if (n > d) {
      n -= d;
    } else {
      d -= n;
    }
  }

  nume /= n;
  deno /= n;

  if (deno < 0) {
    deno *= -1;
    nume *= -1;
  }

  return *this;
}

int main()
{
  CFraction num1(4, -6);
  CFraction num2;

  num1.Simplicity().Get();
  num1.Set();
  num2.Set(-9, 0);

  num1.Simplicity().Get();
  num2.Simplicity().Get();

  return 0;
}