#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a variable to store the input number
    long x;
    
    // Read the number from the input
    scanf("%ld", &x);
    
    // Create an array to store the digits of the number
    long list[20]; // Assuming the number of digits won't exceed 20
    int size = 0;
    
    // Loop through each digit of the number from right to left
    while (x > 0) {
        // Get the last digit of the number
        long r = x % 10;
        
        // Check if the digit is greater than 4 and if 9 - digit is less than digit
        if (9 - r < r) {
            // If it's the last digit and 9 - r is 0, add the digit as is
            if (x / 10 == 0 && 9 - r == 0) {
                list[size++] = r;
            } else {
                // Otherwise, add 9 - digit to the list
                list[size++] = 9 - r;
            }
        } else {
            // Otherwise, add the digit to the list
            list[size++] = r;
        }
        
        // Remove the last digit from the number
        x = x / 10;
    }
    
    // Initialize variables to construct the new number
    long newNumber = 0;
    
    // Loop through the list of digits to construct the new number
    for (int i = 0; i < size; i++) {
        newNumber += list[i] * (long) pow(10, i);
    }
    
    // Print the new number
    printf("%ld\n", newNumber);
    
    return 0;
}

// <END-OF-CODE>
