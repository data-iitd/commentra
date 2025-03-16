
#include <stdio.h> // Including necessary header files for input/output operations
#include <stdlib.h> // Including necessary header files for memory allocation and deallocation

int main() {
    int n, k, l, r, sAll, sk; // Declaring variables to store the input values
    
    // Reading the input values from the user
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk);
    
    int *ans = (int*)malloc(n * sizeof(int)); // Allocating memory for the result array
    
    for (int i = 0; i < n; i++) { // Initializing the result array with the lower bound value 'l'
        ans[i] = l;
    }
    
    // Subtracting the initial points for the first group and the remaining elements
    sAll -= sk + (n - k) * l;
    sk -= k * l;
    
    // Distributing the remaining points to the first group until sk is zero
    while (sk > 0) {
        int idx = n - 1; // Starting from the last element in the array
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++; // Incrementing the points and moving to the previous element
            sk--; // Decrementing the remaining points to distribute
        }
    }
    
    // Distributing the remaining points to the remaining elements until sAll is zero
    while (sAll > 0) {
        int idx = 0; // Starting from the first element in the array
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++; // Incrementing the points and moving to the next element
            sAll--; // Decrementing the remaining points to distribute
        }
    }
    
    // Printing the result array
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]); // Printing each element followed by a space
    }
    
    free(ans); // Deallocating the memory allocated for the result array
    
    return 0; // Returning 0 to indicate successful execution
}

