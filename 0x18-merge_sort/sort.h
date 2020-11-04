#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_caller(int *sub_array, int *array, int left, int right);
void merge(int *sub_array, int *array, int left, int mid, int right);

#endif
