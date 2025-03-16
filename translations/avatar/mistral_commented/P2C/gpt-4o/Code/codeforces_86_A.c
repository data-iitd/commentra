#include <stdio.h>
#include <math.h>

int main() {
    int l, r;
    // Take two integers as input and store them in 'l' and 'r'
    scanf("%d %d", &l, &r);

    // Initialize current number to 'r'
    int curr = r;

    // Initialize sum variable 's' to 0
    int s = 0;

    // Initialize 'ans' with a negative value
    long long ans = -1;

    // While 'curr' is not zero, perform the following operations
    while (curr) {
        // Increment the sum 's' by 1
        s++;

        // Calculate the power of 10 raised to the value of 's' and store it in 'first'
        long long first = pow(10, s);

        // Calculate half of 'first' and store it in 'second'
        long long second = first / 2;

        // Iterate through the list containing 'l', 'r', 'first', and 'second'
        for (long long i = l; i <= r || i == first || i == second; i = (i == first ? second + 1 : (i == second ? r + 1 : i + 1))) {
            // If 'i' lies within the range of 'l' and 'r', update 'curr'
            if (i >= l && i <= r) {
                curr = i;
                long long rev = 0;
                long long temp = curr;

                // Reverse the digits of 'curr' and store it in 'rev'
                while (temp > 0) {
                    rev = rev * 10 + (9 - (temp % 10));
                    temp /= 10;
                }

                // Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
                ans = fmax(ans, rev * curr);
            }
        }
        // Break the loop if curr is updated to 0
        if (curr == 0) break;
    }

    // Print the final answer
    printf("%lld\n", ans);

    return 0;
}
