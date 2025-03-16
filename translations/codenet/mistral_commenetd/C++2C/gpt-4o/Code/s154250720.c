#include <stdio.h>
#include <stdlib.h>

#define MAXN 200000 + 10 // maximum size of the input array 'n'
#define INF (int)(1e8) // a large constant value used as INF

// Initialize arrays 'maps' and 'num' with given size 'MAXN'
int maps[MAXN];
int num[MAXN];

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Main function starts here
int main() {
    // Initialize variable 'n' to read input from standard input
    int n;
    // Start an infinite loop to read multiple test cases
    while (scanf("%d", &n) != EOF) {
        // Initialize 'maps' and 'num' arrays with input values
        for (int i = 1; i <= n; i++) {
            scanf("%d", &maps[i]);
            num[i] = maps[i]; // copy input values to 'num' array
        }
        // Sort 'maps' array in ascending order
        qsort(maps + 1, n, sizeof(int), compare);
        // Calculate the middle index 'm' of sorted 'maps' array
        int m = n / 2;
        // Process each element in 'num' array based on the middle index 'm'
        for (int i = 1; i <= n; i++) {
            // If current element 'num[i]' is smaller than or equal to middle element 'maps[m]'
            if (num[i] <= maps[m]) {
                // Print the next element in sorted 'maps' array
                printf("%d\n", maps[m + 1]);
            }
            // Otherwise print the current middle element 'maps[m]'
            else {
                printf("%d\n", maps[m]);
            }
        }
    }
    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
