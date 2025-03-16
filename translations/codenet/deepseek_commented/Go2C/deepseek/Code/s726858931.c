#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000 * 1024

char* readString() {
    char* s = (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
    if (s == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    fgets(s, MAX_INPUT_SIZE, stdin);
    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';
    return s;
}

void findMissingCharacter(const char* s) {
    int alphabet[26] = {0};
    int i;

    // Mark characters present in the string
    for (i = 0; i < strlen(s); i++) {
        alphabet[s[i] - 'a'] = 1;
    }

    // Check for the first missing character
    for (i = 0; i < 26; i++) {
        if (alphabet[i] == 0) {
            printf("%c\n", 'a' + i);
            return;
        }
    }

    // If no missing character is found, print "None"
    printf("None\n");
}

int main() {
    char* s = readString();
    findMissingCharacter(s);
    free(s);
    return 0;
}

