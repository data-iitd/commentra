#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to define the main logic of the program
void main() {

    // Read input: number of elements 'n' and the difference 'k'
    int n, k;
    scanf("%d %d", &n, &k);

    // Read input: list of elements 'elems'
    int elems[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }

    // Helper function to check if all elements in a list are the same
    int all_same(int arr[], int n) {
        // Return True if all elements in the list are the same, else False
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                return 0;
            }
        }
        return 1;
    }

    // Check if all elements in the list are the same
    if (all_same(elems, n)) {
        // If all elements are the same, print 0 and exit
        printf("0\n");
        return;
    }

    // Check if difference 'k' is 1
    if (k == 1) {
        // If difference is 1, print -1 and exit
        printf("-1\n");
        return;
    }

    // Check if last 'k' elements in the list are not all the same
    if (!all_same(elems + n - k, k)) {
        // If last 'k' elements are not all the same, print -1 and exit
        printf("-1\n");
        return;
    }

    // Initialize target element
    int target = elems[n - 1];

    // Initialize list 'to_delete' to store elements to be deleted
    int to_delete[k - 1];
    for (int i = 0; i < k - 1; i++) {
        to_delete[i] = elems[i];
    }

    // While 'to_delete' is not empty and its last element is 'target'
    while (to_delete[k - 2] == target) {
        // Pop the last element from 'to_delete'
        to_delete[k - 2] = 0;
    }

    // Print the length of 'to_delete'
    printf("%d\n", k - 1 - to_delete[k - 2]);

    // End of code
    printf("