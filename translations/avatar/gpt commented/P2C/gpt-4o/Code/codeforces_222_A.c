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
    // Read two integers n and k from input
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Read a list of n integers from input
    int* elems = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }
    
    // If all elements in elems are the same, print 0 and exit
    if (all_same(elems, n)) {
        printf("0\n");
        free(elems);
        return 0;
    }
    
    // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
    if (k == 1) {
        printf("-1\n");
        free(elems);
        return 0;
    }
    
    // If the last k-1 elements are not the same, print -1 and exit
    if (!all_same(elems + (k - 1), n - (k - 1))) {
        printf("-1\n");
        free(elems);
        return 0;
    }
    
    // Set the target value to the last element of elems
    int target = elems[n - 1];
    
    // Create a list of elements to delete, which are the first k-1 elements
    int to_delete_size = k - 1;
    int* to_delete = (int*)malloc(to_delete_size * sizeof(int));
    for (int i = 0; i < to_delete_size; i++) {
        to_delete[i] = elems[i];
    }
    
    // Remove elements from to_delete that are equal to the target from the end
    while (to_delete_size > 0 && to_delete[to_delete_size - 1] == target) {
        to_delete_size--;
    }
    
    // Print the number of elements that need to be deleted
    printf("%d\n", to_delete_size);
    
    // Free allocated memory
    free(elems);
    free(to_delete);
    
    return 0;
}

// <END-OF-CODE>
