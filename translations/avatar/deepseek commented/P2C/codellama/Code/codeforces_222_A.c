
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000

int main() {
    // Read the number of elements (n) and the parameter (k)
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Read the list of elements
    int elems[MAX_INPUT];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }
    
    // Define a lambda function to check if all elements in a list are the same
    int all_same(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                return 0;
            }
        }
        return 1;
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
    int to_delete[MAX_INPUT];
    for (int i = 0; i < k - 1; i++) {
        to_delete[i] = elems[i];
    }
    
    // Remove elements from to_delete that are equal to target until a different element is found
    int j = k - 1;
    for (int i = k - 1; i < n; i++) {
        if (elems[i] != target) {
            to_delete[j++] = elems[i];
        }
    }
    
    // Print the length of to_delete
    printf("%d\n", j);
    
    return 0;
}

