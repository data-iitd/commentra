#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 500001

// Function to read the next word from the input.
char* getNextString() {
    static char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        // Remove newline character if present.
        buffer[strcspn(buffer, "\n")] = '\0';
        return buffer;
    }
    return NULL;
}

// Function to read the next word, convert it to an integer, and return it.
int getNextInt() {
    char* str = getNextString();
    return atoi(str);
}

// Function to read the next word, convert it to an int64_t, and return it.
int64_t getNextInt64() {
    char* str = getNextString();
    return atoll(str);
}

// Function to read the next word, convert it to a uint64_t, and return it.
uint64_t getNextUint64() {
    char* str = getNextString();
    return strtoull(str, NULL, 10);
}

// Function to read the next word, convert it to a float64_t, and return it.
double getNextFloat64() {
    char* str = getNextString();
    return atof(str);
}

// Main function handles file input/output operations based on command-line arguments.
int main(int argc, char* argv[]) {
    FILE* fp = stdin;
    FILE* wfp = stdout;

    // Check if command-line arguments are provided for file input/output.
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, fp);
    int n = atoi(buffer);

    // Initialize the answer to "second".
    char ans[6] = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt();
        if (a % 2 == 1) {
            strcpy(ans, "first");
            break;
        }
    }
    // Print the result based on the condition.
    fprintf(wfp, "%s\n", ans);
    fclose(fp);
    fclose(wfp);
    return 0;
}
