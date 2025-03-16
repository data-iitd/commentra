#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 500001

// Function prototypes
void getNextString(char *buffer, FILE *fp);
int getNextInt(FILE *fp);
long long getNextInt64(FILE *fp);
unsigned long long getNextUint64(FILE *fp);
double getNextFloat64(FILE *fp);
void solve(FILE *fp, FILE *wfp);

// Function to get the next string from the file
void getNextString(char *buffer, FILE *fp) {
    fgets(buffer, BUFFER_SIZE, fp);
}

// Function to get the next integer from the file
int getNextInt(FILE *fp) {
    char buffer[BUFFER_SIZE];
    getNextString(buffer, fp);
    return atoi(buffer);
}

// Function to get the next 64-bit integer from the file
long long getNextInt64(FILE *fp) {
    char buffer[BUFFER_SIZE];
    getNextString(buffer, fp);
    return atoll(buffer);
}

// Function to get the next unsigned 64-bit integer from the file
unsigned long long getNextUint64(FILE *fp) {
    char buffer[BUFFER_SIZE];
    getNextString(buffer, fp);
    return strtoull(buffer, NULL, 10);
}

// Function to get the next float64 from the file
double getNextFloat64(FILE *fp) {
    char buffer[BUFFER_SIZE];
    getNextString(buffer, fp);
    return atof(buffer);
}

// Main function
int main() {
    FILE *fp = stdin;
    FILE *wfp = stdout;
    int cnt = 0;

    // Check for environment variables to determine input and output files.
    if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        cnt = 2; // Set the count for additional processing.
    }
    if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    // Solve the problem for the first time.
    solve(fp, wfp);

    // If cnt is greater than 0, solve the problem additional times.
    for (int i = 0; i < cnt; i++) {
        fprintf(wfp, "-----------------------------------\n");
        solve(fp, wfp);
    }

    // Close the files
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// Function to process the input values and determine if the condition is met.
void solve(FILE *fp, FILE *wfp) {
    int k = getNextInt(fp); // Read the first integer k.
    int x = getNextInt(fp); // Read the second integer x.

    char ans[4] = "No"; // Default answer is "No".
    if (k * 500 >= x) { // Check the condition.
        strcpy(ans, "Yes"); // Update answer to "Yes" if condition is met.
    }
    fprintf(wfp, "%s\n", ans); // Output the result.
}

