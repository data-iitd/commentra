
#include <stdio.h> // Include the necessary header file for input/output operations

int main() { // Main function to execute the program
    char inp[1000][1000]; // Declare a 2D array to store the input strings
    int n, m; // Declare variables to store the dimensions of the input

    scanf("%d %d", &n, &m); // Read the dimensions of the input from the console

    for (int i = 0; i < n; i++) { // Loop through each row
        scanf("%s", inp[i]); // Read the current row as a string
    }

    for (int i = 0; i < n; i++) { // Loop through each row again
        for (int j = 0; j < m; j++) { // Loop through each character in the row
            if (inp[i][j] == '-') { // Check if the character is a '-'
                printf("-"); // Print '-'
            } else {
                if ((i + j) % 2 == 1) { // Check if the sum of indices is odd
                    printf("W"); // Print 'W'
                } else {
                    printf("B"); // Print 'B'
                }
            }
        }
        printf("\n"); // Print a new line after each row
    }

    return 0; // Return 0 to indicate successful execution
}
