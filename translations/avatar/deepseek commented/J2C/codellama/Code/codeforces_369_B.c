#include <stdio.h>
#include <stdlib.h>

int* getPoints(int n, int k, int l, int r, int sAll, int sk) {
    int* ans = (int*)malloc(n * sizeof(int)); // Initializing an array to store the result
    for (int i = 0; i < n; i++) { // Filling the array with the lower bound value 'l'
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
    
    return ans; // Returning the result array
}

int main() {
    int n, k, l, r, sAll, sk; // Declaring variables to store the input values
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk); // Reading the input values
    
    int* ans = getPoints(n, k, l, r, sAll, sk); // Calling the getPoints method to compute the result
    
    for (int i = 0; i < n; i++) { // Iterating through the result array to print each element
        printf("%d ", ans[i]); // Printing each element followed by a space
    }
    printf("\n"); // Printing a newline character
    
    free(ans); // Freeing the memory allocated for the result array
    return 0;
}

