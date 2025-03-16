#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

int main() { 
    // Create a Scanner object for input and a PrintWriter for output
    int n; 
    scanf("%d", &n); 
    int list[n]; 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &list[i]); 
    } 
    
    // Sort the list of integers in ascending order
    qsort(list, n, sizeof(int), compare); 
    
    // Initialize a counter to track the maximum consecutive integer
    int c = 1; 
    
    // Iterate through the sorted list to find the maximum consecutive integer
    for (int i = 0; i < n; i++) { 
        // If the current integer is greater than or equal to the counter, increment the counter
        if (list[i] >= c) { 
            c++; 
        } 
    } 
    
    // Print the result which is the maximum consecutive integer found
    printf("%d\n", c); 
    
    return 0; 
} 

int compare(const void *a, const void *b) { 
    return (*(int *)a - *(int *)b); 
} 

// Debugging method to print objects to the error output
void debug(int n, int *list) { 
    for (int i = 0; i < n; i++) { 
        printf("%d ", list[i]); 
    } 
    printf("\n"); 
} 

