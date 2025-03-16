#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool all_same(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Read the number of elements (n) and the parameter (k)
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Read the list of elements
    int* elems = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }
    
    // Check if all elements in the list are the same
    if (all_same(elems, n)) {
        // If all elements are the same, print 0 and return
        printf("0\n");
        free(elems);
        return 0;
    }
    
    // If k is 1, print -1 and return
    if (k == 1) {
        printf("-1\n");
        free(elems);
        return 0;
    }
    
    // Check if elements from index k-1 to the end are all the same
    if (!all_same(elems + (k - 1), n - (k - 1))) {
        // If not, print -1 and return
        printf("-1\n");
        free(elems);
        return 0;
    }
    
    // Set the target to the last element of the list
    int target = elems[n - 1];
    
    // Initialize to_delete as elements from the start to k-1
    int to_delete_count = k - 1;
    
    // Remove elements from to_delete that are equal to target until a different element is found
    while (to_delete_count > 0 && elems[to_delete_count - 1] == target) {
        to_delete_count--;
    }
    
    // Print the length of to_delete
    printf("%d\n", to_delete_count);
    
    // Free allocated memory
    free(elems);
    
    return 0;
}

// <END-OF-CODE>
