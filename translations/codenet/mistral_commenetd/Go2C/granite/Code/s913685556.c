
#include <stdio.h>

// Define a function max that takes two integers as arguments and returns the maximum value.
int max(int a, int b) {
    return (a > b)? a : b;
}

// The main function is the entry point of the program.
int main() {
    // Initialize a Scanner object named sc.
    int A, B;
    scanf("%d %d", &A, &B);

    // Calculate the maximum value of A+B, A-B, and A*B using the max function.
    int mx = max(A+B, A-B);
    mx = max(mx, A*B);

    // Print the maximum value.
    printf("%d\n", mx);

    return 0;
}
