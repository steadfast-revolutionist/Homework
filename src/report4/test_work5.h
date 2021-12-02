#ifndef WORK5_TEST_WORK5_H
#define WORK5_TEST_WORK5_H

#include <iostream>

#include "work5.h"

void try_save(const Employee* obj) {
  int false_count = 0;
  while (false_count < 3) {
    if (obj->save()) {
      cout << "save successfully!\n";
      break;
    } else {
      false_count++;
    }
  }
  if (false_count == 3) {
    cout << "failed to save!\nlocked...\n";
  }
}

#endif