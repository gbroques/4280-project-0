#include <iostream>
#include <array>
#include "procInput.h"

int main(int argc, char* argv[]) {
  std::array<int, MAX_NUM_INTS> numbers;
  numbers = process_args(argc, argv);

  for (int i = 0; i < MAX_NUM_INTS; i++) {
    std::cout << numbers.at(i) << std::endl;
  } 
  return 0;
}

