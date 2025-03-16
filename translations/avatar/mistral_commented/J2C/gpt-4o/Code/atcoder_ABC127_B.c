#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// Function to read a line of input
char* readLine() {
    char* buffer = (char*)malloc(BUFFER_SIZE);
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

// Function to convert string to integer
int stringToInt(char* str) {
    return atoi(str);
}

// Function to convert string to long
long stringToLong(char* str) {
    return atol(str);
}

int main() {
    // Variables for input
    int r, d;
    long x;

    // Reading input variables from the user
    char* input = readLine();
    sscanf(input, "%d %d %ld", &r, &d, &x);
    free(input);

    // Running the loop for 10 iterations
    for (int i = 0; i < 10; ++i) {
        // Multiplying 'r' with 'x' and subtracting 'd' from it
        x = r * x - d;

        // Writing the result to the output stream
        printf("%ld\n", x);
    }

    return 0;
}

// <END-OF-CODE>
