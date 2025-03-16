#include <stdio.h> // Include necessary headers for input and output operations

int main() { // The main function is the entry point of the program
    int A, B, C, X; // Declare variables to store the input values
    scanf("%d %d %d %d", &A, &B, &C, &X); // Read the values of A, B, C, and X from the standard input
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    int cnt = 0; // Initialize a counter to count the number of combinations
    for (int a = 0; a <= A; a++) { // Iterate over the possible values of a (0 to A)
        for (int b = 0; b <= B; b++) { // Iterate over the possible values of b (0 to B)
            for (int c = 0; c <= C; c++) { // Iterate over the possible values of c (0 to C)
                int total = 500 * a + 100 * b + 50 * c; // Calculate the total value of the coins
                if (total == X) cnt++; // If the total equals X, increment the counter
            }
        }
    }
    printf("%d\n", cnt); // Output the number of combinations that sum up to X
<<<<<<< HEAD

    return 0; // Return 0 to indicate successful completion
} // End of main function
// <END-OF-CODE>
=======
    
    return 0; // Return 0 to indicate successful completion
} // <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
