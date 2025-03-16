
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new scanner from a file pointer
FILE* getScanner(FILE* fp) {
    return fp;
}

// Function to read the next string from the scanner
char* getNextString(FILE* scanner) {
    int ch;
    char* str = (char*)malloc(500001 * sizeof(char));
    int i = 0;
    while ((ch = fgetc(scanner))!= EOF) {
        if (ch =='' || ch == '\n' || ch == '\t') {
            break;
        }
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
    return str;
}

// Function to read the next integer from the scanner
int getNextInt(FILE* scanner) {
    int num;
    fscanf(scanner, "%d", &num);
    return num;
}

// Function to read the next integer64 from the scanner
long long getNextInt64(FILE* scanner) {
    long long num;
    fscanf(scanner, "%lld", &num);
    return num;
}

// Function to read the next uint64 from the scanner
unsigned long long getNextUint64(FILE* scanner) {
    unsigned long long num;
    fscanf(scanner, "%llu", &num);
    return num;
}

// Function to read the next float64 from the scanner
double getNextFloat64(FILE* scanner) {
    double num;
    fscanf(scanner, "%lf", &num);
    return num;
}

// Main function
int main() {
    // Open the standard input and output files
    FILE* fp = stdin;
    FILE* wfp = stdout;

    // Set the file pointers for reading and writing
    if (getenv("MASPY")!= NULL && strcmp(getenv("MASPY"), "ますπ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        int cnt = 2; // Number of test cases to be read
    }
    if (getenv("MASPYPY")!= NULL && strcmp(getenv("MASPYPY"), "ますπッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
        int cnt = 1; // Number of test cases to be written
    }

    // Initialize the scanner and writer
    FILE* scanner = getScanner(fp);

    // Solve the problem for the given test cases
    for (int i = 0; i < cnt; i++) {
        printf("-----------------------------------\n"); // Print a separator for each test case
        solve(scanner, wfp);
    }

    // Close the files
    fclose(fp);
    fclose(wfp);

    return 0;
}

// Function to solve the problem for a single test case
void solve(FILE* scanner, FILE* writer) {
    // Read the input values
    int k = getNextInt(scanner);
    int x = getNextInt(scanner);

    // Initialize the answer
    char* ans = "No";

    // Check if the condition is satisfied
    if (k * 500 >= x) {
        ans = "Yes";
    }

    // Print the answer
    fprintf(writer, "%s\n", ans);
}

