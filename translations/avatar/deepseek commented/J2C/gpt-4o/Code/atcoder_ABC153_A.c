#include <stdio.h> // Including standard input-output header
#include <stdlib.h> // Including standard library for atoi function

int main() {
    int h, a; // Declaring variables for height and amount to subtract
    int num = 0; // Initializing a counter to keep track of the number of subtractions

    // Reading input from the user
    scanf("%d %d", &h, &a); // Reading two integers from standard input

    // Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
    while (h > 0) {
        h -= a; // Subtracting 'a' from 'h'
        num++; // Incrementing the counter
    }

    printf("%d\n", num); // Printing the result, which is the number of subtractions
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
