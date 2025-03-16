#include <stdio.h>
#include <math.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    // Taking the range as input from the user

    int curr = r;
    int s = 0;
    // Initialize curr to r and s to 0

    while (curr) {
        s += 1;
        curr /= 10;
    }
    // Determine the number of digits in r and store it in s

    int first = pow(10, s);
    int second = first / 2;
    // Calculate the smallest number with s digits and its half

    int ans = -1;
    // Initialize ans to -1 to store the maximum product found

    int candidates[] = {l, r, first, second};
    for (int i = 0; i < 4; i++) {
        int curr = candidates[i];
        if (curr >= l && curr <= r) {
            char rev[12]; // Assuming max digits in int is 10 + 1 for null terminator
            int index = 0;
            for (char *k = (char *) &curr; *k != '\0'; k++) {
                rev[index++] = '9' - (*k - '0');
            }
            rev[index] = '\0'; // Null-terminate the string

            int rev_num = atoi(rev);
            ans = (ans > rev_num * curr) ? ans : rev_num * curr;
        }
    }
    // Iterate over the specified numbers, check if they are within the range,
    // reverse the digits, calculate the product, and update ans if necessary

    printf("%d\n", ans);
    // Print the maximum product found

    return 0;
}
// <END-OF-CODE>
