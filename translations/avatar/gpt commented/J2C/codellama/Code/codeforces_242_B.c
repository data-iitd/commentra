#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INF (int) 1e9 + 5 

int main() { 
    // Create a Scanner object for input
    int n; 
    scanf("%d", &n); 
    
    // Initialize two ArrayLists to store the pairs
    int *a = (int *) malloc(n * sizeof(int)); 
    int *b = (int *) malloc(n * sizeof(int)); 
    
    // Initialize left to infinity and right to zero
    int left = INF, right = 0; 
    
    // Read the pairs and determine the minimum and maximum values
    for (int i = 0; i < n; i++) { 
        scanf("%d", &a[i]); // Read the first element of the pair
        scanf("%d", &b[i]); // Read the second element of the pair
        
        // Update left to the minimum value found in a
        left = min(left, a[i]); 
        // Update right to the maximum value found in b
        right = max(right, b[i]); 
    } 
    
    // Check for a pair that matches the left and right bounds
    for (int i = 0; i < n; i++) { 
        // If the current pair matches the min and max values
        if (left == a[i] && right == b[i]) { 
            // Print the index (1-based) and exit
            printf("%d\n", i + 1); 
            return 0; 
        } 
    } 
    
    // If no matching pair is found, print -1
    printf("-1\n"); 
    return 0; 
} 

