#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from the input
int getNextInt(FILE *fp) {
    int value;
    fscanf(fp, "%d", &value);
    return value;
}

// Main function is the entry point of the program
int main(int argc, char *argv[]) {
    // Open standard input as default file if no arguments are provided
    FILE *fp = stdin;
    // Open output file if provided as an argument
    FILE *wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening input file");
            return EXIT_FAILURE;
        }
        // Create output file if provided as an argument
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
            if (wfp == NULL) {
                perror("Error opening output file");
                fclose(fp);
                return EXIT_FAILURE;
            }
        }
    }

    // Read the first integer from the input
    int n = getNextInt(fp);

    // Initialize answer variable
    const char *ans = "second";
    // Iterate through the input integers
    for (int i = 0; i < n; i++) {
        // Read the next integer from the input
        int a = getNextInt(fp);
        // Check if the current integer is odd
        if (a % 2 == 1) {
            // Update the answer if an odd integer is found
            ans = "first";
            // Exit the loop if only one odd integer is found
            break;
        }
    }
    // Write the answer to the output
    fprintf(wfp, "%s\n", ans);

    // Close the files if they were opened
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return EXIT_SUCCESS;
}

// <END-OF-CODE>
