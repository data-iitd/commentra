#include <stdio.h>

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int A, B;

    // Read two integers A and B from the standard input
    scanf("%d %d", &A, &B);

    // Calculate the maximum value of A+B, A-B, and A*B using the max function
    int mx = max(A + B, A - B);
    mx = max(mx, A * B);

    // Print the maximum value
    printf("%d\n", mx);

    return 0;
}

// <END-OF-CODE>
