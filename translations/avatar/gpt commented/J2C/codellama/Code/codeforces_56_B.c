#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int len; 
    scanf("%d", &len); 
    
    // Initialize an array of the specified length
    int a[len]; 
    
    // Populate the array with user input
    for (int i = 0; i < len; i++) { 
        scanf("%d", &a[i]); 
    } 
    
    // Initialize variables to track the left and right indices of the mismatch
    int l = 0; 
    int r = 0; 
    
    // Flags to indicate the state of the search for mismatches
    bool flag = false; 
    bool isTrue = false; 
    
    // Loop through the array to find the first and second mismatches
    for (int i = 0; i < len; i++) { 
        // Check if the current element does not match its expected value
        if (a[i] != i + 1 && !flag) { 
            // Set the left index to the current position (1-based index)
            l = i + 1; 
            // Set the flag to indicate the first mismatch has been found
            flag = true; 
            continue; 
        } 
        // Check for the second mismatch
        if (a[i] != i + 1 && flag) { 
            // Set the right index to the current position (1-based index)
            r = i + 1; 
            // Check if the previous element is less than the current element
            if ((a[r - 1] - a[r - 2] > 0)) { 
                // Set the isTrue flag to indicate a valid mismatch has been found
                isTrue = true; 
                break; 
            } 
        } 
    } 
    
    // Output the result based on whether a valid mismatch was found
    printf((!isTrue) ? "%d %d\n" : "0 0\n", l, r); 
    return 0; 
}

