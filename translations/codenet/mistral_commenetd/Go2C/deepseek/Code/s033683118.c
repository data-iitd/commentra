#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next string
char* getNextString() {
    char *str = (char*)malloc(1000 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read the next integer
int getNextInt() {
    char *str = getNextString();
    int num = atoi(str);
    free(str);
    return num;
}

// Function to read the next integer64
long long getNextInt64() {
    char *str = getNextString();
    long long num = atoll(str);
    free(str);
    return num;
}

// Function to read the next uint64
unsigned long long getNextUint64() {
    char *str = getNextString();
    unsigned long long num = strtoull(str, NULL, 10);
    free(str);
    return num;
}

// Function to read the next float64
double getNextFloat64() {
    char *str = getNextString();
    double num = atof(str);
    free(str);
    return num;
}

// Main function
int main() {
    // Open the standard input and output files
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Set the file pointers for reading and writing
    if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        int cnt = 2; // Number of test cases to be read
    }
    if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
        int cnt = 1; // Number of test cases to be written
    }

    // Initialize the scanner and writer
    char buffer[500001];
    setvbuf(fp, buffer, _IOFBF, 500001);
    setvbuf(wfp, NULL, _IONBF, 0);

    // Solve the problem for the given test cases
    int k, x;
    char ans[4];
    while (fscanf(fp, "%d %d", &k, &x) != EOF) {
        // Initialize the answer
        strcpy(ans, "No");

        // Check if the condition is satisfied
        if (k * 500 >= x) {
            strcpy(ans, "Yes");
        }

        // Print the answer
        fprintf(wfp, "%s\n", ans);
    }

    // Close the files
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}
