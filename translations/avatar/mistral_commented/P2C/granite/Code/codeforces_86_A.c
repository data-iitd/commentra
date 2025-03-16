
#include <stdio.h>
#include <math.h>

int main() {
    // Take two integers as input and store them in variables 'l' and 'r' respectively
    int l, r;
    scanf("%d %d", &l, &r);

    // Initialize current number to 'r'
    int curr = r;

    // Initialize sum variable's' to 0
    int s = 0;

    // While 'curr' is not zero, perform the following operations
    while (curr) {
        // Increment the sum's' by 1
        s++;

        // Calculate the power of 10 raised to the value of's' and store it in 'first'
        int first = pow(10, s);

        // Calculate half of 'first' and store it in'second'
        int second = first / 2;

        // Initialize 'ans' with a negative value
        int ans = -1;

        // Iterate through the list containing 'l', 'r', 'first', and'second'
        for (int i : {l, r, first, second}) {
            // If 'i' lies within the range of 'l' and 'r', update 'curr' and'rev'
            if (i >= l && i <= r) {
                curr = i;
                int rev = 0;
                // Reverse the digits of 'curr' and store it in'rev'
                for (int k = curr; k > 0; k /= 10) {
                    rev = rev * 10 + 9 - (k % 10);
                }

                // Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
                ans = fmax(ans, rev * curr);
            }
        }
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}
