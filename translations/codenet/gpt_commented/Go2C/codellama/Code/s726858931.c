#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000000

int main() {
    char *buffer = (char *)malloc(MAX_BUFFER_SIZE);
    char *token = NULL;
    char *input = NULL;
    char *output = NULL;
    int i = 0;
    int j = 0;
    int c = 'a';
    int found = 0;

    // Read the input string
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    input = strtok(buffer, " ");

    // Start checking for the first missing lowercase letter from 'a'
    c = 'a';

    // Loop through all lowercase letters from 'a' to 'z'
    for (j = 0; j < 26; j++) {
        found = 0; // Flag to check if the current letter is found in the input string
        // Check if the current letter exists in the input string
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == c) {
                found = 1; // Set the flag to true if the letter is found
                break;
            }
        }
        // If the letter was not found, print it and exit
        if (found == 0) {
            printf("%c\n", c);
            return 0;
        }
        c++; // Move to the next letter
    }

    // If all letters from 'a' to 'z' are found, print "None"
    printf("None\n");

    return 0;
}

