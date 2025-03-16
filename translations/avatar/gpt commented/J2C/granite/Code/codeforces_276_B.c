
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000];
    fgets(str, 1000, stdin); // Read a line of input from the user

    int map[256] = {0}; // Initialize an array to count occurrences of each character
    int oddCount = 0; // Initialize counter for characters with odd occurrences

    int i;
    for (i = 0; i < strlen(str); i++) {
        char ch = str[i];
        // Update the count of the character in the map
        map[ch]++;
    }

    for (i = 0; i < 256; i++) {
        if (map[i] % 2!= 0) {
            oddCount++;
        }
    }

    if (oddCount <= 1 || oddCount % 2!= 0) {
        printf("First"); // Output "First" if conditions are met
    } else {
        printf("Second"); // Output "Second" otherwise
    }

    return 0;
}
