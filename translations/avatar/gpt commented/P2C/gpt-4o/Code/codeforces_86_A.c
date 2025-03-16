#include <stdio.h>
#include <math.h>

int main() {
    // Read the input values for l and r, which define the range
    int l, r;
    scanf("%d %d", &l, &r);

    // Initialize the current value to r and a counter for the number of digits
    int curr = r;
    int s = 0;

    // Count the number of digits in the current value (r)
    while (curr) {
        s++;
        curr /= 10;
    }

    // Calculate the first power of ten greater than r
    int first = pow(10, s);

    // Calculate the second value as half of the first power of ten
    int second = first / 2;

    // Initialize the answer variable to store the maximum product found
    long long ans = -1;

    // Iterate through the possible candidates: l, r, first, and second
    int candidates[] = {l, r, first, second};
    for (int i = 0; i < 4; i++) {
        int candidate = candidates[i];
        // Check if the candidate is within the range [l, r]
        if (candidate >= l && candidate <= r) {
            curr = candidate;
            char rev[20]; // Array to store the reverse number as a string
            int index = 0;

            // Create the reverse number by subtracting each digit from 9
            for (char *k = (char *) &curr; *k != '\0'; k++) {
                rev[index++] = '9' - (*k - '0');
            }
            rev[index] = '\0'; // Null-terminate the string

            // Update the answer with the maximum product of the current number and its reverse
            long long rev_num = atoll(rev); // Convert the reverse string to a long long
            ans = (ans > rev_num * curr) ? ans : rev_num * curr;
        }
    }

    // Print the maximum product found
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
