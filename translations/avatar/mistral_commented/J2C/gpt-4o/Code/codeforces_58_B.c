#include <stdio.h>  // Importing the standard I/O library

int main() {
    int n;  // Declaring an integer variable to store the first number

    // Reading the first number from the user input
    scanf("%d", &n);

    printf("%d\n", n);  // Printing the first number to the standard output stream

    int m = n;  // Initializing an integer variable 'm' with the value of 'n'

    // Finding the factors of the number 'n' using a for loop
    for (int i = n - 1; i > 0; i--) {
        if (m % i == 0) {  // Checking if 'i' is a factor of 'm'
            printf("%d\n", i);  // Printing the factor to the standard output stream
            m = i;  // Updating the value of 'm' with the current factor
        }
    }

    return 0;  // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
