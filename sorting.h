#ifndef SORTING_H
#define SORTING_H

#include <stddef.h> // Required for size_t

/**
 * @brief Sorts an array of integers using the Bubble Sort algorithm.
 * @param arr Pointer to the integer array.
 * @param n The number of elements in the array.
 */
void bubble_sort(int *arr, size_t n);

/**
 * @brief Sorts an array of integers using the Insertion Sort algorithm.
 * @param arr Pointer to the integer array.
 * @param n The number of elements in the array.
 */
void insertion_sort(int *arr, size_t n);

#endif // SORTING_H
