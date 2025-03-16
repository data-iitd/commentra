
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialize input and output streams
    FILE *inputStreamReader = stdin;
    FILE *bufferedReader = stdin;
    FILE *writer = stdout;

    char *str;                 // String to read from input
    int *map;                  // Map to store character counts
    int oddCount;              // Count of odd-valued character counts

    try {
        // Read the first line of input
        str = (char *)malloc(sizeof(char) * 100);
        fgets(str, 100, bufferedReader);

        // Initialize the map to store character counts
        map = (int *)malloc(sizeof(int) * 100);

        // Iterate through each character in the input string
        for (int i = 0; i < strlen(str); i++) {
            char ch = str[i]; // Get the current character

            // If the character is already in the map, increment its count
            if (map[ch] != 0) {
                map[ch]++;
            } else {
                // Otherwise, add the character to the map with a count of 1
                map[ch] = 1;
            }
        }

        // Iterate through each entry in the map and count odd-valued entries
        for (int i = 0; i < strlen(str); i++) {
            if (map[i] % 2 != 0) {
                oddCount++; // Increment the odd count
            }
        }

        // Determine the output based on the odd count
        if (oddCount <= 1 || oddCount % 2 != 0) {
            fprintf(writer, "First\n"); // Output "First" if the odd count is 1 or odd
        } else {
            fprintf(writer, "Second\n"); // Output "Second" if the odd count is even
        }

        // Flush the output buffer to write the output to the console
        fflush(writer);

    } finally {
        // Close the input and output streams
        fclose(bufferedReader);
        fclose(inputStreamReader);
        fclose(writer);
    }

    return 0;
}

