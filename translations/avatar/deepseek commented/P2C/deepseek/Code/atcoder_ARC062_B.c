#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[1000];  // Declare a character array to store the input string
    int num_g = 0, num_p = 0;  // Initialize counters for 'g' and 'p' characters
    int score = 0;  // Initialize the score variable to 0

    // Read the input string
    fgets(s, sizeof(s), stdin);

    // Iterate over each character in the string
    for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        if (s[i] == 'g') {
            // Check if the number of 'g' characters exceeds the number of 'p' characters
            if (num_g - num_p > 0) {
                score += 1;  // Increment the score and the count of 'p' characters
                num_p += 1;
            } else {
                score = score;  // Keep the score unchanged and increment the count of 'g' characters
                num_g += 1;
            }
        } else if (s[i] == 'p') {
            // Check if the number of 'g' characters exceeds the number of 'p' characters
            if (num_g - num_p > 0) {
                score = score;  // Keep the score unchanged and increment the count of 'p' characters
                num_p += 1;
            } else {
                score -= 1;  // Decrement the score and increment the count of 'g' characters
                num_g += 1;
            }
        }
    }

    printf("%d\n", score);  // Print the final score
    return 0;
}
