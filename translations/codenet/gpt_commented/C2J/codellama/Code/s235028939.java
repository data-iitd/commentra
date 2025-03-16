#include <stdio.h>

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables n and m
        int n, m;

        // Read two integers from standard input
        // n represents the number of rows, and m represents the number of columns
        scanf("%d %d", &n, &m);

        // Calculate the product of (n - 1) and (m - 1)
        // This represents the number of internal edges in a grid of n by m cells
        printf("%d\n", (n - 1) * (m - 1));

        // Flush the output buffer to ensure all output is printed
        fflush(stdout);

        // Return 0 to indicate successful completion of the program
        return 0;
    }
}

