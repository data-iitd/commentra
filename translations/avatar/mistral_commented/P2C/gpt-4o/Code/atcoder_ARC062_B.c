#include <stdio.h>
#include <string.h>

int main() {
    // Initialize an empty array to store input characters
    char s[100]; // Assuming a maximum length of 100 for the input
    fgets(s, sizeof(s), stdin); // Read input from the user

    // Initialize counters for 'g' and 'p' symbols
    int num_g = 0, num_p = 0;

    // Initialize score variable
    int score = 0;

    // Iterate through each character in the array 's'
    for (int i = 0; i < strlen(s); i++) {
        char x = s[i];

        // Check if current character is 'g'
        if (x == 'g') {
            // Check if number of 'g' symbols is greater than number of 'p' symbols
            if (num_g - num_p > 0) {
                // Increment score and number of 'p' symbols
                score += 1;
                num_p += 1;
                // Comment: If there are more 'g' symbols than 'p' symbols, increment score and update number of 'p' symbols
            } else {
                // Do not change score and increment number of 'g' symbols
                num_g += 1;
                // Comment: If there are less or equal 'g' symbols than 'p' symbols, do not change score and update number of 'g' symbols
            }
        }
        // Check if current character is 'p'
        else if (x == 'p') {
            // Check if number of 'g' symbols is greater than number of 'p' symbols
            if (num_g - num_p > 0) {
                // Do not change score and increment number of 'p' symbols
                num_p += 1;
                // Comment: If there are more 'g' symbols than 'p' symbols, do not change score and update number of 'p' symbols
            } else {
                // Decrement score and increment number of 'g' symbols
                score -= 1;
                num_g += 1;
                // Comment: If there are less or equal 'g' symbols than 'p' symbols, decrement score and update number of 'g' symbols
            }
        }
    }

    // Print the final score
    printf("%d\n", score);
    // Comment: After iterating through all characters in the array 's', print the final score

    return 0;
}

// <END-OF-CODE>
