
#include <stdio.h>
#include <stdlib.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for large inputs.
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL);
    return fp;
}

// getNextString retrieves the next string from the scanner.
char *getNextString(FILE *scanner) {
    char str[500001];
    fscanf(scanner, "%s", str);
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

int main() {
    // Determine the input source: standard input or a file specified as a command-line argument.
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    // Initialize the scanner for reading input.
    FILE *scanner = getScanner(fp);

    // Create a buffered writer for output.
    setbuf(stdout, NULL);

    // Read the number of elements from the input.
    int n = getNextInt(scanner);

    // Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
    int aa[n+2];
    int sum = 0;

    // Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
    for (int i = 0; i < n; i++) {
        aa[i+1] = getNextInt(scanner);
        sum += abs(aa[i+1] - aa[i]);
    }
    // Include the difference between the last element and the element before it.
    sum += abs(aa[n+1] - aa[n]);

    // Calculate and print the result for each element.
    for (int i = 1; i < n+1; i++) {
        // Calculate the new sum of absolute differences if the i-th element is removed.
        int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
        printf("%d\n", ans); // Output the result for the current element.
    }

    // Flush the buffered writer to ensure all output is written.
    fflush(stdout);
}

// abs returns the absolute value of an integer.
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

