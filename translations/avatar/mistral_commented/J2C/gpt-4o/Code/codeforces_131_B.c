#include <stdio.h>

int main() {
    // Initialize variables
    int n;
    // Define the maximum size of the array to avoid array out of bounds exception
    long cnt[21] = {0}; // Initialize count array to zero

    // Read the number of test cases from the console
    scanf("%d", &n);

    // Read the numbers one by one and update the count array accordingly
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num); // Read the next number
        cnt[num + 10]++; // Increment the count of the number
    }

    // Calculate the result using the given formula
    long res = 0;
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i]; // Calculate the sum of products of pairs of numbers with absolute difference i
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2; // Calculate the sum of squares of numbers equal to 10 and add half of it

    // Print the result to the console
    printf("%ld\n", res);

    return 0;
}

// <END-OF-CODE>
