#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to calculate combinations C(n, r)
int combi(int n, int r) {
    int c = 1;
    // Calculate the combination using the formula C(n, r) = n! / (r! * (n - r)!)
    for (int i = 1; i <= r; i++) {
        c = c * (n - i + 1) / i;
    }
    return c; // Return the calculated combination
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize a array to hold the input integers
    int a[n];
    // Read n integers from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Create a prefix sum array to store cumulative sums
    int s[n+1];
    s[0] = 0; // Initialize the first element to 0
    for (int i = 0; i < n; i++) {
        s[i+1] = s[i] + a[i]; // Calculate cumulative sum
    }

    // Sort the prefix sum array
    qsort(s, n+1, sizeof(int), compare);

    // Initialize variables to count pairs of equal sums
    int ans = 0;
    int count = 0;
    // Iterate through the sorted prefix sums to find duplicates
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i+1]) {
            count++; // Increment count if current and next sums are equal
        } else if (count > 0) {
            // If we found duplicates, calculate combinations and reset count
            ans += combi(count+1, 2);
            count = 0; // Reset count for the next unique sum
        }
    }
    // Handle the case where the last sums were duplicates
    if (count > 0) {
        ans += combi(count+1, 2);
    }

    // Output the total number of pairs of equal sums
    printf("%d\n", ans);

    return 0;
}
