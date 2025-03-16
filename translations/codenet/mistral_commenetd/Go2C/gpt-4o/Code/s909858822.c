// Import the standard input-output library
#include <stdio.h>

int main() {
    // Declare two integer variables, A and B
    int A, B;
    
    // Read their values from the standard input
    scanf("%d %d", &A, &B);

    // Declare an integer variable, ans, to store the result of our calculation
    int ans = 0;

    // Use an if statement to check the value of A
    if (A >= 6 && A <= 12) {
        // If A is between 6 and 12 (inclusive), calculate the answer as the integer division of B by 2
        ans = B / 2;
    } else if (A > 12) {
        // If A is greater than 12, assign the value of B directly to the ans variable
        ans = B;
    }

    // Print the value of ans
    printf("%d\n", ans);

    // End of code
    return 0;
}
// <END-OF-CODE>
