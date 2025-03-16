
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize a map to count occurrences of integers
    int m[100001] = {0};

    // Read the number of initial integers (N) and the number of operations (M)
    int N, M;
    scanf("%d %d", &N, &M);

    // Read N integers and count their occurrences in the map
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        m[a]++;
    }

    // Process M operations, where each operation adds B occurrences of integer C
    for (int i = 0; i < M; i++) {
        int B, C;
        scanf("%d %d", &B, &C);
        m[C] += B;
    }

    // Create a slice to hold the unique integers from the map
    int *ints = (int *)malloc(sizeof(int) * 100001);
    int len = 0;
    for (int i = 0; i < 100001; i++) {
        if (m[i] > 0) {
            ints[len++] = i;
        }
    }

    // Sort the integers in descending order
    qsort(ints, len, sizeof(int), cmpfunc);

    // Initialize variables to keep track of remaining integers and the total sum
    int rest = N;
    int sum = 0;

    // Calculate the maximum sum based on the sorted integers
    for (int i = len - 1; i >= 0; i--) {
        int num = m[ints[i]];
        if (num >= rest) {
            sum += rest * ints[i]; // Add the product of remaining count and the integer
            break; // Exit the loop as we have used all remaining integers
        }
        sum += num * ints[i]; // Add the product of occurrences and the integer to the sum
        rest -= num; // Decrease the remaining count by the number of occurrences
    }

    // Output the final calculated sum
    printf("%d\n", sum);

    // Free the allocated memory for the integers slice
    free(ints);

    return 0;
}

// Compare function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Translate the above C code to Java and end with comment "