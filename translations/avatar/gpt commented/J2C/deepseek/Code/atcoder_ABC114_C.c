#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a static Scanner object for input
static char input[100];

// Method to read a String input from the user
char* gs() {
    fgets(input, sizeof(input), stdin);
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;
    return input;
}

// Method to read an integer input from the user
int gi() {
    gs();
    return atoi(input);
}

// Method to read a long input from the user
long gl() {
    gs();
    return atol(input);
}

// Method to read a double input from the user
double gd() {
    gs();
    return atof(input);
}

int main() {
    // Initialize a long variable i starting from 357
    long i = 357;

    // Initialize a counter to keep track of valid numbers
    int c = 0;

    // Read an integer N from the user
    int N = gi();

    // Loop until i exceeds N
    while (i <= N) {
        // Convert the current number i to a String
        char s[20];
        sprintf(s, "%ld", i);

        // Check if the string contains '3', '5', and '7'
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7"))
            c++; // Increment the counter if all digits are present

        // Create a StringBuilder to construct a new number
        char sb[20] = "";
        int f = 0; // Flag to indicate if a replacement has occurred

        // Iterate through the digits of the number in reverse order
        for (int j = 0; j < strlen(s); j++) {
            char a = s[strlen(s) - 1 - j]; // Get the current digit

            // If a replacement has occurred, append the digit as is
            if (f) {
                strncat(sb, &a, 1);
            } else {
                // Replace '3' with '5' and set the flag
                if (a == '3') {
                    strcat(sb, "5");
                    f = 1;
                }
                // Replace '5' with '7' and set the flag
                else if (a == '5') {
                    strcat(sb, "7");
                    f = 1;
                }
                // If it's neither, append '3'
                else {
                    strncat(sb, &a, 1);
                }
            }
        }

        // If no replacement occurred, append '3' to the StringBuilder
        if (!f)
            strncat(sb, "3", 1);

        // Reverse the constructed number and parse it back to long
        char sb2[20];
        strcpy(sb2, sb);
        strrev(sb2);
        i = atol(sb2);
    }

    // Print the total count of valid numbers found
    printf("%d\n", c);

    return 0;
}
