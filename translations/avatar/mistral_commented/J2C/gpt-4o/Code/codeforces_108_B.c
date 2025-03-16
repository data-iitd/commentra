#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for sorting

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements in the array from user input
    int a[n]; // Creating an integer array of size n

    // Initializing the array with user input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sorting the array in ascending order
    qsort(a, n, sizeof(int), compare);

    // Checking if there is any pair of adjacent elements that satisfy the condition
    for (int i = 0; i < n - 1; i++) {
        // Checking if the next element is less than twice the current element and they are not the same
        if (a[i + 1] < a[i] * 2 && a[i] != a[i + 1]) {
            printf("YES\n"); // Printing "YES" if a pair is found
            return 0; // Exiting the program if a pair is found
        }
    }

    // If no pair is found, printing "NO"
    printf("NO\n");
    return 0; // Exiting the program
}

// <END-OF-CODE>
