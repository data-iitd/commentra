
#include <stdio.h>
#include <stdlib.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for larger inputs.
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL);
    return fp;
}

// getNextString retrieves the next string from the scanner.
char *getNextString(FILE *scanner) {
    char str[500001];
    fgets(str, 500001, scanner);
    return str;
}

// getNextInt converts the next string from the scanner to an integer.
int getNextInt(FILE *scanner) {
    int i;
    fscanf(scanner, "%d", &i);
    return i;
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
long long getNextInt64(FILE *scanner) {
    long long i;
    fscanf(scanner, "%lld", &i);
    return i;
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
unsigned long long getNextUint64(FILE *scanner) {
    unsigned long long i;
    fscanf(scanner, "%llu", &i);
    return i;
}

// getNextFloat64 converts the next string from the scanner to a float64.
double getNextFloat64(FILE *scanner) {
    double i;
    fscanf(scanner, "%lf", &i);
    return i;
}

int main() {
    // Initialize file pointers for input and output.
    FILE *fp = stdin;
    FILE *wfp = stdout;
    int cnt = 0;

    // Check for environment variables to determine input and output files.
    if (getenv("MASPY")) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        cnt = 2; // Set the count for additional processing.
    }
    if (getenv("MASPYPY")) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    // Create a scanner for reading input and a writer for output.
    FILE *scanner = getScanner(fp);
    FILE *writer = getScanner(wfp);

    // Solve the problem for the first time.
    solve(scanner, writer);

    // If cnt is greater than 0, solve the problem additional times.
    for (int i = 0; i < cnt; i++) {
        fprintf(writer, "-----------------------------------\n");
        solve(scanner, writer);
    }

    // Flush the writer to ensure all output is written.
    fflush(writer);
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
void solve(FILE *scanner, FILE *writer) {
    int k = getNextInt(scanner); // Read the first integer k.
    int x = getNextInt(scanner); // Read the second integer x.

    char *ans = "No"; // Default answer is "No".
    if (k * 500 >= x) { // Check the condition.
        ans = "Yes"; // Update answer to "Yes" if condition is met.
    }
    fprintf(writer, "%s\n", ans); // Output the result.
}
