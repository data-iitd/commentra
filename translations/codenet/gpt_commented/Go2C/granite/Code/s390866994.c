
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print output to the console
void out(char *fmt,...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
}

// Function to read an integer from input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a string from input
char* getString() {
    static char str[1000];
    scanf("%s", str);
    return str;
}

// Basic utility functions for mathematical operations
int max(int a, int b) {
    return a > b? a : b;
}

int min(int a, int b) {
    return a < b? a : b;
}

int asub(int a, int b) {
    return a > b? a - b : b - a;
}

int abs(int a) {
    return a >= 0? a : -a;
}

int main() {
    // Read the number of elements (N), maximum count (C), and time limit (K)
    int N = getInt();
    int C = getInt();
    int K = getInt();
    int t[N]; // Create an array to hold the time values

    // Read N time values from input
    for (int i = 0; i < N; i++) {
        t[i] = getInt(); // Store each time value in the array
    }

    // Sort the time values in ascending order
    qsort(t, N, sizeof(int), cmpfunc);

    // Initialize variables for counting groups and tracking the end time
    int ans = 1; // Start with one group
    int cnt = 1; // Count of elements in the current group
    int end = t[0] + K; // Calculate the end time for the first group

    // Iterate through the sorted time values
    for (int i = 1; i < N; i++) {
        // Check if we can add the current time to the current group
        if (cnt < C && t[i] <= end) {
            cnt++; // Increment the count of the current group
        } else {
            // Start a new group since the current time exceeds the end time
            cnt = 1; // Reset the count for the new group
            end = t[i] + K; // Update the end time for the new group
            ans++; // Increment the group count
        }
    }
    out("%d", ans); // Output the total number of groups formed
    return 0;
}

