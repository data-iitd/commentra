#include <stdio.h>
#include <stdlib.h>

// Function to compute the property f(n)
int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

// Function to calculate the number of pairs with common factor greater than 1
int nPairsWithCommonFX(int* sequence, int size) {
    // Initialize a dictionary to store values grouped by their computed property
    int* storage = (int*)calloc(size, sizeof(int));
    int* FXs = (int*)malloc(size * sizeof(int));
    int count = 0;

    for (int i = 0; i < size; i++) {
        // Compute the property for the current value
        int y = f(sequence[i]);
        // If the property is not already in storage, add it with the current value
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (FXs[j] == y) {
                storage[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            FXs[count] = y;
            storage[count] = 1;
            count++;
        }
    }

    // Calculate the number of pairs with common factor greater than 1
    int pairs = 0;
    for (int i = 0; i < count; i++) {
        pairs += storage[i] * (storage[i] - 1) / 2;
    }

    // Free allocated memory
    free(storage);
    free(FXs);

    return pairs;
}

int main() {
    // Take input from the user
    int n;
    scanf("%d", &n);
    int* sequence = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    // Process the input and call nPairsWithCommonFX with the processed input
    int result = nPairsWithCommonFX(sequence, n);

    // Print the result
    printf("%d\n", result);

    // Free allocated memory
    free(sequence);

    return 0;
}
