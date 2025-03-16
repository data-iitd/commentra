#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000001

char inputBuffer[MAX_INPUT_SIZE];
int bufferIndex = 0;

void initScanner() {
    fread(inputBuffer, 1, MAX_INPUT_SIZE, stdin);
}

char* nextStr() {
    char* token = strtok(inputBuffer + bufferIndex, " \n");
    if (token == NULL) {
        return NULL;
    }
    bufferIndex += strlen(token) + 1;
    return token;
}

int nextInt() {
    char* str = nextStr();
    if (str == NULL) {
        return -1; // Error or end of input
    }
    return atoi(str);
}

// Main function to read input and process it
int main() {
    initScanner();

    // Read the number of test cases
    int n = nextInt();

    // Initialize variables for processing the input
    int ans = 0;
    int aPrev = 0;

    // Process each test case
    for (int i = 0; i < n; i++) {
        // Read the next integer as 'a'
        int a = nextInt();

        // Check if 'a' is valid based on the conditions in the problem statement
        if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
            printf("-1\n");
            return 0;
        }
        if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
            ans++;
        } else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
            ans += a;
        }

        // Update the previous number
        aPrev = a;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}
