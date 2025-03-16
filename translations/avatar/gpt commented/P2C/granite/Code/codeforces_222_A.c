
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Read two integers n and k from input
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Read a list of n integers from input
    int elems[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }
    
    // Define a lambda function to check if all elements in an array are the same
    bool all_same(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            if (arr[i]!= arr[0]) {
                return false;
            }
        }
        return true;
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
    if (!all_same(elems + n - k, k)) {
        printf("-1\n");
        return 0;
    }
    
    // Set the target value to the last element of elems
    int target = elems[n - 1];
    
    // Create a list of elements to delete, which are the first k-1 elements
    int to_delete[k - 1];
    int to_delete_size = 0;
    for (int i = 0; i < k - 1; i++) {
        if (elems[i]!= target) {
            to_delete[to_delete_size++] = elems[i];
        }
    }
    
    // Print the number of elements that need to be deleted
    printf("%d\n", to_delete_size);
    
    // End of code
    return 0;
}

