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
    scanf("%d %d", &N, &M);
    
<<<<<<< HEAD
    // Create an array to store the counts of integers
    int *keys = malloc(N * sizeof(int));
    int *counts = malloc(N * sizeof(int));
    int uniqueCount = 0;
=======
    // Create a map to store the counts of integers
    int *keys = malloc(N * sizeof(int));
    int *values = malloc(N * sizeof(int));
    int size = 0;
>>>>>>> 98c87cb78a (data updated)

    // Read N integers and store their counts
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        
<<<<<<< HEAD
        // Check if the number is already in the keys array
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (keys[j] == num) {
                counts[j]++;
=======
        // Check if the number is already in the map
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (keys[j] == num) {
                values[j]++;
>>>>>>> 98c87cb78a (data updated)
                found = 1;
                break;
            }
        }
        if (!found) {
<<<<<<< HEAD
            keys[uniqueCount] = num;
            counts[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Perform M operations to update the counts
=======
            keys[size] = num;
            values[size] = 1;
            size++;
        }
    }

    // Perform M operations to update the map with new integers and their counts
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < M; i++) {
        int B, C;
        scanf("%d %d", &B, &C);
        
<<<<<<< HEAD
        // Check if C is already in the keys array
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (keys[j] == C) {
                counts[j] += B;
=======
        // Check if C is already in the map
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (keys[j] == C) {
                values[j] += B;
>>>>>>> 98c87cb78a (data updated)
                found = 1;
                break;
            }
        }
        if (!found) {
<<<<<<< HEAD
            keys[uniqueCount] = C;
            counts[uniqueCount] = B;
            uniqueCount++;
=======
            keys[size] = C;
            values[size] = B;
            size++;
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Create an array of pairs to sort
<<<<<<< HEAD
    Pair *pairs = malloc(uniqueCount * sizeof(Pair));
    for (int i = 0; i < uniqueCount; i++) {
        pairs[i].key = keys[i];
        pairs[i].value = counts[i];
    }

    // Sort the pairs in descending order based on the key
    qsort(pairs, uniqueCount, sizeof(Pair), compare);
=======
    Pair *pairs = malloc(size * sizeof(Pair));
    for (int i = 0; i < size; i++) {
        pairs[i].key = keys[i];
        pairs[i].value = values[i];
    }

    // Sort the pairs in descending order based on the key
    qsort(pairs, size, sizeof(Pair), compare);
>>>>>>> 98c87cb78a (data updated)

    // Initialize variables to keep track of the remaining elements and the sum
    int rest = N;
    long long sum = 0;

<<<<<<< HEAD
    // Iterate through the sorted pairs and calculate the sum based on the conditions
    for (int i = 0; i < uniqueCount; i++) {
=======
    // Iterate through the sorted integers and calculate the sum based on the conditions
    for (int i = 0; i < size; i++) {
>>>>>>> 98c87cb78a (data updated)
        int num = pairs[i].value;
        if (num >= rest) {
            sum += (long long)rest * pairs[i].key;
            break;
        }
        sum += (long long)num * pairs[i].key;
        rest -= num;
    }

    // Print the calculated sum
    printf("%lld\n", sum);

    // Free allocated memory
    free(keys);
<<<<<<< HEAD
    free(counts);
=======
    free(values);
>>>>>>> 98c87cb78a (data updated)
    free(pairs);

    return 0;
}

// <END-OF-CODE>
