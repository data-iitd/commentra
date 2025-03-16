#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Create a list to store the digits of the number
    int list[10];
    int size = 0;
    
    // Read the number from the input
    long x;
    scanf("%ld", &x);
    
    // Loop through each digit of the number from right to left
    while (x > 0) {
        // Get the last digit of the number
        int r = x % 10;
        
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
    int pow = 0;
    long newNumber = 0;
    
    // Loop through the list of digits to construct the new number
    for (int i = size - 1; i >= 0; i--) {
        // Add the digit to the new number at the appropriate place value
        newNumber = newNumber + list[i] * (long) pow(10, pow);
        pow++;
    }
    
    // Print the new number
    printf("%ld\n", newNumber);
    
