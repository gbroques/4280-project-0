#include <iostream>
#include "incrDiv.h"

void incr_div(int num) {
  if (num <= 0) {
    std::cerr << "'" << num << "' must be positive integer.\n";
    exit(1);
  }
  incr_div_helper(num, 2);
}

static int incr_div_helper(int num, int divisor) {
  if (num <= 0) {
    std::cout << "numCalls = " << divisor - 2 << "\n";
    return divisor - 2;
  }
  int quotient = num / divisor;
  std::cout << quotient << " ";
  return incr_div_helper(quotient, divisor + 1);
}


