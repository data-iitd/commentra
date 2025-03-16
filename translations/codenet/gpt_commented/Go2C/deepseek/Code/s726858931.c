#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 1000 * 1024

char* readLine() {
    char* line = (char*)malloc(CAPACITY * sizeof(char));
    if (line == NULL) {
        perror("Unable to allocate buffer");
        exit(EXIT_FAILURE);
    }
    if (fgets(line, CAPACITY, stdin) == NULL) {
        free(line);
        return NULL;
    }
    return line;
}

void findMissingLowercaseLetter(const char* str) {
    int found[26] = {0}; // Array to keep track of found letters
    int len = strlen(str);

    // Mark the letters found in the input string
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            found[str[i] - 'a'] = 1;
        }
    }

    // Check for the first missing lowercase letter
    for (int i = 0; i < 26; i++) {
        if (found[i] == 0) {
            printf("%c\n", 'a' + i);
            return;
        }
    }

    // If all letters are found, print "None"
    printf("None\n");
}

int main() {
    char* input = readLine();
    if (input == NULL) {
        perror("Failed to read input");
        return EXIT_FAILURE;
    }

    findMissingLowercaseLetter(input);

    free(input);
    return 0;
}
