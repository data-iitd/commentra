#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Set up input and output streams
    char str[1000];
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    // Create an array to count the frequency of each character in the input string
    int map[128] = {0};

    // Initialize a counter for characters with odd frequencies
    int oddCount = 0;

    // Iterate through the input string to populate the frequency map
    for (int i = 0; i < strlen(str); i++) {
        map[(int)str[i]]++;
    }

    // Iterate through the map to count characters with odd frequencies
    for (int i = 0; i < 128; i++) {
        if (map[i] % 2 != 0) {
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
