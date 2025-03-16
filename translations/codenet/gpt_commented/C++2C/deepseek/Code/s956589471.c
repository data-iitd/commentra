#include <stdio.h>  // Include the stdio library for input and output

int main() {
    // Declare variables to hold input values
    int a, b, c, d, e, k;

    // Read six integers from standard input
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &k);

    // Check if the difference between e and a is less than or equal to k
    // If true, print "Yay!", otherwise print ":("
    printf("%s\n", (e - a <= k) ? "Yay!" : ":(");

    return 0; // Return 0 to indicate successful execution of the program
}
