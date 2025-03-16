
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int x;
    scanf("%d", &x);
    
    // Create a list to store the digits of the number
    int list[100];
    int listSize = 0;
    
    // Loop through each digit of the number from right to left
    while (x > 0) {
        // Get the last digit of the number
        int r = x % 10;
        
        // Check if the digit is greater than 4 and if 9 - digit is less than digit
        if (9 - r < r) {
            // If it's the last digit and 9 - r is 0, add the digit as is
            if (x / 10 == 0 && 9 - r == 0) {
                list[listSize] = r;
                listSize++;
            } else {
                // Otherwise, add 9 - digit to the list
                list[listSize] = 9 - r;
                listSize++;
            }
        } else {
            // Otherwise, add the digit to the list
            list[listSize] = r;
            listSize++;
        }
        
        // Remove the last digit from the number
        x = x / 10;
    }
    
    // Initialize variables to construct the new number
    int pow = 0;
    int newNumber = 0;
    
    // Loop through the list of digits to construct the new number
    for (int i = 0; i < listSize; i++) {
        // Add the digit to the new number at the appropriate place value
        newNumber = newNumber + list[i] * (int) pow(10, pow);
        pow++;
    }
    
    // Print the new number
    printf("%d", newNumber);
    
    return 0;
}

