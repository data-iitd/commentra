#include <stdio.h>
#include <stdlib.h>

int* getPoints(int n, int k, int l, int r, int sAll, int sk) {
    // Allocate memory for the points array
    int* ans = (int*)malloc(n * sizeof(int));
    
    // Fill the array with the minimum value l
    for (int i = 0; i < n; i++) {
        ans[i] = l;
    }
    
    // Adjust the total sum by subtracting the sum of selected elements and the minimum values
    sAll -= sk + (n - k) * l;
    
    // Adjust the sum of selected elements by subtracting the minimum values
    sk -= k * l;
    
    // Distribute the remaining points to the last k elements
    while (sk > 0) {
        int idx = n - 1;
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++; // Increment the points for the selected elements
            sk--; // Decrease the remaining points to distribute
        }
    }
    
    // Distribute the remaining total sum to the first n-k elements
    while (sAll > 0) {
        int idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]; // Increment the points for the non-selected elements
            sAll--; // Decrease the remaining total sum to distribute
        }
    }
    
    // Return the final points distribution
    return ans;
}

int main() {
    // Read the number of elements (n), number of selected elements (k), 
    // lower bound (l), upper bound (r), total sum (sAll), and sum of selected elements (sk)
    int n, k, l, r, sAll, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk);
    
    // Call the getPoints method to calculate the points distribution
    int* ans = getPoints(n, k, l, r, sAll, sk);
    
    // Print the resulting points distribution
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    
    // Free the allocated memory
    free(ans);
    
    return 0;
}

// <END-OF-CODE>
