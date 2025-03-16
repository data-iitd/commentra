#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);  // Reading the number of elements in the arrays

    int *a = (int *)malloc(n * sizeof(int));  // Dynamically allocating memory for the first array
    int *b = (int *)malloc(n * sizeof(int));  // Dynamically allocating memory for the second array

    int left = INT_MAX, right = INT_MIN;  // Initializing left and right variables

    // Reading the elements of the arrays and updating the minimum and maximum elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Reading an element from the first array
        scanf("%d", &b[i]);  // Reading an element from the second array
        if (a[i] < left) {
            left = a[i];  // Finding the minimum element in the first array
        }
        if (b[i] > right) {
            right = b[i];  // Finding the maximum element in the second array
        }
    }

    // Checking if there is an element that has the same minimum and maximum value in both arrays
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {  // Checking if the current element in both arrays has the same minimum and maximum value
            printf("%d\n", i + 1);  // If true, printing the index of the element (1-based index)
            free(a);  // Freeing allocated memory
            free(b);  // Freeing allocated memory
            return 0;  // Exiting the program after finding the element
        }
    }

    // If no such element is found, printing -1
    printf("-1\n");

    free(a);  // Freeing allocated memory
    free(b);  // Freeing allocated memory
    return 0;
}

// <END-OF-CODE>
