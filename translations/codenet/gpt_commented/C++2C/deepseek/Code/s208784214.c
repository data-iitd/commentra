#include <stdio.h> // Include the stdio library for input and output operations

int N, A; // Declare two integer variables N and A

int main() {
    // Read two integers from standard input
    scanf("%d %d", &N, &A);

    // Check if the remainder of N divided by 500 is less than or equal to A
    // If true, print "Yes"; otherwise, print "No"
    printf("%s\n", (N % 500 <= A) ? "Yes" : "No");

    return 0; // Return 0 to indicate successful completion of the program
}

