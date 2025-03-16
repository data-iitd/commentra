
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Read the number of integers from input
    int n;
    scanf("%d", &n);

    // Initialize an array to store the integers
    int a[n];

    // Read n integers from input and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the array in ascending order
    qsort(a, n, sizeof(int), cmpfunc);

    // Initialize a flag to check for consecutive triplets
    bool found = false;

    // Check for three consecutive integers in the sorted array
    for (int i = 0; i < n - 2; i++) {
        // Check if the current, next, and the one after next integers are consecutive
        if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
            found = true; // Set found to true if consecutive triplet is found
        }
    }

    // Output "YES" if a triplet was found, otherwise output "NO"
    if (found) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// Function to compare two integers for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// End of code