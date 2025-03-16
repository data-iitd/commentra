#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair *)b)->key - ((Pair *)a)->key; // Sort in descending order
}

int main() {
    int N, M;
    scanf("%d", &N);

    // Initialize an array to store the frequency of each number
    int *frequency = (int *)calloc(100001, sizeof(int)); // Assuming numbers are in the range [0, 100000]

    // Read the N integers and store their frequencies
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        frequency[num]++;
    }

    // Read the number of queries M
    scanf("%d", &M);
    // For each query, read the number B and the index C, and update the frequency
    for (int i = 0; i < M; i++) {
        int B, C;
        scanf("%d %d", &B, &C);
        frequency[C] += B;
    }

    // Create an array of pairs to store the unique numbers and their frequencies
    Pair *pairs = (Pair *)malloc(100001 * sizeof(Pair));
    int count = 0;

    // Populate the pairs array with the frequency data
    for (int i = 0; i < 100001; i++) {
        if (frequency[i] > 0) {
            pairs[count].key = i;
            pairs[count].value = frequency[i];
            count++;
        }
    }

    // Sort the pairs in descending order based on the key
    qsort(pairs, count, sizeof(Pair), compare);

    // Initialize variables for calculating the sum
    int rest = N;
    int sum = 0;

    // Iterate through the sorted pairs
    for (int i = 0; i < count; i++) {
        int num = pairs[i].value;
        int value = pairs[i].key;

        // If the number's frequency is greater than or equal to the remaining number of elements
        if (num >= rest) {
            sum += rest * value;
            break;
        }
        // Otherwise, add the product of the number's frequency and its index to the sum
        sum += num * value;
        rest -= num;
    }

    // Print the result
    printf("%d\n", sum);

    // Free allocated memory
    free(frequency);
    free(pairs);

    return 0;
}

// <END-OF-CODE>
