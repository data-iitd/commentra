

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new bufio.Scanner from a file pointer
FILE *getScanner(FILE *fp) {
    setvbuf(fp, NULL, _IOFBF, 500001); // Buffer size for efficient reading
    return fp;
}

// Function to read the next string from the scanner
char *getNextString(FILE *scanner) {
    char *str = malloc(500001 * sizeof(char));
    fscanf(scanner, "%s", str);
    return str;
}

// Function to read the next integer from the scanner
int getNextInt(FILE *scanner) {
    int num;
    fscanf(scanner, "%d", &num);
    return num;
}

// Function to read the next int64 from the scanner
long long getNextInt64(FILE *scanner) {
    long long num;
    fscanf(scanner, "%lld", &num);
    return num;
}

int main() {
    // Open the standard input as a file
    FILE *fp = stdin;
    // If there is an argument, open the file with that name instead
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    // Create a new bufio.Scanner from the file pointer
    FILE *scanner = getScanner(fp);

    // Create a new bufio.Writer for output
    FILE *writer = stdout;

    // Read the first integer from the input
    int n = getNextInt(scanner);

    // Initialize an array 'aa' of size 'n+2'
    int *aa = malloc((n + 2) * sizeof(int));
    // Initialize a variable'sum' to store the sum of absolute differences between consecutive elements
    int sum = 0;

    // Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
    for (int i = 0; i < n; i++) {
        // Read the next integer from the scanner and store it in 'aa[i+1]'
        aa[i + 1] = getNextInt(scanner);
        // Calculate the absolute difference between the current and previous elements and add it to the sum
        sum += abs(aa[i + 1] - aa[i]);
    }
    // Calculate the absolute difference between the last two elements and add it to the sum
    sum += abs(aa[n + 1] - aa[n]);

    // Iterate through the array 'aa' and print the answer for each subarray
    for (int i = 1; i < n + 1; i++) {
        // Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
        int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
        // Write the answer to the output writer
        fprintf(writer, "%d\n", ans);
    }

    // Flush the buffer to write all the data to the output
    fflush(writer);
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

