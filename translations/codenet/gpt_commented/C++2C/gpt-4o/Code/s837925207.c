<<<<<<< HEAD
#include <stdio.h> // Include the stdio.h library for input and output
=======
#include <stdio.h> // Include the standard I/O library for input and output
>>>>>>> 98c87cb78a (data updated)

int main() {
    int x, ans = 0; // Declare variables x for input and ans for the result

    // Read an integer input from the user
    scanf("%d", &x);

    // Calculate the result as the sum of x, x squared, and x cubed
    ans = x + x*x + x*x*x;

    // Output the calculated result to the console
    printf("%d\n", ans);

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
