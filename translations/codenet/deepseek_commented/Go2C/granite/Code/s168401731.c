
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new bufio.Scanner with specific configurations.
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL);
    return fp;
}

// getNextString reads the next word from the scanner.
char *getNextString(FILE *fp) {
    static char buf[500001];
    fscanf(fp, "%s", buf);
    return buf;
}

// getNextInt reads the next word, converts it to an integer, and returns it.
int getNextInt(FILE *fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}

// getNextInt64 reads the next word, converts it to an int64, and returns it.
long long getNextInt64(FILE *fp) {
    long long i;
    fscanf(fp, "%lld", &i);
    return i;
}

// getNextUint64 reads the next word, converts it to a uint64, and returns it.
unsigned long long getNextUint64(FILE *fp) {
    unsigned long long i;
    fscanf(fp, "%llu", &i);
    return i;
}

// getNextFloat64 reads the next word, converts it to a float64, and returns it.
double getNextFloat64(FILE *fp) {
    double i;
    fscanf(fp, "%lf", &i);
    return i;
}

// Main function handles file input/output operations based on command-line arguments.
int main(int argc, char **argv) {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Check if command-line arguments are provided for file input/output.
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    fp = getScanner(fp);
    setbuf(wfp, NULL);

    // Read the number of integers to process.
    int n = getNextInt(fp);

    // Initialize the answer to "second".
    char *ans = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt(fp);
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }
    // Print the result based on the condition.
    fprintf(wfp, "%s\n", ans);
    fclose(wfp);
}
