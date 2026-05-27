#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <string>

const int MAX_ROWS = 20;
const int MAX_COLS = 20;

void task_matrix_19();

void read_matrix_from_file(std::string filename, double mx[][MAX_COLS], int &m, int &n);
void append_matrix_results_to_file(std::string filename, const double sums[], int m);
void print_matrix(const double mx[][MAX_COLS], int m, int n);
void calculate_row_sums(const double mx[][MAX_COLS], int m, int n, double sums[]);

#endif
