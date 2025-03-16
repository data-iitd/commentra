#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an empty list `L` using dynamic memory allocation
    int *L = NULL;
    int size = 0;
    int r = 1; // Initialize r to 1

    // Read the first input, which is the number of elements to add to the list
    int n;
    scanf("%d", &n);

    // Use a for loop to iterate through each integer in the input
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        
        // Resize the list `L` to accommodate new elements
        L = realloc(L, (size + k) * sizeof(int));
        
        // Add `r` elements to the list `L` with the value `r`
        for (int j = 0; j < k; j++) {
            L[size++] = r; // Add r to the list and increment size
        }
        
        // Increment the value of `r` by 1 to prepare for the next iteration
        r++;
    }

    // Read the second input, which represents the indices of the elements to print from the list
    int m;
    scanf("%d", &m);

    // Use another for loop to iterate through each integer in the input
    for (int i = 0; i < m; i++) {
        int j;
        scanf("%d", &j);
        
        // Print the element at the given index using the index as an offset from the beginning of the list
        printf("%d\n", L[j - 1]);
    }

    // Free the allocated memory
    free(L);
    
    return 0;
}

// <END-OF-CODE>
