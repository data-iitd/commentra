#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a Scanner object to read input from the user
    int n, k, l, r, sAll, sk; 
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk); 
    
    // Call the getPoints method to calculate the points distribution
    int* ans = getPoints(n, k, l, r, sAll, sk); 
    
    // Print the resulting points distribution
    for (int i = 0; i < n; i++) { 
        printf("%d ", ans[i]); 
    } 
    printf("\n"); 
    
    // Free the memory allocated for the points distribution
    free(ans); 
    return 0; 
} 

int* getPoints(int n, int k, int l, int r, int sAll, int sk) { 
    // Initialize an array to hold the points for each element
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

