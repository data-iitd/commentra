#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    // Create a Scanner object to read input from the user
    int n; 
    scanf("%d", &n); 
    
    // Initialize an array to hold the input integers
    int a[n]; 
    
    // Variable to hold the cumulative XOR of all elements
    int r = 0; 
    
    // Read each integer from input and compute the cumulative XOR
    for (int i = 0; i < n; i++) { 
        scanf("%d", &a[i]); 
        r ^= a[i]; // Update the cumulative XOR with the current element
    } 
    
    // For each element in the array, print the result of XORing the cumulative XOR with the element
    for (int i = 0; i < n; i++) { 
        if (i != 0) 
            printf(" "); // Print a space before the next number if it's not the first element
        printf("%d", r ^ a[i]); // Print the result of XORing the cumulative XOR with the current element
    } 
    printf("\n"); 
    return 0; 
} 
