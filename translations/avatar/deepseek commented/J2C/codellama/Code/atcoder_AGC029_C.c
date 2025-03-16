
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_INPUT 1000000

int n; // Number of elements in the array
int a[MAX_INPUT]; // The array itself
int s[MAX_INPUT]; // TreeMap to keep track of counts of elements

// Reads input values for n and the array a
void set() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    memset(s, 0, sizeof(s));
}

// Solves the problem by finding the maximum k such that the array can be partitioned into k non-empty subarrays
void solve() {
    set();
    int ng = 0; // Lower bound for binary search
    int ok = n; // Upper bound for binary search
    while (ok - ng > 1) {
        int k = (ng + ok) / 2; // Midpoint of the current search range
        if (isPossible(k)) {
            ok = k; // Adjust the upper bound if k is possible
        } else {
            ng = k; // Adjust the lower bound if k is not possible
        }
    }
    printf("%d\n", ok); // Print the result of the binary search
}

// Checks if it is possible to partition the array into k subarrays
bool isPossible(int k) {
    memset(s, 0, sizeof(s)); // Clear the TreeMap for each new k
    int current = 0; // Current index in the array
    for (int i = 0; i < n; i++) {
        if (a[i] <= current) { // Check if the current element can be part of the previous subarray
            if (k == 1) return false; // If k is 1, it's not possible to partition
            while (!s[i] && i >= 0) { // Remove elements from the TreeMap that are greater than or equal to the current element
                s[i]--;
                i--;
            }
            int p = a[i] - 1; // Start checking from the previous element
            while (true) {
                if (p < 0) return false; // If p goes below 0, it's not possible to partition
                int sp = s[p] + 1; // Get or default the count of p and add 1
                s[p] = sp; // Put the updated count back into the TreeMap
                if (sp == k) { // If the count of p is equal to k
                    s[p] = 0; // Remove p from the TreeMap
                    p--; // Move to the previous element
                } else {
                    break; // Break the loop if the count is not equal to k
                }
            }
        }
        current = a[i]; // Update the current element
    }
    return true; // Return true if it's possible to partition the array into k subarrays
}

int main() {
    solve();
    return 0;
}

