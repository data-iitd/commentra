#include <stdio.h> // Include the standard input-output library

// Define two integer variables: N and A
int N, A;

int main() {
    // Read the values of N and A from the standard input
    scanf("%d %d", &N, &A);

    // Use the conditional operator to check if the remainder of N divided by 500 is less than or equal to A
    printf("%s\n", (N % 500 <= A) ? "Yes" : "No");

    // End the main function and return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
