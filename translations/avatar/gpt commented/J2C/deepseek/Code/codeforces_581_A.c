#include <stdio.h>

int main() {
    int a, b;
    int count = 0;

    // Reading two integers from user input
    scanf("%d %d", &a, &b);

    // Loop to process pairs of a and b while both are greater than zero
    while (1) {
        // Check if both a and b are positive
        if (a > 0 && b > 0) {
            // Increment the count of pairs
            count++;
            // Decrement both a and b
            a--;
            b--;
        } else {
            // Break the loop if either a or b is not positive
            break;
        }
    }

    // Calculate the number of pairs that can be formed from the remaining a and b
    int ans = a / 2 + b / 2;

    // Output the count of pairs processed and the calculated answer
    printf("%d %d\n", count, ans);

    return 0;
}
