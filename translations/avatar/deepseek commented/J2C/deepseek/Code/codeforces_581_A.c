#include <stdio.h>

int main() {
    int a, b;
    int count = 0;

    // Read first integer input
    scanf("%d %d", &a, &b);

    // Loop continues until the condition is met to break
    while (1) {
        if (a > 0 && b > 0) { // Check if both a and b are positive
            count++; // Increment count
            a--; // Decrement a
            b--; // Decrement b
        } else {
            break; // Break the loop if a or b is not positive
        }
    }

    int ans = a / 2 + b / 2; // Calculate the value of ans
    printf("%d %d\n", count, ans); // Print the results

    return 0;
}

