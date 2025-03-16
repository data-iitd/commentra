#include <stdio.h>
#include <string.h>

int main() {
    char str[4][256]; // Define an array of strings named str with a length of 4 to store the input strings
    int i = -1; // Initialize an integer variable i to -1, which will be used as an index to read input strings into the str array

    // Read input strings into the str array
    while (i != 3) {
        i = i + 1;
        scanf("%s", str[i]);
    }

    int u = -1; // Initialize an integer variable u to -1, which will be used as an index to compare adjacent strings in the str array

    // Compare adjacent strings in the str array
    while (u != 2) {
        u = u + 1;

        int yes = 0; // Initialize an integer variable yes to 0
        int i = -1; // Initialize an integer variable i to -1, which will be used as an index to compare characters in the current and next strings

        // Compare characters in the current and next strings
        while (i != 2) {
            i = i + 1;

            if ((str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i])) ||
                (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))) {
                yes = 1; // Set the yes variable to 1 if the condition is true
                printf("YES\n"); // Print "YES" to the standard output if the condition is true
                break; // Break out of both loops using the break statement if the condition is true
            }
        }

        if (yes == 1) { // If the yes variable is set to 1, break out of the outer while loop
            break;
        }

        if (yes == 0) { // If the yes variable is still equal to 0, print "NO" to the standard output
            printf("NO\n");
        }
    }

    return 0;
}
