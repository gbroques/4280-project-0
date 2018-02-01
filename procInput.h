#ifndef PROC_INPUT_H
#define PROC_INPUT_H

#include <array>

/**
 * Process Input
 */

#define MAX_NUM_INTS 10

std::array<int, MAX_NUM_INTS> process_args(int argc, char* argv[]);

std::string get_output_filename(int argc, char* argv[]);

#endif
