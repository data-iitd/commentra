#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next integer from the input.
int getNextInt(FILE *fp) {
    int value;
    fscanf(fp, "%d", &value);
    return value;
}

// Function to solve the problem based on the input values.
void solve(FILE *fp, FILE *wfp) {
    int k = getNextInt(fp); // Read the first integer k.
    int x = getNextInt(fp); // Read the second integer x.

    // Check the condition and print the result.
    if (k * 500 >= x) {
        fprintf(wfp, "Yes\n");
    } else {
        fprintf(wfp, "No\n");
    }
}

int main() {
    // Initialize file pointers for input and output.
    FILE *fp = stdin;
    FILE *wfp = stdout;
    int cnt = 0;

    // Check for environment variables to determine input and output files.
    if (getenv("MASPY") && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        cnt = 2; // Set the count for additional processing.
    }
    if (getenv("MASPYPY") && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    // Solve the problem for the first time.
    solve(fp, wfp);

    // If cnt is greater than 0, solve the problem additional times.
    for (int i = 0; i < cnt; i++) {
        fprintf(wfp, "-----------------------------------\n");
        solve(fp, wfp);
    }

    // Close the file pointers if they were opened.
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// <END-OF-CODE>
