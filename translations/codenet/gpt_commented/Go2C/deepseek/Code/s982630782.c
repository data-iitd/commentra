#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Main function to execute the program logic
int main() {
    // Initialize a map to count occurrences of integers
    int N, M;
    scanf("%d %d", &N, &M);

    // Array to store the counts of each integer
    int *counts = (int *)calloc(100001, sizeof(int));
    int num;

    // Read N integers and count their occurrences
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        counts[num]++;
    }

    // Process M operations
    int B, C;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &B, &C);
        counts[C] += B;
    }

    // Create an array to hold the unique integers
    int *uniqueInts = (int *)malloc(N * sizeof(int));
    int uniqueCount = 0;

    // Collect unique integers
    for (int i = 0; i < 100001; i++) {
        if (counts[i] > 0) {
            uniqueInts[uniqueCount++] = i;
        }
    }

    // Sort the unique integers in descending order
    qsort(uniqueInts, uniqueCount, sizeof(int), (int (*)(const void *, const void *))compareDesc);

    // Initialize variables to keep track of remaining integers and the total sum
    int rest = N;
    long long sum = 0;

    // Calculate the maximum sum based on the sorted integers
    for (int i = 0; i < uniqueCount; i++) {
        int num = counts[uniqueInts[i]];
        // If the number of occurrences is greater than or equal to the remaining count
        if (num >= rest) {
            sum += (long long)rest * uniqueInts[i]; // Add the product of remaining count and the integer
            break; // Exit the loop as we have used all remaining integers
        }
        sum += (long long)num * uniqueInts[i]; // Add the product of occurrences and the integer to the sum
        rest -= num; // Decrease the remaining count by the number of occurrences
    }

    // Output the final calculated sum
    printf("%lld\n", sum);

    // Free allocated memory
    free(counts);
    free(uniqueInts);

    return 0;
}

// Comparator function for qsort to sort in descending order
int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
