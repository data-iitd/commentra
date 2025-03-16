#include <stdio.h>  // Standard input/output library
#include <string.h> // String manipulation functions

// Function to solve the problem
void solve() {
    char s[100001]; // Array to hold the input string (assuming max length of 100000)
    scanf("%s", s); // Read the input string

    // Replace all occurrences of "BC" with "D"
    char temp[100001]; // Temporary array to hold the modified string
    int j = 0; // Index for the temp array

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'B' && s[i + 1] == 'C') {
            // If "BC" is found, replace it with "D"
            temp[j++] = 'D';
            i++; // Skip the next character as it's part of "BC"
        } else {
            // Otherwise, copy the character as is
            temp[j++] = s[i];
        }
    }
    temp[j] = '\0'; // Null-terminate the modified string

    long cnt = 0; // Initialize counter for the number of "D"s
    long tmp = 0; // Initialize temporary variable for counting consecutive "A"s

    // Loop through each character in the modified string
    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == 'A') {
            // If the character is "A", increment the temporary counter
            tmp++;
        } else if (temp[i] == 'D') {
            // If the character is "D", add the temporary counter to the total count
            cnt += tmp;
        } else {
            // If the character is neither "A" nor "D", reset the temporary counter
            tmp = 0;
        }
    }

    // Print the result
    printf("%ld\n", cnt);
}

// Main function that starts the program
int main() {
    solve(); // Call the solve function
    return 0; // Return success
}

// <END-OF-CODE>
