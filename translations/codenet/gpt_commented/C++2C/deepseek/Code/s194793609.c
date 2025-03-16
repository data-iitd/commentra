#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize an array to store the input numbers
    long long a[n];
    // Read the input numbers into the array
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // Create a copy of the input array to store absolute values
    long long abs_a[n];
    for (int i = 0; i < n; i++) {
        abs_a[i] = a[i];
    }

    // Convert all elements in abs_a to their absolute values
    for (int i = 0; i < n; i++) {
        if (abs_a[i] < 0) {
            abs_a[i] = -abs_a[i];
        }
    }

    // Initialize variables to calculate the sum of absolute values and find the minimum absolute value
    long long ans = 0;
    long long min = abs_a[0];
    // Iterate through the absolute values to calculate the total sum and find the minimum
    for (int i = 0; i < n; i++) {
        ans += abs_a[i]; // Accumulate the sum of absolute values
        if (min > abs_a[i]) {
            min = abs_a[i]; // Update the minimum absolute value found
        }
    }

    // Count the number of negative numbers in the original array
    int num_negative = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            num_negative++; // Increment count for each negative number
        }
    }

    // If the count of negative numbers is odd, adjust the total sum
    if (num_negative % 2) {
        ans -= min * 2; // Subtract twice the minimum absolute value from the total sum
    }

    // Output the final result
    printf("%lld\n", ans);
}
