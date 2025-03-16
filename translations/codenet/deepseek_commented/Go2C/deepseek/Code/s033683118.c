#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 500001

// getNextString reads the next token from the standard input and returns it as a string.
char* getNextString() {
    static char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        return buffer;
    } else {
        return NULL;
    }
}

// getNextInt reads the next token, converts it to an integer, and returns it.
int getNextInt() {
    char* str = getNextString();
    return atoi(str);
}

// getNextInt64 reads the next token, converts it to an int64_t, and returns it.
int64_t getNextInt64() {
    char* str = getNextString();
    return atoll(str);
}

// getNextUint64 reads the next token, converts it to a uint64_t, and returns it.
uint64_t getNextUint64() {
    char* str = getNextString();
    return strtoull(str, NULL, 10);
}

// getNextFloat64 reads the next token, converts it to a double, and returns it.
double getNextFloat64() {
    char* str = getNextString();
    return atof(str);
}

// main function handles the program's flow.
// It sets up the input and output files based on environment variables,
// calls the solve function, and prints separators if necessary.
int main() {
    FILE* fp = stdin;
    FILE* wfp = stdout;
    int cnt = 0;

    if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        cnt = 2;
    }
    if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    if (fp == NULL || wfp == NULL) {
        fprintf(stderr, "Error opening files\n");
        return 1;
    }

    solve(fp, wfp);
    for (int i = 0; i < cnt; i++) {
        fprintf(wfp, "-----------------------------------\n");
        solve(fp, wfp);
    }

    fclose(fp);
    fclose(wfp);
    return 0;
}

// solve function reads two integers k and x, and determines if k * 500 is greater than or equal to x.
// It writes "Yes" or "No" based on this condition.
void solve(FILE* fp, FILE* wfp) {
    int k = getNextInt();
    int x = getNextInt();

    char ans[3] = "No";
    if (k * 500 >= x) {
        strcpy(ans, "Yes");
    }
    fprintf(wfp, "%s\n", ans);
}

