#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000];
    int map[128] = {0}; // Array to count occurrences of each character
    int oddCount = 0; // Initialize counter for characters with odd occurrences

    // Read a line of input from the user
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(str); i++) {
        map[(int)str[i]]++;
    }

    // Count how many characters have an odd number of occurrences
    for (int i = 0; i < 128; i++) {
        if (map[i] % 2 != 0) {
            oddCount++;
        }
    }

    // Determine the output based on the count of odd occurrences
    if (oddCount <= 1 || oddCount % 2 != 0) {
        printf("First\n"); // Output "First" if conditions are met
    } else {
        printf("Second\n"); // Output "Second" otherwise
    }

    return 0;
}
