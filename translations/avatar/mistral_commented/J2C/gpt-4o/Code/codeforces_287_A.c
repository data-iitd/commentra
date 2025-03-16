#include <stdio.h>
#include <string.h>

int main() {
    char str[4][100]; // Define an array of strings named str with a length of 4 to store the input strings
    int i = -1; // Initialize an integer variable i to -1

    while (i != 3) { // Enter a while loop that continues as long as i is not equal to 3
        i++; // Increment i by 1 in each iteration of the loop
        scanf("%s", str[i]); // Read the next input string using scanf and store it in the str array at index i
    }

    int u = -1; // Initialize an integer variable u to -1

    while (u != 2) { // Enter an outer while loop that continues as long as u is not equal to 2
        u++; // Increment u by 1 in each iteration of the loop

        int yes = 0; // Initialize an integer variable yes to 0
        int j = -1; // Initialize an integer variable j to -1 for character comparison

        while (j != 2) { // Enter an inner while loop that continues as long as j is not equal to 2
            j++; // Increment j by 1 in each iteration of the loop

            if ((str[u][j] == str[u][j + 1] && (str[u + 1][j] == str[u][j] || str[u + 1][j + 1] == str[u][j])) ||
                (str[u + 1][j] == str[u + 1][j + 1] && (str[u][j] == str[u + 1][j] || str[u][j + 1] == str[u + 1][j]))) {
                yes = 1; // Set the yes variable to 1 if the condition is true
                printf("YES\n"); // Print "YES" to the standard output if the condition is true
                break; // Break out of the inner loop if the condition is true
            }
        }

        if (yes == 1) { // If the yes variable is set to 1, break out of the outer while loop
            break;
        }

        if (yes == 0) { // If the yes variable is still equal to 0, print "NO" to the standard output
            printf("NO\n");
        }
    }

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
