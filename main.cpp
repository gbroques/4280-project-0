#include <iostream>
#include <array>
#include "procInput.h"
#include "incrDiv.h"

int main(int argc, char* argv[]) {
  std::array<int, MAX_NUM_INTS> numbers;
  numbers = process_args(argc, argv);
  
  int i = 0;
  while (numbers[i] != 0 && i < MAX_NUM_INTS) {
    incr_div(numbers[i++]);
  }

  return 0;
}

