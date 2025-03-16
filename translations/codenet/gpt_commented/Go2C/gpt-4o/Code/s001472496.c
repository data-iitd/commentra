#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable to hold the input
    char s[1000]; // Assuming a maximum length of 999 characters + 1 for null terminator
    // Read the input string from standard input
    scanf("%s", s);

    // Initialize variables to track the maximum length of valid characters and the current length
    int max_tmp = 0;
    int max = 0;

<<<<<<< HEAD
    // Get the length of the input string
    int len = strlen(s);

    // Iterate over each character in the input string
    for (int i = 0; i < len; i++) {
=======
    // Iterate over each character in the input string
    for (int i = 0; i < strlen(s); i++) {
>>>>>>> 98c87cb78a (data updated)
        // Flag to indicate if a non-valid character is encountered
        int flag = 0;

        // Check if the current character is one of the valid DNA bases
        switch (s[i]) {
            case 'A':
            case 'C':
            case 'T':
            case 'G':
                // Increment the temporary count for valid characters
                max_tmp++;
                break;
            default:
                // Set the flag to true if a non-valid character is found
                flag = 1;
                break;
        }

        // Check if we are at the last character of the string
<<<<<<< HEAD
        if (i == len - 1) {
=======
        if (i == strlen(s) - 1) {
>>>>>>> 98c87cb78a (data updated)
            // Set the flag to true to handle the end of the string
            flag = 1;
        }

        // If a non-valid character was found or we reached the end of the string
        if (flag == 1) {
            // Update the maximum length if the current temporary length is greater
            if (max < max_tmp) {
                max = max_tmp;
            }
            // Reset the temporary length counter
            max_tmp = 0;
        }
    }

    // Print the maximum length of consecutive valid characters found
    printf("%d\n", max);

    return 0;
}

// <END-OF-CODE>
