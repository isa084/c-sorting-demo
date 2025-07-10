#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h> // For memcmp()

#include "sorting.h"

// A helper function to print an array. Useful for debugging.
void print_array(const char* prefix, int arr[], int n) {
    printf("%s: [", prefix);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// A generic test function that takes a sorting function as an argument.
// Returns 0 on success, 1 on failure.
int run_test(void (*sort_func)(int*, size_t), const char* func_name) {
    printf("--- Testing %s ---\n", func_name);

    int test_arr[] = {64, 34, 25, 12, 22, 11, 90};
    int expected_arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(test_arr) / sizeof(test_arr[0]);

    print_array("Original", test_arr, n);

    // Call the sorting function passed as an argument
    sort_func(test_arr, n);

    print_array("Sorted", test_arr, n);

    // Compare the sorted array with the expected result
    if (memcmp(test_arr, expected_arr, sizeof(test_arr)) == 0) {
        printf("Result: PASS\n\n");
        return 0; // Success
    } else {
        printf("Result: FAIL\n\n");
        return 1; // Failure
    }
}

int main() {
    int final_status = 0;

    // Run the test for each sorting algorithm
    final_status |= run_test(bubble_sort, "Bubble Sort");
    final_status |= run_test(insertion_sort, "Insertion Sort");

    if (final_status == 0) {
        printf("All tests passed!\n");
        return 0; // Exit with success code
    } else {
        printf("One or more tests failed.\n");
        return 1; // Exit with failure code
    }
}
