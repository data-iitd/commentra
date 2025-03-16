
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Static variable to hold the value of N.
static int N;
// Constant MOD value.
static int MOD = (int) (1e9 + 7);

/**
 * Main method where the program execution starts.
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 * @return 0 if the program executed successfully, else 1.
 */
int main(int argc, char *argv[]) {
    // Scanner to read input from the standard input stream.
    FILE *in = stdin;
    // PrintWriter to write output to the standard output stream.
    FILE *out = stdout;
    // Read the number of test cases.
    int t;
    fscanf(in, "%d", &t);
    // Process each test case.
    while (t-- > 0) {
        // Read the values of n, a, and b.
        long n, a, b;
        fscanf(in, "%ld %ld %ld", &n, &a, &b);
        // Check if n is less than a.
        if (n < a) {
            fprintf(out, "No\n");
            continue;
        }
        // Check if a is equal to b.
        if (a == b) {
            if (n % a == 0) {
                fprintf(out, "Yes\n");
            } else {
                fprintf(out, "No\n");
            }
            continue;
        }
        // Calculate x as b / (b - a).
        long x = b / (b - a);
        // Check if n is greater than x * a.
        if (n > x * a) {
            fprintf(out, "Yes\n");
            continue;
        }
        // Perform binary search to find the minimum ans.
        long low = 1;
        long high = x + 1;
        long ans = 1;
        while (low <= high) {
            long mid = (low + high) / 2;
            if (mid * a < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        // Check if n lies between (ans - 1) * b and ans * a.
        if (n > (ans - 1) * b && n < ans * a) {
            fprintf(out, "No\n");
        } else {
            fprintf(out, "Yes\n");
        }
    }
    // Close the PrintWriter to flush the output.
    fclose(out);
    return 0;
}

