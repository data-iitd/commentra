#include <stdio.h>
#include <stdlib.h>

#define MAXN 200000 + 10
#define INF (int)(1e8)

// Arrays to hold input values and sorted values
int maps[MAXN];
<<<<<<< HEAD
int num[MAXN];

=======
int num[MAXN;

// Comparison function for qsort
>>>>>>> 98c87cb78a (data updated)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n; // Variable to hold the number of elements
    
    // Continuously read input until EOF
    while (scanf("%d", &n) != EOF) {
        // Read n integers into the maps array and copy to num array
        for (int i = 1; i <= n; i++) {
            scanf("%d", &maps[i]);
            num[i] = maps[i];
        }

        // Sort the maps array to find the median
        qsort(maps + 1, n, sizeof(int), compare);
        
        // Calculate the index for the median element
        int m = n / 2;

        // For each element in the original array, determine and print the appropriate value
        for (int i = 1; i <= n; i++) {
            // If the current number is less than or equal to the median
            if (num[i] <= maps[m]) {
                // Print the next higher number (the one after the median)
                printf("%d\n", maps[m + 1]);
            } else {
                // Print the median value
                printf("%d\n", maps[m]);
            }
        }
    }
    return 0; // Return success
}

// <END-OF-CODE>
