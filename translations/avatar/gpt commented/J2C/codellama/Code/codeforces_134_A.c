#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    // Create a Scanner object to read input from the user
    int n; 
    scanf("%d", &n); 
    
    // Initialize an array to hold the integers and a variable to store the sum
    int arr[n]; 
    int sum = 0; 
    
    // Read the integers into the array and calculate the sum
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
        sum += arr[i]; // Accumulate the sum of the elements
    } 
    
    // Initialize a counter for valid indices and a StringBuilder for output
    int c = 0; 
    char sb[100]; 
    
    // Check each element to see if it can be the "removed" element
    for (int i = 0; i < n; i++) { 
        // Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) { 
            c++; // Increment the count of valid indices
            sprintf(sb, "%d ", i + 1); // Append the 1-based index to the StringBuilder
        } 
    } 
    
    // Output the count of valid indices
    printf("%d\n", c); 
    
    // Output the indices of valid elements
    printf("%s\n", sb); 
    
    return 0; 
} 
