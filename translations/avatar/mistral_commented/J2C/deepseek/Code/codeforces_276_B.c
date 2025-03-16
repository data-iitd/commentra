#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000]; // Buffer to read input string
    int map[128] = {0}; // Array to store character counts
    int oddCount = 0; // Count of odd-valued character counts

    // Read the input string
    fgets(str, sizeof(str), stdin);

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i]; // Get the current character

        // Increment the count for the current character
        map[(int)ch]++;
    }

    // Iterate through each character count in the map
    for (int i = 0; i < 128; i++) {
        if (map[i] % 2 != 0) {
            oddCount++; // Increment the odd count
        }
    }

    // Determine the output based on the odd count
    if (oddCount <= 1 || oddCount % 2 != 0) {
        printf("First\n"); // Output "First" if the odd count is 1 or odd
    } else {
        printf("Second\n"); // Output "Second" if the odd count is even
    }

    return 0;
}
