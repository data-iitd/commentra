#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y++;
        }
        n /= 2;
    }
    return y;
}

int nPairsWithCommonFX(int *sequence, int size) {
    int storage[MAX_SIZE] = {0}; // To store counts of each computed property
    int FXs[MAX_SIZE] = {0}; // To store unique property values
    int FX_count = 0; // Count of unique properties

    for (int i = 0; i < size; i++) {
        int value = sequence[i];
        int y = f(value);
        
        // If the property is not already in storage, add it
        if (storage[y] == 0) {
            FXs[FX_count++] = y;
        }
        storage[y]++;
    }

    // Calculate the number of pairs with common factor greater than 1
    int total_pairs = 0;
    for (int i = 0; i < FX_count; i++) {
        int count = storage[FXs[i]];
        total_pairs += count * count; // Count of pairs for this property
    }
    
    // Subtract the number of single elements to avoid counting them as pairs
    total_pairs = (total_pairs - FX_count) / 2;

    return total_pairs;
}

int main() {
    int sequence[MAX_SIZE];
    int size = 0;

    // Take input from the user
    printf("Enter numbers (end with -1): ");
    while (1) {
        int value;
        scanf("%d", &value);
        if (value == -1) break; // End input on -1
        sequence[size++] = value;
    }

    // Process the input and call nPairsWithCommonFX with the processed input
    int result = nPairsWithCommonFX(sequence, size);
    
    // Print the result
    printf("%d\n", result);
    
    return 0;
}

// <END-OF-CODE>
