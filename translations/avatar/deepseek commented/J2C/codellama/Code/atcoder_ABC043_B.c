
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000000

// Step 1: Define the input stream and output stream
FILE *inputStream = stdin;
FILE *outputStream = stdout;

// Step 2: Create a LightScanner instance for reading input efficiently
char inputBuffer[MAX_INPUT_LENGTH];
int inputBufferIndex = 0;
int inputBufferLength = 0;

char *readInput() {
    char *token = NULL;
    if (inputBufferIndex == inputBufferLength) {
        inputBufferIndex = 0;
        inputBufferLength = fread(inputBuffer, sizeof(char), MAX_INPUT_LENGTH, inputStream);
        if (inputBufferLength == 0) {
            return NULL;
        }
    }
    token = &inputBuffer[inputBufferIndex];
    inputBufferIndex++;
    return token;
}

// Step 3: Create a PrintWriter instance for writing output
FILE *outputFile = outputStream;

// Step 4: Create an instance of the problem solver
void solve(int testNumber, char *inputString) {
    // Read the input string
    char *s = inputString;
    
    // StringBuilder to build the result
    char *d = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    d[0] = '\0';
    
    // Iterate over each character in the input string
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '0':
                // Append '0' to the result
                strcat(d, "0");
                break;
            case '1':
                // Append '1' to the result
                strcat(d, "1");
                break;
            case 'B':
                // Remove the last character if the result is not empty
                if (strlen(d) > 0) {
                    d[strlen(d) - 1] = '\0';
                }
                break;
        }
    }
    
    // Print the result
    fprintf(outputFile, "%s\n", d);
    
    // Free the memory
    free(d);
}

int main() {
    // Step 5: Solve the problem
    solve(1, readInput());
    
    // Close the output writer
    fclose(outputFile);
    
    return 0;
}

// 