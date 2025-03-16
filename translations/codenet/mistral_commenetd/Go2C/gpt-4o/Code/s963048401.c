#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX_SIZE 100000

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to read an integer from stdin
int intScanner() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read input and process it
int main() {
    // Read the number of elements in the array
    int n = intScanner();

    // Initialize an array to store the elements
    int as[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        as[i] = intScanner();
    }

    // Initialize an array to store unique elements
    int xs[MAX_SIZE];
    int uniqueCount = 0;

    // Iterate through the array and add unique elements to the xs array
    for (int j = 0; j < n; j++) {
        // Check if the current element is already in the xs array
        int found = 0;
        for (int k = 0; k < uniqueCount; k++) {
            if (xs[k] == as[j]) {
                found = 1;
                break;
            }
        }
        // If the current element is not found, add it to the xs array
        if (!found) {
            xs[uniqueCount++] = as[j];
        }
    }

    // Print the length of the xs array
    printf("%d\n", uniqueCount);

    return 0;
}

// <END-OF-CODE>
