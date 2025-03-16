
#include <stdio.h> // Include the standard input/output library

int main() {
    int n, i, odd = 0, even = 0, odd_ind = 0, even_ind = 0; // Declare variables for the number of elements, loop counter, and counters for odd and even numbers
    
    printf("Enter the number of elements: "); // Prompt the user to enter the number of elements
    scanf("%d", &n); // Read the number of elements from the user
    
    int array[n + 1]; // Declare an array of size n + 1 to store the input integers
    
    printf("Enter %d integers:\n", n); // Prompt the user to enter n integers
    
    for (i = 1; i <= n; i++) { // Loop to read n integers from the user and store them in the array
        scanf("%d", &array[i]); // Read each integer from the user and store it in the array
    }
    
    for (i = 1; i <= n; i++) { // Loop to count odd and even numbers and track their latest indices
        if (array[i] % 2 == 0) { // Check if the number is even
            even++; // Increment the even counter
            even_ind = i; // Update the index of the last even number
        } else { // The number is odd
            odd++; // Increment the odd counter
            odd_ind = i; // Update the index of the last odd number
        }
    }
    
    if (odd > even) { // Compare the counts of odd and even numbers to determine which index to print
        printf("The index of the last even number is %d.\n", even_ind); // Print the index of the last even number if there are more odds
    } else {
        printf("The index of the last odd number is %d.\n", odd_ind); // Print the index of the last odd number otherwise
    }
    
    return 0; // Return 0 to indicate successful execution of the program
}
