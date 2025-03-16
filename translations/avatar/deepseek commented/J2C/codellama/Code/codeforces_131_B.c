
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // Initialize variable to store the number of elements
    scanf("%d", &n); // Read the number of elements
    int N = 100005; // Define a constant N for array size
    long cnt[21]; // Initialize an array to count occurrences of each value shifted by 10

    // Count the occurrences of each value shifted by 10
    for (int i = 0; i < n; i++) {
        int x; // Initialize variable to store the input
        scanf("%d", &x); // Read the input
        cnt[x + 10]++; // Increment the count of the value shifted by 10
    }

    long res = 0; // Initialize result variable

    // Calculate the number of pairs that sum up to 20
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }

    // Special case for pairs where both elements are the same (i.e., i = 10)
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    // Output the result
    printf("%ld\n", res);

    return 0;
}

