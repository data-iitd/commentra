
#include <stdio.h>
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
        // Return true if all elements in the list are the same, else false
        for (int i = 1; i < size; i++) {
            if (arr[i]!= arr[0]) {
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
    if (!all_same(elems + n - k, k)) {
        // If last 'k' elements are not all the same, print -1 and exit
        printf("-1\n");
        return;
    }

    // Initialize target element
    int target = elems[n - 1];

    // Initialize list 'to_delete' to store elements to be deleted
    int to_delete[k - 1];
    int to_delete_size = 0;

    // While 'to_delete' is not empty and its last element is 'target'
    while (to_delete_size > 0 && to_delete[to_delete_size - 1] == target) {
        // Pop the last element from 'to_delete'
        to_delete_size--;
    }

    // Print the length of 'to_delete'
    printf("%d\n", to_delete_size);
}

