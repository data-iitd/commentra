#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to read the next word from the scanner
char* getNextWord(char** buffer) {
    while (**buffer && **buffer != ' ') {
        (*buffer)++;
    }
    if (**buffer == ' ') {
        (*buffer)++;
    }
    return *buffer;
}

// Function to read the next integer from the scanner
int getNextInt(char** buffer) {
    int result;
    char* end;
    result = strtol(buffer, &end, 10);
    buffer = end;
    return result;
}

// Main function
int main(int argc, char* argv[]) {
    // Open the standard input file if the command line argument is provided
    FILE* fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    // Initialize the buffer for reading
    char buffer[1024];
    fread(buffer, 1, sizeof(buffer), fp);

    // Initialize the scanner and writer
    char* cursor = buffer;
    int n = getNextInt(&cursor);
    int m = getNextInt(&cursor);

    // Initialize an associative array to store the elements
    int aa[100001] = {0};
    // Read m elements and store them in the associative array
    for (int i = 0; i < m; i++) {
        aa[getNextInt(&cursor)] = 1;
    }

    // Initialize a slice of length n+1 for dynamic programming
    int dp[n+1];
    // Initialize the first element of the slice
    dp[0] = 1;

    // Iterate through the array from index 0 to n-1
    for (int i = 0; i < n; i++) {
        // Iterate through the prefix sum from i to i+2
        for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
            // Skip if the current index and its sum are already present in the associative array
            if (aa[i+ii] == 1) {
                continue;
            }
            // Calculate the dynamic programming value for the current index
            dp[i+ii] = (dp[i+ii] + dp[i]) % MOD;
        }
    }

    // Print the final answer
    printf("%d\n", dp[n]);

    // Close the file if it was opened
    if (argc > 1) {
        fclose(fp);
    }

    return 0;
}
