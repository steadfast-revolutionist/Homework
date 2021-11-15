#include <iostream>
#include <string>

using namespace std;

class Monster {
  public:
    Monster() = default;
    

  private:
    string name;
    unsigned ATK;
    unsigned DEF;
    unsigned Blood;
    double strike_rate;
    double violent_damage;
};