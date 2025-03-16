#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a specified number of lines from input
char** read(int len) {
    char** strList = (char**)malloc(len * sizeof(char*));
    for (int i = 0; i < len; i++) {
        strList[i] = (char*)malloc(100 * sizeof(char)); // Allocate memory for each line
        if (scanf("%99s", strList[i]) != 1) { // Read a line from input
            perror("Failed to read input");
            exit(EXIT_FAILURE);
        }
    }
    return strList;
}

int main() {
    // Read the first input as an integer
    int n;
    if (scanf("%d", &n) != 1) {
        perror("Failed to read input");
        return EXIT_FAILURE;
    }

    // Check if the input is 1
    if (n == 1) {
        // If the input is 1, print "Hello World"
        printf("Hello World\n");
    } else {
        // If the input is not 1, read two more strings
        char** strs = read(2);
        // Parse the two strings as integers and print their sum
        int sum = atoi(strs[0]) + atoi(strs[1]);
        printf("%d\n", sum);

        // Free allocated memory
        for (int i = 0; i < 2; i++) {
            free(strs[i]);
        }
        free(strs);
    }

    return EXIT_SUCCESS;
}
