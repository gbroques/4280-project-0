#ifndef PROC_INPUT_H
#define PROC_INPUT_H

#include <array>

/**
 * Process Input
 */

#define MAX_NUM_INTS 10

std::array<int, MAX_NUM_INTS> process_args(int argc, char* argv[]);

static void print_usage(const char* program_name);

static void print_invalid_input_error(std::string input);

static void print_max_ints_error();

static bool is_positive_integer(const std::string &str);

static bool is_digits(const std::string &str);

static bool is_empty(std::ifstream &file);

#endif
