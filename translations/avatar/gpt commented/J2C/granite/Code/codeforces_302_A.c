
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    // Create a Scanner object to read input from the console
    int n, k, l, r, o = 0, e = 0; 
    scanf("%d %d", &n, &k); 
    
    // Initialize an array to hold the input values
    int arr[n]; 
    
    // Populate the array with input values
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
    
    // Counters for the number of 1s (o) and 0s (e) in the array
    for (int i = 0; i < n; i++) 
        if (arr[i] == 1) 
            o++; // Increment count of 1s
        else 
            e++; // Increment count of 0s
    
    // Process each query
    for (int i = 0; i < k; i++) { 
        scanf("%d %d", &l, &r); 
        
        // Check if the number of elements in the range is odd
        if ((r - l + 1) % 2 == 1) 
            printf("0\n"); // If odd, print "0"
        else { 
            // If even, check if we can form a valid pair of 1s and 0s
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e) 
                printf("1\n"); // Print "1" if valid pairs can be formed
            else 
                printf("0\n"); // Otherwise, print "0"
        } 
    } 
    
    // Close the scanner to free resources
    return 0; 
}
