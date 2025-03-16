#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next integer from the input
int getNextInt(FILE *fp) {
    int value;
    fscanf(fp, "%d", &value);
    return value;
}

// Main function handles the program's flow
int main() {
    FILE *fp = stdin;
    FILE *wfp = stdout;
    int cnt = 0;

    // Check for environment variables
    if (getenv("MASPY") && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        cnt = 2;
    }
    if (getenv("MASPYPY") && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    // Solve the problem
    for (int i = 0; i < cnt + 1; i++) {
        int k = getNextInt(fp);
        int x = getNextInt(fp);

        // Determine if k * 500 is greater than or equal to x
        if (k * 500 >= x) {
            fprintf(wfp, "Yes\n");
        } else {
            fprintf(wfp, "No\n");
        }

        // Print separator if needed
        if (i < cnt) {
            fprintf(wfp, "-----------------------------------\n");
        }
    }

    // Close files if they were opened
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// <END-OF-CODE>
