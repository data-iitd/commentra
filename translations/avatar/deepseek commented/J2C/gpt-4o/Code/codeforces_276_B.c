#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int main() {
    // Set up input and output streams
    char str[1000]; // Assuming the input string will not exceed 999 characters
    int freq[MAX_CHAR] = {0}; // Frequency array for characters
    int oddCount = 0;

    // Read the input string from the user
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character if present

    // Iterate through the input string to populate the frequency array
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        freq[(unsigned char)ch]++;
    }

    // Iterate through the frequency array to count characters with odd frequencies
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    // Determine the winner based on the count of characters with odd frequencies
    if (oddCount <= 1 || oddCount % 2 != 0) {
        printf("First\n");
    } else {
        printf("Second\n");
    }

    return 0;
}

// <END-OF-CODE>
