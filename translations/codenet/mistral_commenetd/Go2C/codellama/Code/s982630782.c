
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000
#define MAX_M 100000

int main() {
    // Initialize an empty map to store the frequency of each number
    int m[MAX_N];
    memset(m, 0, sizeof(m));

    // Read the number of test cases N
    int N;
    scanf("%d", &N);
    // Read the N integers and store their frequencies in the map
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        m[num]++;
    }

    // Read the number of queries M
    int M;
    scanf("%d", &M);
    // For each query, read the number B and the index C, and update the frequency of the number at index C in the map
    for (int i = 0; i < M; i++) {
        int B, C;
        scanf("%d %d", &B, &C);
        m[C] += B;
    }

    // Create a slice of integers from the map keys
    int ints[MAX_N];
    int i = 0;
    // Populate the slice with the map keys
    for (int k = 0; k < MAX_N; k++) {
        if (m[k] > 0) {
            ints[i] = k;
            i++;
        }
    }

    // Sort the slice in descending order
    qsort(ints, i, sizeof(int), compare);

    // Initialize variables for calculating the sum
    int rest = N;
    int sum = 0;
    // Iterate through the sorted slice of integers
    for (int j = 0; j < i; j++) {
        int num = m[ints[j]];
        // If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
        if (num >= rest) {
            sum += rest * ints[j];
            break;
        }
        // Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
        sum += num * ints[j];
        rest -= num;
    }

    // Print the result
    printf("%d\n", sum);

    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

