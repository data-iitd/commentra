#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Macro definitions for convenience
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x), (x) + (sizeof(x) / sizeof(*x))

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    // Read the number of elements
    int n;
    scanf("%d", &n);
    
    // Initialize an array to store the elements and read them from input
    int a[n];
    REP(i, n) scanf("%d", &a[i]);
    
    // Sort the array to facilitate duplicate checking
    qsort(a, n, sizeof(int), compare);
    
    // Check for duplicates in the sorted array
    REP(i, n - 1) {
        if (a[i] == a[i + 1]) {
            // If a duplicate is found, print "NO" and exit
            printf("NO\n");
            return 0;
        }
    }
    
    // If no duplicates are found, print "YES"
    printf("YES\n");
    
    return 0; // End of the program
}
