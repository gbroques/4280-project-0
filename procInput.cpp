#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include "procInput.h"

std::array<int, MAX_NUM_INTS> process_args(int argc, char* argv[]) {
  std::array<int, MAX_NUM_INTS> numbers = {0};
  if (argc == 1) {
    print_usage(argv[0]);
    exit(1);
  }
  if (argc == 2) {
    if (is_positive_integer(argv[1])) {
      numbers[0] = atoi(argv[1]);
    } else {  // Is a file
      std::ifstream file(argv[1]);
      if (!file) {
        std::cerr << "Error: Cannot open file '" << argv[1] << "'.\n";
        exit(1);
      }
      if (is_empty(file)) {
        std::cerr << "Error: File is empty.\n";
        exit(1);
      }
      std::string x;
      int i = 0;
      while (file >> x) {
        if (!is_positive_integer(x)) {
          print_invalid_input_error(x);
          exit(1);
        }
        numbers[i++] = stoi(x);
        if (i == MAX_NUM_INTS) {
          print_max_ints_error();
          exit(1);
        }
      }
    }
  }
  if (argc > 2) {
    for (int i = 1; i < argc; i++) {
      if (!is_positive_integer(argv[i])) {
        print_invalid_input_error(argv[i]);
        exit(1);
      }
      if (i > MAX_NUM_INTS) {
        print_max_ints_error();
        exit(1);
      }
      numbers[i-1] = atoi(argv[i]);
    }
  }
  return numbers;
}

static void print_usage(const char* program_name) {
  std::cerr << "Usage: " << program_name << " filename\n";
  std::cerr << "    filename: A file containing a list of positive integers\n";
  std::cerr << "    Maximum length of list: 10\n";
  std::cerr << "Usage: " << program_name << " n1 [n2 ...]\n";
  std::cerr << "    n1, n2, etc.: A list of positive integers\n";
  std::cerr << "    Maximum length of list: 10\n";
}

static void print_invalid_input_error(std::string input) {
  std::cerr << "Error: Invalid input. '" << input << "' is not a positive integer.\n";
}

static void print_max_ints_error() {
  std::cerr << "Error: Maximum number of " << MAX_NUM_INTS << " integers exceeded.\n";
}

static bool is_positive_integer(const std::string &str) {
  return is_digits(str) && stoi(str) != 0;
}

static bool is_digits(const std::string &str) {
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

static bool is_empty(std::ifstream &file) {
  return file.peek() == std::ifstream::traits_type::eof();
}
