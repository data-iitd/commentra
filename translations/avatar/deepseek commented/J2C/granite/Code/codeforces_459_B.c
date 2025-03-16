
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the size of the array
    int N;
    scanf("%d", &N);

    // Read the elements of the array
    int A[N];
    for (int n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }

    // Sort the array
    qsort(A, N, sizeof(int));

    // Find the minimum and maximum values in the array
    int min = A[0];
    int max = A[N - 1];

    // Count the occurrences of the minimum and maximum values
    long mins = 0;
    long maxs = 0;
    for (int value = 0; value < N; value++) {
        if (A[value] == min) {
            mins++;
        }
        if (A[value] == max) {
            maxs++;
        }
    }

    // Special case: if min == max
    if (min == max) {
        printf("%ld %ld\n", (long)(max - min), mins * (mins - 1) / 2);
    } else {
        // General case: if min!= max
        printf("%ld %ld\n", (long)(max - min), mins * maxs);
    }

    return 0;
}

// Debugging method to print debug statements
void debug(char* format,...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

// End of code
