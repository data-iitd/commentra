#include <stdio.h>
#include <string.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);

    int curr = r;
    int s = 0;

    // Count the number of digits in the current value (r)
    while (curr) {
        s++;
        curr /= 10;
    }

    // Calculate the first power of ten greater than r
    int first = 10 * s;

    // Calculate the second value as half of the first power of ten
    int second = first / 2;

    // Initialize the answer variable to store the maximum product found
    int ans = -1;

    // Iterate through the possible candidates: l, r, first, and second
    for (int i = l; i <= r; i++) {
        if (i >= l && i <= r) {
            curr = i;
            char rev[10];
            memset(rev, 0, sizeof(rev));

            // Create the reverse number by subtracting each digit from 9
            int j = 0;
            while (curr) {
                rev[j++] = '0' + (9 - (curr % 10));
                curr /= 10;
            }

            // Update the answer with the maximum product of the current number and its reverse
            int rev_num = atoi(rev);
            int product = i * rev_num;
            if (product > ans) {
                ans = product;
            }
        }
    }

    // Print the maximum product found
    printf("%d\n", ans);

    return 0;
}
