#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main() 
{ 
    // Create a Scanner object to read input from the user
    long x; 
    printf("Enter a number: "); 
    scanf("%ld", &x); 
    
    // Initialize a list to store the digits after transformation
    long list[100]; 
    int i = 0; 
    
    // Process each digit of the number until there are no digits left
    while (x > 0) { 
        // Extract the last digit of the number
        long r = x % 10; 
        
        // Determine whether to keep the digit or replace it with its complement to 9
        if (9 - r < r) { 
            // If the digit is the last one and its complement is 0, keep the digit
            if (x / 10 == 0 && 9 - r == 0) 
                list[i++] = r; 
            else 
                // Otherwise, add the complement to the list
                list[i++] = 9 - r; 
        } else 
            // If the digit is less than or equal to its complement, keep the digit
            list[i++] = r; 
        
        // Remove the last digit from the number
        x = x / 10; 
    } 
    
    // Initialize variables to construct the new number
    int pow = 0; 
    long newNumber = 0; 
    
    // Reconstruct the new number from the transformed digits
    for (int j = 0; j < i; j++) { 
        newNumber = newNumber + list[j] * (long) pow(10, pow); 
        pow++; 
    } 
    
    // Output the newly constructed number
    printf("The new number is: %ld\n", newNumber); 
    return 0; 
} 

