#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool all_same(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    
    // Read two integers n and k from input
    scanf("%d %d", &n, &k);
    
    // Read a list of n integers from input
    int elems[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }
    
    // If all elements in elems are the same, print 0 and exit
    if (all_same(elems, n)) {
        printf("0\n");
        return 0;
    }
    
    // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
    if (k == 1) {
        printf("-1\n");
        return 0;
    }
    
    // If the last k-1 elements are not the same, print -1 and exit
    if (!all_same(elems + n - k + 1, k - 1)) {
        printf("-1\n");
        return 0;
    }
    
    // Set the target value to the last element of elems
    int target = elems[n - 1];
    
    // Create a list of elements to delete, which are the first k-1 elements
    int to_delete[k - 1];
    for (int i = 0; i < k - 1; i++) {
        to_delete[i] = elems[i];
    }
    
    // Remove elements from to_delete that are equal to the target from the end
    while (to_delete[0] == target) {
        for (int i = 0; i < k - 2; i++) {
            to_delete[i] = to_delete[i + 1];
        }
    }
    
    // Print the number of elements that need to be deleted
    printf("%zu\n", sizeof(to_delete) / sizeof(to_delete[0]));
    
    return 0;
}
