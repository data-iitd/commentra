#include <stdio.h> // Include standard input-output header

int main() {
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Read the number of elements
    long cnt[21] = {0}; // Initialize an array to count occurrences of each value shifted by 10

    // Count the occurrences of each value shifted by 10
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value); // Read each value
        cnt[value + 10]++; // Increment the count for the shifted value
    }

    long res = 0; // Initialize result variable

    // Calculate the number of pairs that sum up to 20
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }

    // Special case for pairs where both elements are the same (i.e., i = 10)
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    // Output the result
    printf("%ld\n", res); // Print the result

    return 0; // Return success
}

// <END-OF-CODE>
