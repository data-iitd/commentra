
#include <stdio.h> // Include the standard input/output library.
#define ll long long int // Define a macro for long long int.

int main() { // The main function is the entry point of the program.
    int x, ans = 0; // Declare an integer variable x and initialize ans to 0.

    scanf("%d", &x); // Read an integer from the standard input and store it in x.

    ans = x + x*x + x*x*x; // Calculate the result by adding x, x*x, and x*x*x.

    printf("%d\n", ans); // Print the result to the standard output.

    return 0; // Return 0 to indicate successful execution.
}


