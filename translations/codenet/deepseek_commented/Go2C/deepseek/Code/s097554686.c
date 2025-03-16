#include <stdio.h>

#define size 100001

int main() {
    int n, t; // Declare variables for number of intervals and time range
    int l, r; // Declare variables for left and right endpoints of intervals
    int mem[size] = {0}; // Declare an array to store cumulative changes

    scanf("%d", &n); // Read the number of intervals
    scanf("%d", &t); // Read the time range

    // Read each interval and update the cumulative changes in the array
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r); // Read the left and right endpoints
        mem[l]++; // Increment the value at the left endpoint
        mem[r]--; // Decrement the value at the right endpoint
    }

    // Initialize ans with the value at mem[0]
    int ans = mem[0];

    // Compute the prefix sum and find the maximum value in the array
    for (int i = 1; i < t + 1; i++) {
        mem[i] += mem[i - 1]; // Compute the prefix sum
        if (ans < mem[i]) { // Update ans if a larger value is found
            ans = mem[i];
        }
    }

    // Print the maximum value found
    printf("%d\n", ans);

