#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if all elements in an array are the same
bool all_same(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

// Main function to define the main logic of the program
int main() {
    // Read input: number of elements 'n' and the difference 'k'
    int n, k;
    scanf("%d %d", &n, &k);

    // Read input: list of elements 'elems'
    int *elems = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }

    // Check if all elements in the list are the same
    if (all_same(elems, n)) {
        // If all elements are the same, print 0 and exit
        printf("0\n");
        free(elems);
        return 0;
    }

    // Check if difference 'k' is 1
    if (k == 1) {
        // If difference is 1, print -1 and exit
        printf("-1\n");
        free(elems);
        return 0;
    }

    // Check if last 'k' elements in the list are not all the same
    if (!all_same(elems + (n - k), k)) {
        // If last 'k' elements are not all the same, print -1 and exit
        printf("-1\n");
        free(elems);
        return 0;
    }

    // Initialize target element
    int target = elems[n - 1];

    // Initialize list 'to_delete' to store elements to be deleted
    int *to_delete = (int *)malloc((k - 1) * sizeof(int));
    for (int i = 0; i < k - 1; i++) {
        to_delete[i] = elems[i];
    }

    // Count the number of elements to delete
    int delete_count = k - 1;

    // While 'to_delete' is not empty and its last element is 'target'
    while (delete_count > 0 && to_delete[delete_count - 1] == target) {
        // Decrease the count of elements to delete
        delete_count--;
    }

    // Print the length of 'to_delete'
    printf("%d\n", delete_count);

    // Free allocated memory
    free(elems);
    free(to_delete);

    return 0;
}
// <END-OF-CODE>
