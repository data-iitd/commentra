#include <stdio.h>
#include <stdlib.h>

int* func(int* A, int* size) {
    int min = 0;
    int newSize = 0;
    int* newArray = (int*)malloc(*size * sizeof(int));

    for (int i = 0; i < *size; i++) {
        if (A[i] == 0) {
            continue; // Skip zero elements
        } else {
            if (min != 0) {
                newArray[newSize] = A[i] % min;
                // If the updated element is 1, print 1 and exit
                if (newArray[newSize] == 1) {
                    printf("1\n");
                    exit(0);
                }
            } else {
                min = A[i];
                newArray[newSize] = A[i];
            }
            newSize++;
        }
    }

    *size = newSize; // Update the size of the new array
    newArray = (int*)realloc(newArray, newSize * sizeof(int)); // Resize the array
    return newArray;
}

int main() {
    // Read the number of integers to be processed
    int n;
    scanf("%d", &n);

    // If there is only one integer, print it and exit
    if (n == 1) {
        int singleValue;
        scanf("%d", &singleValue);
        printf("%d\n", singleValue);
        return 0;
    }

    // Initialize an array to store the integers
    int* a = (int*)malloc(n * sizeof(int));

    // Read n integers from input and add them to the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the array in ascending order
    qsort(a, n, sizeof(int), (int (*)(const void*, const void*))compare);

    // If the largest number is 0, print 0 and exit
    if (a[n - 1] == 0) {
        printf("0\n");
        free(a);
        return 0;
    }

    // Initialize the answer variable
    int ans = 0;

    // Loop until the array is reduced to one element
    while (1) {
        if (n == 1) {
            ans = a[0];
            break;
        }
        a = func(a, &n);
    }

    // Print the final answer
    printf("%d\n", ans);
    free(a);
    return 0;
}

// Comparison function for qsort
int compare(const int* a, const int* b) {
    return (*a - *b);
}
