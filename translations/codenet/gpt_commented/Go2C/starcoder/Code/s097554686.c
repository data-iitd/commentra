

#include <stdio.h>

// Define a constant for the maximum size of the memory array
#define size 100001

int main() {
    // Declare variables for the number of intervals (n), the maximum time (t),
    // and the left (l) and right (r) bounds of each interval
    int n, t;
    int l, r;
    // Create an array to store the count of overlapping intervals at each time point
    int mem[size];

    // Read the number of intervals and the maximum time from input
    scanf("%d", &n);
    scanf("%d", &t);

    // Process each interval
    for (int i = 0; i < n; i++) {
        // Read the left and right bounds of the interval
        scanf("%d", &l);
        scanf("%d", &r);
        // Increment the count at the start of the interval
        mem[l] += 1;
        // Decrement the count just after the end of the interval
        mem[r] -= 1;
    }

    // Initialize the answer with the count at time 0
    int ans = mem[0];

    // Calculate the number of overlapping intervals at each time point
    for (int i = 1; i < t + 1; i++) {
        // Update the current count based on the previous count
        mem[i] += mem[i - 1];
        // Update the answer if the current count is greater than the previous maximum
        if (ans < mem[i]) {
            ans = mem[i];
        }
    }

    // Print the maximum number of overlapping intervals
    printf("%d\n", ans);

    return 0;
}

