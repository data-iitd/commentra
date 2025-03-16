#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
#define MOD (1000000000 + 7)

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
=======
// Constants
#define MOD 1000000007
>>>>>>> 98c87cb78a (data updated)

// Function to read an integer from input
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read an array of integers
int* readIntArray(int n) {
<<<<<<< HEAD
    int *array = (int *)malloc(n * sizeof(int));
=======
    int* array = (int*)malloc(n * sizeof(int));
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        array[i] = readInt();
    }
    return array;
}

<<<<<<< HEAD
// Main function where the program execution starts
int main() {
    int n = readInt();
    int x = readInt();
    int *A = readIntArray(n);
=======
// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Main function
int main() {
    int n = readInt();
    int x = readInt();
    int* A = readIntArray(n);
>>>>>>> 98c87cb78a (data updated)

    // Sort the array A
    qsort(A, n, sizeof(int), compare);

    // Initialize answer variable
    int ans = 0;

    // Count how many elements can be taken from A without exceeding x
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }

    // Adjust answer if all elements are taken and there is still remaining x
    if (ans == n && x > 0) {
        ans--;
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free allocated memory
    free(A);
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
