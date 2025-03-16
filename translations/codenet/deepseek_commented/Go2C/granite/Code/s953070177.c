
#include <stdio.h>
#include <stdlib.h>

// getScanner initializes a new bufio.Scanner to read from a file.
// It sets the split function to bufio.ScanWords to read words,
// and it also sets a buffer size.
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL);
    return fp;
}

// getNextString reads the next word from the scanner and returns it as a string.
char *getNextString(FILE *fp) {
    char word[500001];
    fscanf(fp, "%s", word);
    return word;
}

// getNextInt reads the next word from the scanner, converts it to an integer,
// and returns it.
int getNextInt(FILE *fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}

// getNextInt64 reads the next word from the scanner, converts it to an int64,
// and returns it.
long long getNextInt64(FILE *fp) {
    long long i;
    fscanf(fp, "%lld", &i);
    return i;
}

// main is the entry point of the program.
// It first checks if a file name is provided as an argument,
// and if so, it opens that file for reading.
// It then initializes a scanner and a writer.
int main(int argc, char **argv) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    FILE *writer = stdout;

    // Read the number of elements.
    int n = getNextInt(fp);

    // Initialize a slice to store the elements and a sum variable.
    int *aa = (int *)malloc(sizeof(int) * (n + 2));
    int sum = 0;

    // Read the elements into the slice and calculate the sum of absolute differences.
    for (int i = 0; i < n; i++) {
        aa[i + 1] = getNextInt(fp);
        sum += absint(aa[i + 1] - aa[i]);
    }
    sum += absint(aa[n + 1] - aa[n]);

    // Calculate and print the differences for each element.
    for (int i = 1; i < n + 1; i++) {
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        fprintf(writer, "%d\n", ans);
    }

    // Flush the writer to ensure all output is written to the output stream.
    fflush(writer);

    // Free the memory allocated for the slice.
    free(aa);

    return 0;
}

// absint returns the absolute value of an integer.
int absint(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

