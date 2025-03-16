

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000]; // String to read from input
    int map[256] = {0}; // Map to store character counts
    int oddCount = 0; // Count of odd-valued character counts

    // Read the first line of input
    fgets(str, sizeof(str), stdin);

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i]; // Get the current character

        // If the character is already in the map, increment its count
        if (map[ch] > 0) {
            map[ch]++;
        } else {
            // Otherwise, add the character to the map with a count of 1
            map[ch] = 1;
        }
    }

    // Iterate through each entry in the map and count odd-valued entries
    for (int i = 0; i < 256; i++) {
        if (map[i] % 2!= 0) {
            oddCount++; // Increment the odd count
        }
    }

    // Determine the output based on the odd count
    if (oddCount <= 1 || oddCount % 2!= 0) {
        printf("First\n"); // Output "First" if the odd count is 1 or odd
    } else {
        printf("Second\n"); // Output "Second" if the odd count is even
    }

    return 0;
}

