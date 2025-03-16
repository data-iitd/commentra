
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the user
    int n;
    scanf("%d", &n);
    
    // Initialize an ArrayList to store the integers
    int *a = (int*)malloc(n * sizeof(int));
    
    // If there is only one integer, print it and exit
    if (n == 1) {
        scanf("%d", &a[0]);
        printf("%d\n", a[0]);
        free(a);
        return 0;
    }
    
    // Read n integers from input and store them in the ArrayList
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the ArrayList in ascending order
    qsort(a, n, sizeof(int), cmpfunc);
    
    // If the largest number is 0, print 0 and exit
    if (a[n - 1] == 0) {
        printf("0\n");
        free(a);
        return 0;
    }
    
    // Initialize the answer variable
    int ans = 0;
    
    // Loop until the ArrayList is reduced to one element
    while (true) {
        // If only one element remains, set it as the answer and break the loop
        if (n == 1) {
            ans = a[0];
            break;
        }
        // Call the function to process the ArrayList and update it
        a = func(a, &n);
    }
    
    // Print the final answer
    printf("%d\n", ans);
    free(a);
    return 0;
}

// Function to process the ArrayList and return a modified version
int *func(int *a, int *n) {
    // Create a copy of the input ArrayList
    int *A = (int*)malloc((*n) * sizeof(int));
    for (int i = 0; i < *n; i++) {
        A[i] = a[i];
    }
    
    // Initialize a variable to store the minimum value
    int min = 0;
    
    // Iterate through the ArrayList
    for (int i = 0; i < *n; i++) {
        // If the current element is 0, remove it from the list
        if (A[i] == 0) {
            for (int j = i; j < *n - 1; j++) {
                A[j] = A[j + 1];
            }
            (*n)--;
            i--; // Adjust index after removal
        } else {
            // If min is not zero, update the current element
            if (min!= 0) {
                A[i] = A[i] % min;
                // If the updated element is 1, print 1 and exit
                if (A[i] == 1) {
                    printf("1\n");
                    free(A);
                    return NULL;
                }
            } else {
                // Set min to the current element if min is still zero
                min = A[i];
            }
        }
    }
    
    // Sort the modified ArrayList before returning
    qsort(A, *n, sizeof(int), cmpfunc);
    return A;
}

// Function to compare two integers for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

