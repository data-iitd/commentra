#include <stdio.h>
#include <string.h>

int main() {
    // Initialize an empty string to store the input string
    char s[100];

    // Read the input string from the standard input using scanf() function
    scanf("%s", s);

    // Initialize two integer variables max_tmp and max with zero values
    int max_tmp = 0;
    int max = 0;

    // Iterate through each character in the input string using a for loop
    for (int i = 0; i < strlen(s); i++) {
        // Initialize a boolean variable flag with false value
        int flag = 0;

        // Check the character type using switch statement
        switch (s[i]) {
            case 'A':
            case 'C':
            case 'T':
            case 'G':
                // Increment the max_tmp variable by 1 for each valid character encountered
                max_tmp++;
                break;
            default:
                // Set the flag variable to true if the character is not a valid nucleotide
                flag = 1;
                break;
        }

        // Check if the current character is the last character in the input string
        if (i == strlen(s) - 1) {
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
