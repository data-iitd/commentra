#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    int dt[256] = {0}; // Array to count occurrences of each character (ASCII range)
    int cnt = 0;
    int odd_count = 0;

    // Read input
    fgets(s, sizeof(s), stdin);
    int length = strlen(s);
    
    // Count occurrences of each character
    for (int i = 0; i < length; i++) {
        if (s[i] != '\n') { // Ignore the newline character
            dt[(unsigned char)s[i]]++; // Increment the count for the character
        }
    }

    // Check the counts of each character to determine the number of odd occurrences
    for (int i = 0; i < 256; i++) {
        if (dt[i] % 2 != 0) {
            odd_count++;
        }
    }

    // Determine the output based on the number of odd occurrences and the length of the input
    if (odd_count <= 1) {
        printf("First\n"); // If there are no more than one odd occurrences
    } else if (odd_count > 1 && length % 2 == 0) {
        printf("Second\n"); // If there are more than one odd occurrences and the length is even
    } else {
        printf("First\n"); // If there are more than one odd occurrences and the length is odd
    }

    return 0;
}

// <END-OF-CODE>
