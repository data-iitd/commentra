#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Initialize the variable 'n' to read the number of elements in the array 'a'
    int n;
    scanf("%d", &n);

    // Create an array 'a' to store the input elements
    int *a = (int *)malloc(n * sizeof(int));

    // Read 'n' elements from the standard input and store them in array 'a'
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Create an array 'b' to store the unique elements
    int *b = (int *)malloc(n * sizeof(int));
    int b_len = 0;

    // Iterate through each element 'v' in array 'a'
    for (int i = 0; i < n; i++) {
        int v = a[i];
        // Use binary search to find the index 'x' where 'v' should be inserted in array 'b'
        int x = b_len;
        for (int j = 0; j < b_len; j++) {
            if (b[j] >= v) {
                x = j;
                break;
            }
        }

        // If 'x' is equal to the length of array 'b', it means 'v' is not present in the array, so append it
        if (x == b_len) {
            b[b_len++] = v;
        } else {
            // Otherwise, replace the element at index 'x' in array 'b' with 'v'
            b[x] = v;
        }
    }

    // Print the length of array 'b' as the output
    printf("%d\n", b_len);

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}

// <END-OF-CODE>
