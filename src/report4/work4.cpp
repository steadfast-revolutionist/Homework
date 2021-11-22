#include <iostream>
#include <string>

using namespace std;

class BaseMonster {
  public:
    BaseMonster() = default;
    BaseMonster(string n, int p, int l)
                : name(n), nPower(p), nLifeValue(l) { }
    virtual void Info() const = 0;
    virtual void Attack(BaseMonster *) = 0;
    virtual void Hurted(int) = 0;
    virtual void FightBack(BaseMonster *) = 0;

  protected:
    string name;
    int nPower;
    int nLifeValue;
};

#define Define(object)                              \
  class object final : public BaseMonster           \
  {                                                 \
  public:                                           \
    object() = default;                             \
    object(string n, int p, int l)                  \
        : BaseMonster(n, p, l) {}                   \
    void Info() const override;                     \
    void Attack(BaseMonster *) override;            \
    void Hurted(int) override;                      \
    void FightBack(BaseMonster *) override;         \
  };                                                \
                                                    \
  void object::Info() const                         \
  {                                                 \
    cout << "\tname: " << name                      \
         << "\n\tpower: " << nPower                 \
         << "\n\tlife: " << nLifeValue << endl;     \
  }                                                 \
  void object::Attack(BaseMonster *basePtr)         \
  {                                                 \
    cout << name << " attacked " << nPower << endl; \
    basePtr->Hurted(nPower);                        \
    basePtr->FightBack(this);                       \
  }                                                 \
  void object::Hurted(int power)                    \
  {                                                 \
    cout << name << " is hurted " << power << endl; \
    nLifeValue -= power;                            \
  }                                                 \
  void object::FightBack(BaseMonster *basePtr)      \
  {                                                 \
    basePtr->Hurted(nPower / 2);                    \
  }

Define(CDragon);
Define(CWolf);
Define(CGhost);
Define(CThunderBird);

int main()
{
  CDragon dragon("china dragon", 100, 1000);
  CWolf wolf("east wolf", 80, 500);
  CGhost ghost("alion ghost", 100, 300);

  dragon.Attack(&wolf);
  dragon.Attack(&ghost);
}