#include <iostream>
#include <fstream>
#include <array>
#include "procInput.h"
#include "incrDiv.h"
#include "timer.h"

int main(int argc, char* argv[]) {
  timer timer_ = timer();
  timer_.start("Timer started.");

  std::array<int, MAX_NUM_INTS> numbers;
  numbers = process_args(argc, argv);

  std::string output_filename;
  output_filename = get_output_filename(argc, argv);
  std::cout << "Outputting to file '" << output_filename << "'.\n";

  std::ofstream file(output_filename);

  if (file.is_open()) {
    int i = 0;
    while (numbers[i] != 0 && i < MAX_NUM_INTS) {
      incr_div(numbers[i++], file);
    }

    timer_.stop("Timer stopped.");

    std::cout << "Total elapsed time: " << timer_.timeVal() << " seconds.\n";

    file.close();
  } else {
    std::cerr << "Error opening file '" << output_filename << "'.\n";
    exit(1);
  }

  return 0;
}

