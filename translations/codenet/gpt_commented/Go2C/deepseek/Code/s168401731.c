#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 500001

char* getNextString() {
    static char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        char* pos = buffer;
        while (*pos != '\0' && (*pos == ' ' || *pos == '\n')) {
            pos++;
        }
        return pos;
    }
    return NULL;
}

int getNextInt() {
    char* str = getNextString();
    return atoi(str);
}

long long getNextInt64() {
    char* str = getNextString();
    return atoll(str);
}

unsigned long long getNextUint64() {
    char* str = getNextString();
    return strtoull(str, NULL, 10);
}

double getNextFloat64() {
    char* str = getNextString();
    return atof(str);
}

int main() {
    // Initialize file pointers for input and output.
    FILE* fp = stdin;
    FILE* wfp = stdout;

    // Check for command line arguments to open input and output files.
    if (argc > 1) {
        fp = fopen(argv[1], "r"); // Open input file if provided.
        if (argc > 2) {
            wfp = fopen(argv[2], "w"); // Create output file if provided.
        }
    }

    // Read the number of integers to process.
    int n = getNextInt();

    // Initialize the answer as "second" and check for odd integers.
    char ans[6] = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt(); // Read the next integer.
        if (a % 2 == 1) { // Check if the integer is odd.
            strcpy(ans, "first"); // If odd, set answer to "first".
            break; // Exit the loop early if an odd integer is found.
        }
    }

    // Write the result to the output.
    fprintf(wfp, "%s\n", ans);
    fflush(wfp); // Ensure all buffered data is written to the output.

    // Close files if they were opened.
    if (fp != stdin) {
        fclose(fp);
    }
    if (wfp != stdout) {
        fclose(wfp);
    }

    return 0;
}
