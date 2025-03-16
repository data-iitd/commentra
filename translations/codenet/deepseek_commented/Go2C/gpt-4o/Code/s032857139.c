#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

<<<<<<< HEAD
// Function prototypes
int readInt();
int* readIntSlice(int n);
void sortArray(int* arr, int n);
int max(int a, int b);
int min(int a, int b);
void freeIntSlice(int* arr);
void printResult(int ans);

// Main function to read input, sort the array, and calculate the answer.
int main() {
    int n = readInt();
    int x = readInt();
    int* A = readIntSlice(n);

    sortArray(A, n);
=======
// Function to read an integer from standard input
int ReadInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read an array of integers
int* ReadIntSlice(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = ReadInt();
    }
    return arr;
}

// Function to compare two integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Main function to read input, sort the array, and calculate the answer
int main() {
    int n = ReadInt();
    int x = ReadInt();
    int* A = ReadIntSlice(n);

    // Sort the array
    qsort(A, n, sizeof(int), compare);
>>>>>>> 98c87cb78a (data updated)

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }
    if (ans == n && x > 0) {
        ans--;
    }
<<<<<<< HEAD
    printResult(ans);

    freeIntSlice(A);
    return 0;
}

// Function to read an integer from standard input
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read an array of integers from standard input
int* readIntSlice(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = readInt();
    }
    return arr;
}

// Function to sort an array of integers
void sortArray(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to free the allocated integer array
void freeIntSlice(int* arr) {
    free(arr);
}

// Function to print the result
void printResult(int ans) {
    printf("%d\n", ans);
}

// Utility functions for max and min
int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

=======
    printf("%d\n", ans);

    // Free allocated memory
    free(A);
    return 0;
}

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
