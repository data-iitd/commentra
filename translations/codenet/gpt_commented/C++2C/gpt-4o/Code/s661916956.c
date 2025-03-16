<<<<<<< HEAD
#include <stdio.h> // Include the stdio.h library for input and output
#include <stdlib.h> // Include the stdlib.h library for the swap function
=======
#include <stdio.h> // Include the standard I/O library for input and output
>>>>>>> 98c87cb78a (data updated)

int main() {
    int a, b, c; // Declare three integer variables to hold the input values
    scanf("%d %d %d", &a, &b, &c); // Read three integers from the user

    // Check if 'a' is greater than 'b', if so, swap their values
    if (a > b) {
<<<<<<< HEAD
        int temp = a; // Use a temporary variable to hold the value of 'a'
        a = b; // Assign the value of 'b' to 'a'
        b = temp; // Assign the value of 'temp' (original 'a') to 'b'
=======
        int temp = a; 
        a = b; 
        b = temp;
>>>>>>> 98c87cb78a (data updated)
    }

    // Check if 'b' is greater than 'c', if so, swap their values
    if (b > c) {
<<<<<<< HEAD
        int temp = b; // Use a temporary variable to hold the value of 'b'
        b = c; // Assign the value of 'c' to 'b'
        c = temp; // Assign the value of 'temp' (original 'b') to 'c'
=======
        int temp = b; 
        b = c; 
        c = temp;
>>>>>>> 98c87cb78a (data updated)
    }

    // Check again if 'a' is greater than 'b', if so, swap their values
    if (a > b) {
<<<<<<< HEAD
        int temp = a; // Use a temporary variable to hold the value of 'a'
        a = b; // Assign the value of 'b' to 'a'
        b = temp; // Assign the value of 'temp' (original 'a') to 'b'
=======
        int temp = a; 
        a = b; 
        b = temp;
>>>>>>> 98c87cb78a (data updated)
    }

    // Output the sorted values of a, b, and c
    printf("%d %d %d\n", a, b, c);

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
