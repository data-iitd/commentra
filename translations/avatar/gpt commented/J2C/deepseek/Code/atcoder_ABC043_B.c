#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a string from input
char* readString() {
    char* buffer = NULL;
    size_t size = 0;
    if (getline(&buffer, &size, stdin) == -1) {
        free(buffer);
        exit(EXIT_FAILURE);
    }
    return buffer;
}

// Function to solve the B Unhappy Hacking problem
void solve(const char* s) {
    char* d = (char*)malloc(strlen(s) + 1);
    if (!d) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int d_index = 0;

    for (const char* p = s; *p; ++p) {
        switch (*p) {
            case '0':
                d[d_index++] = '0';
                break;
            case '1':
                d[d_index++] = '1';
                break;
            case 'B':
                if (d_index > 0) {
                    --d_index;
                }
                break;
        }
    }
    d[d_index] = '\0';
    printf("%s\n", d);
    free(d);
}

int main() {
    // Read the input string
    char* s = readString();
    // Solve the problem
    solve(s);
    // Free the allocated memory for the input string
    free(s);
    return 0;
}
