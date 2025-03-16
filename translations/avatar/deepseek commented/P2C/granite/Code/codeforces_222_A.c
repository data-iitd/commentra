

#include <stdio.h>
#include <stdbool.h>

int main() {
    // Read the number of elements (n) and the parameter (k)
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Read the list of elements
    int elems[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }
    
    // Define a function to check if all elements in a list are the same
    bool all_same(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            if (arr[i]!= arr[0]) {
                return false;
            }
        }
        return true;
    }
    
    // Check if all elements in the list are the same
    if (all_same(elems, n)) {
        // If all elements are the same, print 0 and return
        printf("0\n");
        return 0;
    }
    
    // If k is 1, print -1 and return
    if (k == 1) {
        printf("-1\n");
        return 0;
    }
    
    // Check if elements from index k-1 to the end are all the same
    if (!all_same(elems + k - 1, n - k + 1)) {
        // If not, print -1 and return
        printf("-1\n");
        return 0;
    }
    
    // Set the target to the last element of the list
    int target = elems[n - 1];
    
    // Initialize to_delete as elements from the start to k-1
    int to_delete[k - 1];
    for (int i = 0; i < k - 1; i++) {
        to_delete[i] = elems[i];
    }
    
    // Remove elements from to_delete that are equal to target until a different element is found
    int i = k - 2;
    while (i >= 0 && to_delete[i] == target) {
        i--;
    }
    
    // Print the length of to_delete
    printf("%d\n", i + 1);
    
    return 0;
}

