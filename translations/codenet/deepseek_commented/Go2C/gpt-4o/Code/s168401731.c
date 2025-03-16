#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
// Function to read the next integer from the input.
int getNextInt(FILE *fp) {
    int value;
    fscanf(fp, "%d", &value);
=======
// Function to read the next integer from input.
int getNextInt() {
    int value;
    scanf("%d", &value);
>>>>>>> 98c87cb78a (data updated)
    return value;
}

// Main function handles file input/output operations based on command-line arguments.
int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Check if command-line arguments are provided for file input/output.
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    // Read the number of integers to process.
<<<<<<< HEAD
    int n = getNextInt(fp);
=======
    int n = getNextInt();
>>>>>>> 98c87cb78a (data updated)

    // Initialize the answer to "second".
    const char *ans = "second";
    for (int i = 0; i < n; i++) {
<<<<<<< HEAD
        int a = getNextInt(fp);
=======
        int a = getNextInt();
>>>>>>> 98c87cb78a (data updated)
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }
    // Print the result based on the condition.
    fprintf(wfp, "%s\n", ans);

    // Close files if they were opened.
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// <END-OF-CODE>
