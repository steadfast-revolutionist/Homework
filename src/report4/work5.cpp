#include <iostream>
#include <string>

#include "test_work5.h"

using namespace std;

int main() 
{
  SalesManager me;
  me.set();
  try_save(&me);

  distill();

  return 0;
}
