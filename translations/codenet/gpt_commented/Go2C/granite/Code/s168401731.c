
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner for the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer size.
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL);
    return fp;
}

// getNextString retrieves the next string from the scanner.
char *getNextString(FILE *scanner) {
    int c = getc(scanner);
    char *str = (char *)malloc(sizeof(char) * 500001);
    int i = 0;
    while (c!= EOF && c!='' && c!= '\n') {
        str[i++] = c;
        c = getc(scanner);
    }
    str[i] = '\0';
    return str;
}

// getNextInt converts the next string from the scanner to an integer.
int getNextInt(FILE *scanner) {
    char *str = getNextString(scanner);
    int i = 0;
    int result = 0;
    while (str[i]!= '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    free(str);
    return result;
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
long long getNextInt64(FILE *scanner) {
    char *str = getNextString(scanner);
    int i = 0;
    long long result = 0;
    while (str[i]!= '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    free(str);
    return result;
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
unsigned long long getNextUint64(FILE *scanner) {
    char *str = getNextString(scanner);
    int i = 0;
    unsigned long long result = 0;
    while (str[i]!= '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    free(str);
    return result;
}

// getNextFloat64 converts the next string from the scanner to a float64.
double getNextFloat64(FILE *scanner) {
    char *str = getNextString(scanner);
    double result = atof(str);
    free(str);
    return result;
}

int main() {
    // Initialize file pointers for input and output.
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Check for command line arguments to open input and output files.
    if (argc > 1) {
        fp = fopen(argv[1], "r"); // Open input file if provided.
        if (argc > 2) {
            wfp = fopen(argv[2], "w"); // Create output file if provided.
        }
    }

    // Create a scanner for reading input and a writer for output.
    FILE *scanner = getScanner(fp);
    setbuf(wfp, NULL);

    // Read the number of integers to process.
    int n = getNextInt(scanner);

    // Initialize the answer as "second" and check for odd integers.
    char *ans = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt(scanner); // Read the next integer.
        if (a % 2 == 1) { // Check if the integer is odd.
            ans = "first"; // If odd, set answer to "first".
            break; // Exit the loop early if an odd integer is found.
        }
    }

    // Write the result to the output.
    fprintf(wfp, "%s\n", ans);
    fflush(wfp); // Ensure all buffered data is written to the output.

    return 0;
}
