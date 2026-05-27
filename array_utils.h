#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <string>

const int MAX_SIZE = 50;

void task_array_97();
void task_sort_3();

void read_array_from_file(std::string filename, int arr[], int &n);
void write_array_to_file(std::string filename, const int arr[], int n);
void print_array(const int arr[], int n);

void remove_duplicates(int arr[], int &n);
void selection_sort(int arr[], int n);

#endif
