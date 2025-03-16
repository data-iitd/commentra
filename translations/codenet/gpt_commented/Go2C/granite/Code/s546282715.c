
#include <stdio.h>
#include <stdlib.h>

// getNextWord reads the next word from the scanner and returns it as a string.
char* getNextWord(FILE* scanner) {
    char* word = (char*)malloc(100 * sizeof(char));
    fscanf(scanner, "%s", word);
    return word;
}

// getNextInt reads the next word from the scanner, converts it to an integer, and returns it.
int getNextInt(FILE* scanner) {
    int i;
    fscanf(scanner, "%d", &i);
    return i;
}

int main() {
    // Set the input source to standard input; if a file is provided as an argument, open that file.
    FILE* fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    // Create a buffered writer to output results to standard output.
    FILE* writer = stdout;

    // Read the first two integers, n and m, from the input.
    int n = getNextInt(fp);
    int m = getNextInt(fp);

    // Initialize a map to store the positions that are blocked (not allowed).
    int* aa = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        // Read each blocked position and mark it in the map.
        aa[i] = getNextInt(fp);
    }

    // Create a dynamic programming array to store the number of ways to reach each position.
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

    // Iterate through each position from 0 to n.
    for (int i = 0; i < n; i++) {
        // Check the next two positions (i+1 and i+2) to see if they can be reached.
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            int blocked = 0;
            for (int j = 0; j < m; j++) {
                if (i + ii == aa[j]) {
                    blocked = 1;
                    break;
                }
            }
            if (blocked) {
                continue; // If blocked, skip to the next iteration.
            }
            // Update the number of ways to reach position i+ii based on the current position i.
            dp[i + ii] += dp[i];
            dp[i + ii] %= 1000000007; // Ensure the result stays within the modulo limit.
        }
    }

    // Output the total number of ways to reach position n.
    fprintf(writer, "%d\n", dp[n]);

    // Flush the buffered writer to ensure all output is written.
    fflush(writer);

    // Free the allocated memory.
    free(aa);
    free(dp);

    return 0;
}
