#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long x;
    scanf("%ld", &x); // Reading the first number from the standard input stream

    long *list = (long *)malloc(20 * sizeof(long)); // Creating an array to store digits (assuming a maximum of 20 digits)
    int size = 0; // To keep track of the number of digits stored

    // The following while loop runs as long as the number x is greater than zero
    while (x > 0) {
        long r = x % 10; // Storing the last digit of the number x in the variable r

        // The following if statement checks if the difference between 9 and the last digit r is less than r itself
        if (9 - r < r) {
            // The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
            if (x / 10 == 0 && 9 - r == 0) {
                list[size++] = r; // Adding the last digit r to the array if it is the only digit in the number x
            } else {
                list[size++] = 9 - r; // Adding the number 9 minus the last digit r to the array
            }
        } else {
            list[size++] = r; // Adding the last digit r to the array
        }

        x = x / 10; // Dividing the number x by 10 to get the next digit
    }

    long newNumber = 0; // Initializing the variable newNumber to 0 to store the final number
    // The following for loop runs through each digit in the array and calculates the new number
    for (int i = 0; i < size; i++) {
        newNumber += list[i] * (long)pow(10, i); // Adding the digit multiplied by the power of 10 to newNumber
    }

    printf("%ld\n", newNumber); // Printing the final number to the standard output stream

    free(list); // Freeing the allocated memory
    return 0;
} // <END-OF-CODE>
