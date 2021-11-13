#include <iostream>
#include <string>

using namespace std;

class vehicle {
  public:
    vehicle() = default;
    vehicle(double m, double w, int c, string f) :
            maxSpeed(m), weight(w), countWheels(c), fuel(f) { }
    virtual vehicle &set() = 0;
    virtual void info() const = 0;
    virtual void run() const = 0;
    virtual void stop() const = 0;

  protected:
    double maxSpeed;
    double weight;
    int countWheels;
    string fuel;
};

#define input(obj)      \
  cout << #obj << ": "; \
  cin >> obj;

#define output(obj) ( cout << #obj << ": " << obj << '\t' )

#define basic_io_vehicle(str) \
  str##put(maxSpeed);    \
  str##put(weight);      \
  str##put(countWheels);  \
  str##put(fuel);

class bicycle : public virtual vehicle {
  public:
    bicycle() = default;
    bicycle(double m, double w, int c, string f, double h, string ma) :
            vehicle(m, w, c, f), height(h), material(ma) { }
    bicycle &set() override;
    void info() const override;
    void run() const override { cout << "this bicycle is running now!\n"; }
    void stop() const override { cout << "this bicycle has stopped just now!\n"; }

  protected:
    double height;
    string material;
};

class motorcar : public virtual vehicle {
  public:
    motorcar() = default;
    motorcar(double m, double w, int c, string f, int n, string s) :
            vehicle(m, w, c, f), seatNum(n), sign(s) { }
    motorcar &set() override;
    void info() const override;
    void run() const override { cout << "this motorcar is running now!\n"; }
    void stop() const override { cout << "this motorcar has stopped just now!\n"; }

  protected:
    int seatNum;
    string sign;
};

class motorcycle final : public bicycle, public motorcar {
  public:
    motorcycle() = default;
    motorcycle(double m, double w, int c, string f, double h, string ma, int n, string s) :
              bicycle(m, w, c, f, h, ma), motorcar(m, w, c, f, n, s) { }
    motorcycle &set() override;
    void info() const override;
    void run() const override { cout << "this motorcycle is running now!\n"; }
    void stop() const override { cout << "this motorcycle has stopped just now!\n"; }
};

#define low_basic_vehicle_io(io, arg1, arg2) \
  basic_io_vehicle(io);                      \
  io##put(arg1);                             \
  io##put(arg2);

bicycle& bicycle::set() {
  low_basic_vehicle_io(in, height, material);
  return *this;
}

void bicycle::info() const {
  low_basic_vehicle_io(out, height, material);
  putchar('\n');
}

motorcar& motorcar::set() {
  low_basic_vehicle_io(in, seatNum, sign);
  return *this;
}

void motorcar::info() const {
  low_basic_vehicle_io(out, seatNum, sign);
  putchar('\n');
}

motorcycle& motorcycle::set() {
  low_basic_vehicle_io(in, height, material);
  input(seatNum);
  input(sign);

  return *this;
}

void motorcycle::info() const {
  low_basic_vehicle_io(out, seatNum, sign);
  output(seatNum);
  output(sign);
  putchar('\n');
}

#undef input()
#undef output()
#undef basic_io_vehicle()
#undef low_basic_vehicle_io()

#define test(object) \
  object.info();     \
  object.run();      \
  object.stop();

int main()
{
  bicycle myBicycle(50.0, 6, 2, "human", 1.2, "C60");
  test(myBicycle);

  motorcar myMotorcar;
  myMotorcar.set();
  test(myMotorcar);

  motorcycle myMotorcycle(50.0, 200, 2, "oil", 1.4, "iron", 2, "no");
  test(myMotorcycle);
  myMotorcycle.set();
  test(myMotorcycle);

  return 0;
}
