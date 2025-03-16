#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <limits.h> 

// Variable to store the minimum result found
long min; 

// Function to perform operations and find the minimum result
void util(long *arr, char **ops, int idx) { 
    // Base case: if all operations have been used, update the minimum result
    if (idx == 3) { 
        min = arr[0]; 
        return; 
    } 
    
    // Iterate through all pairs of numbers in the list
    for (int i = 0; i < 4; i++) { 
        for (int j = i + 1; j < 4; j++) { 
            // Create a new list to hold the remaining numbers after the operation
            long a[3]; 
            
            // Add the remaining numbers to the new list
            int k = 0; 
            for (int l = 0; l < 4; l++) { 
                if (l != j && l != i) { 
                    a[k++] = arr[l]; 
                } 
            } 
            
            long res; 
            // Perform the operation based on the current operation in the ops array
            if (idx < 3 && strcmp(ops[idx], "+") == 0) { 
                res = arr[i] + arr[j]; // Addition operation
            } else { 
                res = arr[i] * arr[j]; // Multiplication operation
            } 
            
            // Add the result of the operation to the new list
            a[k] = res; 
            
            // Recursively call util with the new list and the next operation index
            util(a, ops, idx + 1); 
        } 
    } 
} 

int main() { 
    // Create a Scanner object for user input
    long arr[4]; 
    char ops[3][3]; 
    
    // Initialize min to the maximum possible value
    min = LONG_MAX; 
    
    // Read 4 long integers from user input and add them to the list
    for (int i = 0; i < 4; i++) { 
        scanf("%ld", &arr[i]); 
    } 
    
    // Read 3 operations from user input
    for (int i = 0; i < 3; i++) { 
        scanf("%s", ops[i]); 
    } 
    
    // Call the utility function to compute the minimum result
    util(arr, ops, 0); 
    
    // Print the minimum result found
    printf("%ld\n", min); 
    return 0; 
} 

