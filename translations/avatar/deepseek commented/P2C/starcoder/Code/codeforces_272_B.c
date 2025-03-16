#include <stdio.h>
#include <stdlib.h>

int main() {
    // Take input from the user
    scanf("%*[^\n]");
    // Process the input and call nPairsWithCommonFX with the processed input
    printf("%d\n", nPairsWithCommonFX(processInput()));
    return 0;
}

int nPairsWithCommonFX(int *sequence) {
    // Initialize a dictionary to store values grouped by their computed property
    int *storage = (int *)malloc(sizeof(int) * 1000000);
    // List to store the computed property values
    int *FXs = (int *)malloc(sizeof(int) * 1000000);
    int i = 0;
    for (int value = *sequence; value!= 0; value = *++sequence) {
        // Compute the property for the current value
        int y = f(value);
        // If the property is not already in storage, add it with the current value
        if (storage[y] == 0) {
            storage[y] = value;
            FXs[i++] = y;
        } else {
            // Otherwise, append the current value to the list of values for this property
            storage[y] = value;
        }
    }
    // Calculate the number of pairs with common factor greater than 1
    int result = 0;
    for (int j = 0; j < i; j++) {
        result += storage[FXs[j]] * storage[FXs[j]];
    }
    for (int j = 0; j < i; j++) {
        result -= storage[FXs[j]];
    }
    return result / 2;
}

int f(int n) {
    // Initialize y to 1, which will be the result for the property of n
    int y = 1;
    while (n!= 1) {
        if (n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

int *processInput() {
    // Allocate memory for the input
    int *sequence = (int *)malloc(sizeof(int) * 1000000);
    // Read the input
    int i = 0;
    int value;
    while (scanf("%d", &value) == 1) {
        sequence[i++] = value;
    }
    // Terminate the input with 0
    sequence[i] = 0;
    return sequence;
}

