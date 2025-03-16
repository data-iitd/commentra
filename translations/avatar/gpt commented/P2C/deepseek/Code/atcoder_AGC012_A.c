#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MOD 1000000007

// Function to read a list of integers from input
int* readInts() {
    int n = 0;
    int* arr = malloc(100000 * sizeof(int)); // Allocate memory for the array
    char ch;
    while (scanf("%d%c", &arr[n], &ch) == 2) {
        n++;
        if (ch == '\n') break;
    }
    return arr;
}

// Function to compare two integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Main function to execute the logic
void main() {
    int n;
    scanf("%d", &n); // Reading an integer input for 'n'
    int* A = readInts(); // Reading a list of integers

    // Sorting the array using qsort
    qsort(A, n * 2, sizeof(int), compare);

    int ans = 0; // Initializing the answer variable to accumulate the result

    // Looping through the last 2*n elements of the sorted array in reverse order
    for (int i = 2 * n - 2; i >= n; i -= 2) {
        ans += A[i]; // Adding the current element to the answer
    }

    printf("%d\n", ans); // Printing the final accumulated answer

    free(A); // Freeing the allocated memory
}
