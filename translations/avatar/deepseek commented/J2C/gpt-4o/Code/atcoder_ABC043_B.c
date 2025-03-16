#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

void solve(const char *s) {
    char result[MAX_LENGTH];
    int length = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        switch (c) {
            case '0':
                result[length++] = '0';
                break;
            case '1':
                result[length++] = '1';
                break;
            case 'B':
                if (length > 0) {
                    length--; // Remove the last character
                }
                break;
        }
    }

    // Null-terminate the result string
    result[length] = '\0';
    printf("%s\n", result);
}

int main() {
    // Read the input string
    char input[MAX_LENGTH];
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character from the input if present
    input[strcspn(input, "\n")] = 0;

    // Solve the problem
    solve(input);

    return 0;
}

// <END-OF-CODE>
