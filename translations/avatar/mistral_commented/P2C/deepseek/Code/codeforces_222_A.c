#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    bool all_same(int arr[], int size) {
        for (int i = 1; i < size; i++) {
            if (arr[i] != arr[0]) {
                return false;
            }
        }
        return true;
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
    if (!all_same(elems + k - 1, n - k + 1)) {
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
    while (to_delete[0] != '\0' && to_delete[0] == target) {
        for (int i = 0; i < k - 2; i++) {
            to_delete[i] = to_delete[i + 1];
        }
        to_delete[k - 2] = '\0';
    }

    // Print the length of 'to_delete'
    printf("%zu\n", sizeof(to_delete) / sizeof(to_delete[0]));
}
