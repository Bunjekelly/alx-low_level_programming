#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stddef.h>
#include <stdio.h>

/**
 * file - header
 * desc: contains all prototypes
 */

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);

#endif
