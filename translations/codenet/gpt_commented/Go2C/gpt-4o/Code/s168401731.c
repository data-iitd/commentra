#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from the input.
int getNextInt(FILE *fp) {
    int value;
    fscanf(fp, "%d", &value);
    return value;
}

int main(int argc, char *argv[]) {
    // Initialize file pointers for input and output.
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Check for command line arguments to open input and output files.
    if (argc > 1) {
        fp = fopen(argv[1], "r"); // Open input file if provided.
        if (argc > 2) {
            wfp = fopen(argv[2], "w"); // Create output file if provided.
        }
    }

    // Read the number of integers to process.
    int n = getNextInt(fp);

    // Initialize the answer as "second" and check for odd integers.
    const char *ans = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt(fp); // Read the next integer.
        if (a % 2 == 1) { // Check if the integer is odd.
            ans = "first"; // If odd, set answer to "first".
            break; // Exit the loop early if an odd integer is found.
        }
    }

    // Write the result to the output.
    fprintf(wfp, "%s\n", ans);

<<<<<<< HEAD
    // Close the files if they were opened.
=======
    // Close files if they were opened.
>>>>>>> 98c87cb78a (data updated)
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// <END-OF-CODE>
