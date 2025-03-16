#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool debug = false;

void log(char *text) {
    if (debug) {
        printf("%s\n", text);
    }
}

// Function to parse input from either user input or a string
char* parse_input(char *lines_as_string) {
    static char lines[1000];
    if (lines_as_string == NULL) {
        debug = false;
        fgets(lines, sizeof(lines), stdin);
    } else {
        debug = true;
        strncpy(lines, lines_as_string, sizeof(lines));
    }
    char *c = strtok(lines, " ");
    return c;
}

// Function to solve the problem by finding the next character in the alphabet
char solve(char c) {
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    while (a[i] != '\0' && a[i] != c) {
        i++;
    }
    if (a[i] == '\0') {
        return '\0'; // Character not found
    }
    return a[i + 1];
}

// Main function to orchestrate the execution of the program
int main() {
    char *result;
    result = solve(*parse_input(NULL));
    if (result != NULL) {
        printf("%c\n", result);
    } else {
        printf("Character not found\n");
    }
    return 0;
}
