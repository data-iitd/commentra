
// Constants and package imports
#include <stdio.h>
#include <stdlib.h>

const int mod = 1000000007;
// 1MB
const int ioBufferSize = 1 * 1024 * 1024;

// Helper function to read input
char inputBuffer[ioBufferSize];
int inputBufferIndex = 0, inputBufferLength = 0;

char nextChar() {
    if (inputBufferIndex >= inputBufferLength) {
        inputBufferLength = fread(inputBuffer, sizeof(char), ioBufferSize, stdin);
        inputBufferIndex = 0;
    }
    return inputBuffer[inputBufferIndex++];
}

void nextWord(char *word) {
    int letterIndex = 0;
    char c;
    while (true) {
        c = nextChar();
        if (c =='' || c == '\n' || c == '\t' || c == '\r') {
            if (letterIndex == 0) {
                continue;
            } else {
                break;
            }
        }
        word[letterIndex++] = c;
    }
    word[letterIndex] = '\0';
}

int nextInt() {
    char word[10];
    nextWord(word);
    return atoi(word);
}

int main() {
    // Reading the first two integers h and n
    int h = nextInt(), n = nextInt();

    // Initializing variable a to 0
    int a = 0;

    // Iterating through the array of size n and adding each integer to variable a
    for (int i = 0; i < n; i++) {
        a += nextInt();
    }

    // Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
}

