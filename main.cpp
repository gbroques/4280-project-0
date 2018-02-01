#include <iostream>
#include <fstream>
#include <array>
#include "procInput.h"
#include "incrDiv.h"

int main(int argc, char* argv[]) {
  std::array<int, MAX_NUM_INTS> numbers;
  numbers = process_args(argc, argv);

  std::string output_filename;
  output_filename = get_output_filename(argc, argv);

  std::ofstream file(output_filename);

  if (file.is_open()) {
    int i = 0;
    while (numbers[i] != 0 && i < MAX_NUM_INTS) {
      incr_div(numbers[i++], file);
    }
  } else {
    std::cerr << "Error opening file '" << output_filename << "'.\n";
    exit(1);
  }

  std::cout << "Outputting to " << output_filename << std::endl;

  return 0;
}

