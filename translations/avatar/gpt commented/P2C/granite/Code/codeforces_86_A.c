
#include <stdio.h>

int main() {
    // Read the input values for l and r, which define the range
    int l, r;
    scanf("%d %d", &l, &r);

    // Initialize the current value to r and a counter for the number of digits
    int curr = r;
    int s = 0;

    // Count the number of digits in the current value (r)
    while (curr) {
        s += 1;
        curr /= 10;
    }

    // Calculate the first power of ten greater than r
    int first = 1;
    for (int i = 0; i < s; i++) {
        first *= 10;
    }

    // Calculate the second value as half of the first power of ten
    int second = first / 2;

    // Initialize the answer variable to store the maximum product found
    int ans = -1;

    // Iterate through the possible candidates: l, r, first, and second
    for (int i = l; i <= r; i++) {
        // Check if the candidate is within the range [l, r]
        curr = i;
        int rev = 0;

        // Create the reverse number by subtracting each digit from 9
        while (curr) {
            rev = rev * 10 + (9 - (curr % 10));
            curr /= 10;
        }

        // Update the answer with the maximum product of the current number and its reverse
        ans = ans > rev * i? ans : rev * i;
    }

    // Print the maximum product found
    printf("%d\n", ans);

    return 0;
}
