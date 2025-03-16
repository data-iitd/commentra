#include <stdio.h> // Include standard input-output library for basic I/O operations
#include <string.h> // Include string library for string operations

#define MAX_H 10 // Define a constant for maximum height
#define MAX_W 10 // Define a constant for maximum width

int main() {
    long long h, w; // Declare variables for height and width
    scanf("%lld %lld", &h, &w); // Read the dimensions of the grid
<<<<<<< HEAD
    char t[10], s[10] = "snuke"; // Declare character arrays for comparison
=======
    char t[10], s[10] = "snuke"; // Declare character arrays for input and the pattern
>>>>>>> 98c87cb78a (data updated)
    for (long long i = 0; i < h; i++) { // Loop over each row
        for (long long j = 0; j < w; j++) { // Loop over each column
            scanf("%s", t); // Read a character array
            if (strcmp(s, t) == 0) { // Compare the character array with the pattern
                char c = 'A' + j; // Calculate the column letter
                printf("%c%lld\n", c, i + 1); // Output the position in the grid
                return 0; // Terminate the program
            }
        }
    }
    return 0; // End of main function
} // End of main function
// <END-OF-CODE>
