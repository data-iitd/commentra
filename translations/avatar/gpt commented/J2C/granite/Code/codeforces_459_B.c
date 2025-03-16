
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the standard input stream
    int N;
    scanf("%d", &N);

    // Create an array to hold the input integers
    int *A = (int *)malloc(N * sizeof(int));

    // Read N integers from input and store them in the array A
    for (int n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }

    // Sort the array A to easily find the minimum and maximum values
    qsort(A, N, sizeof(int), cmpfunc);

    // Identify the minimum and maximum values in the sorted array
    int min = A[0];
    int max = A[N - 1];

    // Initialize counters for occurrences of min and max values
    long mins = 0;
    long maxs = 0;

    // Count how many times the minimum and maximum values occur in the array
    for (int n = 0; n < N; n++) {
        if (A[n] == min) {
            mins++;
        }
        if (A[n] == max) {
            maxs++;
        }
    }

    // If all elements are the same (min equals max)
    if (min == max) {
        // Calculate the difference (which is 0) and the number of ways to choose 2 from mins
        printf("%d %ld\n", max - min, mins * (mins - 1) / 2);
    } else {
        // Calculate the difference and the product of occurrences of min and max
        printf("%d %ld\n", max - min, mins * maxs);
    }

    // Free the memory allocated for the array A
    free(A);

    return 0;
}

// Debugging function to print objects in a readable format
void debug(void *p, char *format) {
    printf(format, p);
}

// Comparison function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// End of code
