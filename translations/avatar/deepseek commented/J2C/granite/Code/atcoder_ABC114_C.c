
#include <stdio.h> // Include the standard input/output library

int main() {
    int N = 0; // Declare and initialize the variable N
    scanf("%d", &N); // Read an integer N from the user

    long i = 357; // Declare and initialize the variable i
    int c = 0; // Declare and initialize the variable c

    // Main loop to find numbers containing '3', '5', and '7'
    while (i <= N) {
        char s[20]; // Declare a character array to store the current number
        sprintf(s, "%ld", i); // Convert the current number to a string
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7")) {
            c++; // Increment the counter if all required digits are present
        }

        // Build a new number by replacing the last digit
        char sb[20] = ""; // Declare a character array to store the new number
        bool f = false; // Declare and initialize a boolean variable f
        for (int j = strlen(s) - 1; j >= 0; j--) {
            char a = s[j]; // Get the current digit
            if (f) {
                strcat(sb, &a); // Append the digit to the new number
            } else {
                if (a == '3') {
                    strcat(sb, "5"); // Replace '3' with '5'
                    f = true;
                } else if (a == '5') {
                    strcat(sb, "7"); // Replace '5' with '7'
                    f = true;
                } else {
                    strcat(sb, "3"); // Replace other digits with '3'
                }
            }
        }
        if (!f) strcat(sb, "3"); // Append '3' if no replacements were made

        // Reverse the new number and convert it back to a long
        char sb2[20]; // Declare a character array to store the reversed new number
        strcpy(sb2, sb); // Copy the new number to the reversed new number
        int l = strlen(sb2); // Get the length of the reversed new number
        for (int j = 0; j < l / 2; j++) {
            char temp = sb2[j]; // Swap the characters in the reversed new number
            sb2[j] = sb2[l - 1 - j];
            sb2[l - 1 - j] = temp;
        }
        i = atol(sb2); // Convert the reversed new number back to a long
    }

    // Output the result
    printf("%d\n", c); // Print the count of valid numbers

    return 0; // Return 0 to indicate successful execution
}


Translate the above C code to Python and end with comment "