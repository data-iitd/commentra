#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Function prototypes
<<<<<<< HEAD
bool isSorted(int64_t *arr, size_t size);
void sort(int64_t *arr, size_t size);
int64_t readInt();
void write(const char *s);
void flush();
=======
bool is_sorted(int64_t *arr, size_t size);
void sort_int64s(int64_t *arr, size_t size);
int64_t read_int();
void write(const char *s);
>>>>>>> 98c87cb78a (data updated)
int64_t max(int64_t a, int64_t b);
int64_t min(int64_t a, int64_t b);
int64_t sum(int64_t *arr, size_t size);
void reverse(int64_t *arr, size_t size);

// Main function
int main() {
<<<<<<< HEAD
    int64_t A = readInt();
    int64_t B = readInt();
    int64_t C = readInt();
=======
    int64_t A = read_int();
    int64_t B = read_int();
    int64_t C = read_int();
>>>>>>> 98c87cb78a (data updated)
    
    if (C >= A && C <= B) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}

// Function to read an integer from standard input
<<<<<<< HEAD
int64_t readInt() {
=======
int64_t read_int() {
>>>>>>> 98c87cb78a (data updated)
    int64_t value;
    scanf("%lld", &value);
    return value;
}

// Function to write a string to standard output
void write(const char *s) {
    printf("%s", s);
}

<<<<<<< HEAD
// Function to flush the output buffer
void flush() {
    fflush(stdout);
}

=======
>>>>>>> 98c87cb78a (data updated)
// Function to find the maximum of two integers
int64_t max(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

// Function to find the minimum of two integers
int64_t min(int64_t a, int64_t b) {
    return (a < b) ? a : b;
}

// Function to calculate the sum of an array of integers
int64_t sum(int64_t *arr, size_t size) {
    int64_t total = 0;
    for (size_t i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

<<<<<<< HEAD
// Function to reverse an array of integers
void reverse(int64_t *arr, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        int64_t temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Function to check if an array is sorted
bool isSorted(int64_t *arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
=======
// Function to check if an array of integers is sorted
bool is_sorted(int64_t *arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
>>>>>>> 98c87cb78a (data updated)
            return false;
        }
    }
    return true;
}

<<<<<<< HEAD
// Function to sort an array (simple bubble sort for demonstration)
void sort(int64_t *arr, size_t size) {
=======
// Function to sort an array of integers (simple bubble sort for demonstration)
void sort_int64s(int64_t *arr, size_t size) {
>>>>>>> 98c87cb78a (data updated)
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int64_t temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

<<<<<<< HEAD
=======
// Function to reverse an array of integers
void reverse(int64_t *arr, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        int64_t temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
