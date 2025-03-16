
// Including necessary C libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function starts here
int main() {

    // Creating FastReader object to read input
    struct FastReader {
        FILE *br;
        char *str;
        char *token;
    } sc;

    // Creating PrintWriter object to write output
    struct PrintWriter {
        FILE *pw;
    } pw;

    // Initializing FastReader object
    sc.br = stdin;
    sc.str = (char *) malloc(1024 * sizeof(char));
    sc.token = (char *) malloc(1024 * sizeof(char));

    // Initializing PrintWriter object
    pw.pw = stdout;

    // Reading the first integer input
    int x = 0;
    fgets(sc.str, 1024, sc.br);
    sscanf(sc.str, "%d", &x);

    // Initializing count variable to 0
    int count = 0;

    // Initializing temporary variable tmp with the value of x
    int tmp = x;

    // Setting x to 0
    x = 0;

    // Starting a while loop that runs until x is equal to 360
    while (x != 360) {

        // Adding the value of tmp to x
        x = x + tmp;

        // If x is greater than 360, then subtract 360 from it
        if (x > 360) {
            x = x - 360;
        }

        // Incrementing the count variable
        count++;
    }

    // Printing the value of count to the console using PrintWriter
    fprintf(pw.pw, "%d\n", count);

    // Closing the PrintWriter and FastReader objects
    free(sc.str);
    free(sc.token);
    fclose(sc.br);
    fclose(pw.pw);

    return 0;
}

