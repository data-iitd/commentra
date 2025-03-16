#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int n; 
    scanf("%d", &n); 
    
    // Initialize an array to hold the input integers
    int arr[n]; 
    
    // Populate the array with integers from user input
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
    
    // Initialize the answer with the first element of the array plus one
    int ans = arr[0] + 1; 
    
    // Calculate the total distance based on the differences between consecutive elements
    for (int i = 1; i < n; i++) { 
        // Add the absolute difference between the current and previous element, plus 2
        ans += abs(arr[i] - arr[i - 1]) + 2; 
    } 
    
    // Output the final calculated answer
    printf("%d\n", ans); 
    
    return 0; 
} 
