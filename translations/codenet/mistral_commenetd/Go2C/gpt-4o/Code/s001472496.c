#include <stdio.h>
#include <string.h>

int main() {
    // Initialize an empty string variable to store the input string
    char s[100]; // Assuming a maximum length of 99 characters + 1 for null terminator

    // Read the input string from the standard input
    scanf("%s", s);

    // Initialize two integer variables max_tmp and max with zero values
    int max_tmp = 0;
    int max = 0;

    // Get the length of the input string
    int length = strlen(s);

    // Iterate through each character in the input string using a for loop
    for (int i = 0; i < length; i++) {
        // Initialize a boolean variable flag with false value
        int flag = 0;

        // Check the character type using if statement
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G') {
            // Increment the max_tmp variable by 1 for each valid character encountered
            max_tmp++;
        } else {
            // Set the flag variable to true if the character is not a valid nucleotide
            flag = 1;
        }

        // Check if the current character is the last character in the input string
        if (i == length - 1) {
            // Set the flag variable to true if the current character is the last character
            flag = 1;
        }

        // If the flag variable is true, then the current character is not a valid nucleotide
        // So, we need to check if the max variable is less than the max_tmp value
        // If yes, then update the max variable with the max_tmp value
        if (flag == 1) {
            if (max < max_tmp) {
                max = max_tmp;
            }
            // Reset the max_tmp variable to zero as we have processed the current sequence of valid nucleotides
            max_tmp = 0;
        }
    }

    // Print the maximum length of a valid sequence of nucleotides found in the input string
    printf("%d\n", max);

    // End of the code
    return 0;
}
