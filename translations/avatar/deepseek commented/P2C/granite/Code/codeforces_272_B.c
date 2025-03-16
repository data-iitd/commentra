
#include <stdio.h>

int main() {
    // Take input from the user
    int n;
    scanf("%d", &n);
    // Process the input and call nPairsWithCommonFX with the processed input
    return nPairsWithCommonFX(n);
}

int nPairsWithCommonFX(int n) {
    // Initialize a dictionary to store values grouped by their computed property
    int storage[n + 1];
    // List to store the computed property values
    int FXs[n + 1];
    for (int i = 0; i <= n; i++) {
        // Compute the property for the current value
        int y = f(i);
        // If the property is not already in storage, add it with the current value
        if (storage[y] == 0) {
            storage[y] = i;
            FXs[y] = 1;
        } else {
            // Otherwise, increment the count of values for this property
            FXs[y]++;
        }
    }
    // Calculate the number of pairs with common factor greater than 1
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += FXs[i] * FXs[i];
    }
    return (result - n) / 2;
}

int f(int n) {
    // Initialize y to 1, which will be the result for the property of n
    int y = 1;
    while (n!= 1) {
        if (n % 2) {
            y++;
        }
        n /= 2;
    }
    return y;
}

// 