#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() 
{ 
    // Create a Scanner object to read input from the user
    int n; 
    printf("Enter the number of elements in the array: "); 
    scanf("%d", &n); 
    
    // Initialize an array of size n to store the input values
    int a[n]; 
    
    // Loop to read n integers from the user and store them in the array
    for (int i = 0; i < n; i++) { 
        printf("Enter element %d: ", i + 1); 
        scanf("%d", &a[i]); 
    } 
    
    // Sort the array in ascending order
    qsort(a, n, sizeof(int), compare); 
    
    // Store the minimum value from the sorted array
    int min = a[0]; 
    
    // Check if all elements in the array are divisible by the minimum value
    for (int i = 0; i < n; i++) { 
        if (a[i] % min != 0) { 
            // If any element is not divisible, print -1 and exit
            printf("-1\n"); 
            return 0; 
        } 
    } 
    
    // If all elements are divisible, print the minimum value
    printf("%d\n", min); 
    
    return 0; 
} 

int compare(const void *a, const void *b) 
{ 
    return (*(int *)a - *(int *)b); 
} 

