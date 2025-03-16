#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN 100000

// Function to read input more efficiently
char* readLine() {
    char* line = (char*)malloc(MAX_LEN * sizeof(char));
    if (line == NULL) {
        perror("Unable to allocate buffer");
        exit(EXIT_FAILURE);
    }
    if (!fgets(line, MAX_LEN, stdin)) {
        free(line);
        return NULL;
    }
    // Remove newline character if present
    line[strcspn(line, "\n")] = '\0';
    return line;
}

// Main function to execute the program
int main() {
    char s[MAX_LEN];
    int k;
    int l = 0;

    // Read the input string
    fgets(s, MAX_LEN, stdin);
    // Read the integer k
    scanf("%d", &k);

    // Loop through each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '1') {
            break;
        }
        l++;
    }

    if (l >= k) {
        return 1;
    }
    return s[l] - '0';
}
