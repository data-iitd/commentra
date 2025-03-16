

#include <stdio.h> // Include the standard input/output library

int main() {
    int n, N = 100005; // Define a constant N for array size
    long long cnt[21] = {0}; // Initialize an array to count occurrences of each value shifted by 10
    long long res = 0; // Initialize result variable

    // Read the number of elements and count the occurrences of each value shifted by 10
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x + 10]++;
    }

    // Calculate the number of pairs that sum up to 20
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }

    // Special case for pairs where both elements are the same (i.e., i = 10)
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    // Output the result
    printf("%lld\n", res);

    return 0; // Return 0 to indicate successful execution
}

