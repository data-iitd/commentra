
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner to read input from a file.
// It sets the split function to scan words and buffers the input to a specified size.
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL);
    return fp;
}

// getNextString reads the next token from the scanner and returns it as a string.
char *getNextString(FILE *fp) {
    static char buf[500001];
    fscanf(fp, "%s", buf);
    return buf;
}

// getNextInt reads the next token, converts it to an integer, and returns it.
int getNextInt(FILE *fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}

// getNextInt64 reads the next token, converts it to an int64, and returns it.
long long getNextInt64(FILE *fp) {
    long long i;
    fscanf(fp, "%lld", &i);
    return i;
}

// getNextUint64 reads the next token, converts it to a uint64, and returns it.
unsigned long long getNextUint64(FILE *fp) {
    unsigned long long i;
    fscanf(fp, "%llu", &i);
    return i;
}

// getNextFloat64 reads the next token, converts it to a float64, and returns it.
double getNextFloat64(FILE *fp) {
    double i;
    fscanf(fp, "%lf", &i);
    return i;
}

// main function handles the program's flow.
// It sets up the input and output files based on environment variables,
// calls the solve function, and prints separators if necessary.
int main() {
    FILE *fp = stdin;
    FILE *wfp = stdout;
    int cnt = 0;

    if (getenv("MASPY")!= NULL && strcmp(getenv("MASPY"), "ますπ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        cnt = 2;
    }
    if (getenv("MASPYPY")!= NULL && strcmp(getenv("MASPYPY"), "ますπッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    fp = getScanner(fp);
    fprintf(wfp, "%s", solve(fp, wfp));
    for (int i = 0; i < cnt; i++) {
        fprintf(wfp, "-----------------------------------\n");
        fprintf(wfp, "%s", solve(fp, wfp));
    }
    fclose(wfp);
}

// solve function reads two integers k and x, and determines if k * 500 is greater than or equal to x.
// It writes "Yes" or "No" based on this condition.
char *solve(FILE *fp, FILE *wfp) {
    static char buf[1024];
    int k = getNextInt(fp);
    int x = getNextInt(fp);

    char *ans = "No";
    if (k * 500 >= x) {
        ans = "Yes";
    }
    sprintf(buf, "%s\n", ans);
    return buf;
}
