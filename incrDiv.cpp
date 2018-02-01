#include <iostream>
#include "incrDiv.h"

static int incr_div_helper(int num, int divisor, std::ostream &file);

void incr_div(int num, std::ostream &file) {
  if (num <= 0) {
    std::cerr << "'" << num << "' must be positive integer.\n";
    exit(1);
  }
  incr_div_helper(num, 2, file);
}

static int incr_div_helper(int num, int divisor, std::ostream &file) {
  if (num <= 0) {
    file << "numCalls = " << divisor - 2 << std::endl;
    return divisor - 2;
  }
  int quotient = num / divisor;
  file << quotient << " ";
  return incr_div_helper(quotient, divisor + 1, file);
}


