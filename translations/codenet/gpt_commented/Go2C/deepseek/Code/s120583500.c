#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable to hold the input string
    char s[1000];
    // Read input from the user
    fgets(s, sizeof(s), stdin);

    // Initialize a counter for consecutive valid characters and a array to hold counts
    int count = 0;
    int counter[1000] = {0};
    int counterIndex = 0;

    // If the input string is empty, exit the function
    if (strlen(s) <= 1) {
        return 0;
    }

    // Iterate over each character in the string
    for (int i = 0; i < strlen(s); i++) {
        // Check if the character is one of the valid DNA bases
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            // Increment the count for consecutive valid characters
            count++;
        } else {
            // If an invalid character is encountered, store the current count
            counter[counterIndex++] = count;
            // Reset the count for the next sequence
            count = 0;
        }
    }

    // Append the count of the last sequence of valid characters
    counter[counterIndex++] = count;

    // Find the maximum count of consecutive valid characters
    int maxCount = 0;
    for (int i = 0; i < counterIndex; i++) {
        if (counter[i] > maxCount) {
            maxCount = counter[i];
        }
    }

    // Print the maximum count of consecutive valid characters
    printf("%d\n", maxCount);

    return 0;
}
