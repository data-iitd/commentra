#include <stdio.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000 // Initial buffer size for reading input
#define MAX_BUF_SIZE 100000000 // Maximum buffer size for the scanner

// Function to read the next word from input
char* next() {
    static char buf[MAX_BUF_SIZE];
    static int pos = 0;
    char* token;

    // Read the next line from stdin
    fgets(buf, MAX_BUF_SIZE, stdin);

    // Find the first non-space character
    while (buf[pos] == ' ' || buf[pos] == '\n' || buf[pos] == '\t') {
        pos++;
    }

    // Tokenize the line to get the next word
    token = &buf[pos];

    // Find the end of the word
    while (buf[pos] != ' ' && buf[pos] != '\n' && buf[pos] != '\t' && buf[pos] != '\0') {
        pos++;
    }

    // Null-terminate the word
    buf[pos] = '\0';

    return token;
}

// Function to return the minimum of two integers
int min(int x, int y) {
    return x < y ? x : y;
}

// Main function where the program execution begins
int main() {
    char S[MAX_BUF_SIZE];
    int l0 = 0, l1 = 0;

    // Read the input string
    strcpy(S, next());

    // Loop through each character in the input string
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '0') {
            l0++; // Increment the counter for '0'
        } else {
            l1++; // Increment the counter for '1'
        }
    }

    // Print the result, which is twice the minimum count of '0's or '1's
    printf("%d\n", 2 * min(l0, l1));

    return 0;
}
