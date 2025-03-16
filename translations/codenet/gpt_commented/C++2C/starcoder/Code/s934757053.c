#include <stdio.h>

int main() {
    // Declare variables A and B to hold input values
    int A, B;
    // Initialize ans to count the number of iterations
    int ans = 0;
    // Initialize out to 1, which will be used in the loop
    int out = 1;

    // Read input values for A and B from the user
    scanf("%d %d", &A, &B);

    // Loop until out is less than B
    while (out < B) {
        // Decrement out by 1
        out--;
        // Increment out by the value of A
        out += A;
        // Increment the answer counter for each iteration
        ans++;
    }

    // Output the final count of iterations
    printf("%d\n", ans);

    // Return 0 to indicate successful execution of the program
    return 0;
}
