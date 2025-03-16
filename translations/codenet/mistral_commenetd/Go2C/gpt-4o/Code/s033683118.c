#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next integer from the input
int getNextInt(FILE *fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}

// Function to solve the problem for a single test case
void solve(FILE *fp, FILE *wfp) {
    // Read the input values
    int k = getNextInt(fp);
    int x = getNextInt(fp);

    // Initialize the answer
    const char *ans = "No";

    // Check if the condition is satisfied
    if (k * 500 >= x) {
        ans = "Yes";
    }

    // Print the answer
    fprintf(wfp, "%s\n", ans);
}

// Main function
int main() {
    // Open the standard input and output files
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Check for environment variables to change input/output files
    if (getenv("MASPY") && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
    }
    if (getenv("MASPYPY") && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    // Number of test cases to be read
    int cnt = 2; // Default number of test cases
    if (getenv("MASPYPY") && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        cnt = 1; // Change to 1 if MASPYPY is set
    }

    // Solve the problem for the given test cases
    for (int i = 0; i < cnt; i++) {
        solve(fp, wfp);
        fprintf(wfp, "-----------------------------------\n"); // Print a separator for each test case
    }

    // Close the files if they were opened
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// <END-OF-CODE>
