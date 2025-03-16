#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation

int* getPoints(int n, int k, int l, int r, int sAll, int sk) {
    int* ans = (int*)malloc(n * sizeof(int)); // Allocating memory for the result array
    for (int i = 0; i < n; i++) {
        ans[i] = l; // Filling the array with the lower bound value 'l'
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
            ans[idx++]; // Incrementing the points and moving to the next element
            sAll--; // Decrementing the remaining points to distribute
        }
    }
    
    return ans; // Returning the result array
}

int main() {
    int n, k, l, r, sAll, sk; // Declaring variables for input
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk); // Reading input values
    
    int* ans = getPoints(n, k, l, r, sAll, sk); // Calling the getPoints function to compute the result
    
    for (int i = 0; i < n; i++) { // Iterating through the result array to print each element
        printf("%d ", ans[i]); // Printing each element followed by a space
    }
    
    free(ans); // Freeing the allocated memory for the result array
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
