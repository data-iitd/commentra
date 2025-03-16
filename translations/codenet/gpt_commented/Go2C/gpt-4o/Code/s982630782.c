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

    // Initialize a map to count occurrences of integers
    int *keys = malloc(N * sizeof(int));
    int *values = malloc(N * sizeof(int));
    int uniqueCount = 0;

    // Read N integers and count their occurrences
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
<<<<<<< HEAD
=======
        
        // Check if the number is already in the map
>>>>>>> 98c87cb78a (data updated)
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (keys[j] == num) {
                values[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            keys[uniqueCount] = num;
            values[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Process M operations
    for (int i = 0; i < M; i++) {
        int B, C;
        scanf("%d %d", &B, &C);
<<<<<<< HEAD
=======
        
        // Check if the number is already in the map
>>>>>>> 98c87cb78a (data updated)
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (keys[j] == C) {
                values[j] += B;
                found = 1;
                break;
            }
        }
        if (!found) {
            keys[uniqueCount] = C;
            values[uniqueCount] = B;
            uniqueCount++;
        }
    }

    // Create an array of pairs to hold the unique integers and their counts
    Pair *pairs = malloc(uniqueCount * sizeof(Pair));
    for (int i = 0; i < uniqueCount; i++) {
        pairs[i].key = keys[i];
        pairs[i].value = values[i];
    }

    // Sort the pairs in descending order based on the key
    qsort(pairs, uniqueCount, sizeof(Pair), compare);

    // Initialize variables to keep track of remaining integers and the total sum
    int rest = N;
    long long sum = 0;

    // Calculate the maximum sum based on the sorted integers
    for (int i = 0; i < uniqueCount; i++) {
        int num = pairs[i].value;
        if (num >= rest) {
            sum += (long long)rest * pairs[i].key; // Add the product of remaining count and the integer
            break; // Exit the loop as we have used all remaining integers
        }
        sum += (long long)num * pairs[i].key; // Add the product of occurrences and the integer to the sum
        rest -= num; // Decrease the remaining count by the number of occurrences
    }

    // Output the final calculated sum
    printf("%lld\n", sum);

    // Free allocated memory
    free(keys);
    free(values);
    free(pairs);

    return 0;
}

// <END-OF-CODE>
