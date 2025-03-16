#include <stdio.h>

int main() {
    // Declare a character array to hold the input
    char s[1000];
    // Read the input string from standard input
    scanf("%s", s);

    // Initialize variables to track the maximum length of valid characters and the current length
    int max_tmp = 0;
    int max = 0;

    // Iterate over each character in the input string
    for (int i = 0; s[i] != '\0'; i++) {
        // Flag to indicate if a non-valid character is encountered
        int flag = 0;

        // Check if the current character is one of the valid DNA bases
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G') {
            // Increment the temporary count for valid characters
            max_tmp++;
        } else {
            // Set the flag to true if a non-valid character is found
            flag = 1;
        }

        // If a non-valid character was found or we reached the end of the string
        if (flag == 1 || s[i + 1] == '\0') {
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
