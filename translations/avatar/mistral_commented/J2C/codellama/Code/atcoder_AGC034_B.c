
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Main method that starts the program

    char *s = malloc(1000000 * sizeof(char)); // Allocate memory for the input string
    scanf("%s", s); // Read the input string

    long cnt = 0; // Initialize counter for the number of "D"s
    long tmp = 0; // Initialize temporary variable for counting consecutive "A"s

    for (int i = 0; i < strlen(s); i++) {
        // Loop through each character in the string

        if (s[i] == 'A') {
            // If the character is "A", increment the temporary counter
            tmp++;
        } else if (s[i] == 'D') {
            // If the character is "D", add the temporary counter to the total count
            cnt += tmp;
        } else {
            // If the character is neither "A" nor "D", reset the temporary counter
            tmp = 0;
        }
    }

    // Print the result
    printf("%ld\n", cnt);

    free(s); // Free the memory allocated for the input string

    return 0;
}

