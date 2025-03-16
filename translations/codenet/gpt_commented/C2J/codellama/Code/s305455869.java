#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <limits.h>
#include <math.h>

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input values and the result
        int a, b;
        int ans;

        // Read two integers from standard input
        scanf("%d %d", &a, &b);

        // Initialize the answer variable to zero
        ans = 0;

        // Determine the value of ans based on the value of a
        if (a >= 13) {
            // If a is 13 or greater, set ans to b
            ans = b;
        } else if (a >= 6) {
            // If a is between 6 and 12, set ans to half of b
            ans = b / 2;
        }

        // Output the result
        printf("%d\n", ans);

        // Return 0 to indicate successful execution
        return 0;
    }
}

