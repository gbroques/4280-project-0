#include <iostream>
#include <fstream>
#include <array>
#include "procInput.h"
#include "incrDiv.h"
#include "timer.h"

int main(int argc, char* argv[]) {
  timer timer_ = timer();
  timer_.start();

  std::array<int, MAX_NUM_INTS> numbers;
  numbers = process_args(argc, argv);

  std::string output_filename;
  output_filename = get_output_filename(argc, argv);
  std::cout << "Outputting to " << output_filename << std::endl;

  std::ofstream file(output_filename);

  if (file.is_open()) {
    int i = 0;
    while (numbers[i] != 0 && i < MAX_NUM_INTS) {
      incr_div(numbers[i++], file);
    }

    timer_.stop();

    file << "Total elapsed time: " << timer_.timeVal() << std::endl;

    file.close();
  } else {
    std::cerr << "Error opening file '" << output_filename << "'.\n";
    exit(1);
  }

  return 0;
}

