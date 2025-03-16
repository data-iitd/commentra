#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getNextString reads and returns the next word as a string
char* getNextString() {
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

// getNextInt reads and converts the next integer from the input to an int
int getNextInt() {
    char *str = getNextString();
    return atoi(str);
}

// getNextInt64 reads and converts the next integer from the input to an int64_t
int64_t getNextInt64() {
    char *str = getNextString();
    return strtoll(str, NULL, 10);
}

// getNextUint64 reads and converts the next unsigned integer from the input to a uint64_t
uint64_t getNextUint64() {
    char *str = getNextString();
    return strtoull(str, NULL, 10);
}

// getNextFloat64 reads and converts the next floating-point number from the input to a double
double getNextFloat64() {
    char *str = getNextString();
    return strtod(str, NULL);
}

// main function is the entry point of the program
int main(int argc, char *argv[]) {
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
    char buffer[500001];
    setvbuf(fp, buffer, _IOFBF, 500001);
    setvbuf(wfp, NULL, _IONBF, 0);

    // read the first integer from the input
    int n = getNextInt();

    // initialize answer variable
    const char *ans = "second";
    // iterate through the input integers
    for (int i = 0; i < n; i++) {
        // read the next integer from the input
        int a = getNextInt();
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
    // flush the writer buffer
    fflush(wfp);

    // close files if they were opened
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}
