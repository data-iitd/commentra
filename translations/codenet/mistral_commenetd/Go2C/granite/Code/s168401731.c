

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes and returns a new bufio.Scanner from the given file pointer
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL);
    return fp;
}

// getNextString reads and returns the next word as a string from the scanner
char *getNextString(FILE *fp) {
    static char buf[500001];
    fscanf(fp, "%s", buf);
    return buf;
}

// getNextInt reads and converts the next integer from the scanner to an int
int getNextInt(FILE *fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}

// getNextInt64 reads and converts the next integer from the scanner to an int64
long long getNextInt64(FILE *fp) {
    long long i;
    fscanf(fp, "%lld", &i);
    return i;
}

// getNextUint64 reads and converts the next unsigned integer from the scanner to a uint64
unsigned long long getNextUint64(FILE *fp) {
    unsigned long long i;
    fscanf(fp, "%llu", &i);
    return i;
}

// getNextFloat64 reads and converts the next floating-point number from the scanner to a float64
double getNextFloat64(FILE *fp) {
    double i;
    fscanf(fp, "%lf", &i);
    return i;
}

int main(int argc, char **argv) {
    // open standard input as default file if no arguments are provided
    FILE *fp = stdin;
    // open output file if provided as an argument
    FILE *wfp = stdout;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        // create output file if provided as an argument
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    // initialize scanner and writer
    FILE *scanner = getScanner(fp);
    setbuf(wfp, NULL);

    // read the first integer from the input
    int n = getNextInt(scanner);

    // initialize answer variable
    char *ans = "second";
    // iterate through the input integers
    for (int i = 0; i < n; i++) {
        // read the next integer from the input
        int a = getNextInt(scanner);
        // check if the current integer is odd
        if (a % 2 == 1) {
            // update the answer if an odd integer is found
            ans = "first";
            // exit the loop if only one odd integer is found
            break;
        }
    }
    // write the answer to the output
    fprintf(wfp, "%s\n", ans);

    // close the files if they were opened
    if (fp!= stdin) {
        fclose(fp);
    }
    if (wfp!= stdout) {
        fclose(wfp);
    }

    return 0;
}
