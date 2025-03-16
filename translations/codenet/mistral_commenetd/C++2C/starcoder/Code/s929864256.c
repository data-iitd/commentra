#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Initialize variables
    int a, b;

    // Read input values from standard input
    scanf("%d %d", &a, &b);

    // Calculate the maximum value among a+b, a-b, and a*b
    int result = max(a+b, max(a-b, a*b));

    // Output the result to standard output
    printf("%d\n", result);

    // End of the program
    return 0;
}

