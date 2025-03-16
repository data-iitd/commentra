#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int readInt();
int* readIntArray(int n);
void sortArray(int* arr, int n);

int main() {
    int n = readInt();
    int x = readInt();
    int* A = readIntArray(n);

    // Sort the array A
    sortArray(A, n);

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
    return 0;
}

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read an array of integers from standard input
int* readIntArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to sort an array using quicksort
void sortArray(int* arr, int n) {
    qsort(arr, n, sizeof(int), (int (*)(const void*, const void*))compare);
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

