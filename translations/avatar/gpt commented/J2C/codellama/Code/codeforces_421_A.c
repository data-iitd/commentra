#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int n, a, b; 
    scanf("%d %d %d", &n, &a, &b); 
    
    // Declare variables for the number of elements and sizes of the two lists
    int n, a, b; 
    
    // Read the values for n, a, and b from the input
    scanf("%d %d %d", &n, &a, &b); 
    
    // Initialize two ArrayLists to store the elements of the two lists
    int list1[a]; 
    int list2[b]; 
    
    // Read 'a' integers into list1
    for (int i = 0; i < a; i++) { 
        scanf("%d", &list1[i]); 
    } 
    
    // Read 'b' integers into list2
    for (int i = 0; i < b; i++) { 
        scanf("%d", &list2[i]); 
    } 
    
    // Iterate from 0 to n-1 to check the presence of each index in list1
    for (int i = 0; i < n; i++) { 
        // If the current index + 1 is in list1, print 1
        if (list1[i] == i + 1) { 
            printf("%d ", 1); 
        } else { 
            // Otherwise, print 2
            printf("%d ", 2); 
        } 
    } 
    printf("