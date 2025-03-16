
#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100], s[100];
    int i, x, c, d;

    // Read input and split into two strings a and b, removing the trailing newline
    scanf("%s %s", a, b);

    // Determine the maximum length of the two strings
    x = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);

    // Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
    for (i = 0; i < x - strlen(a); i++) {
        a[i] = '0';
    }
    for (i = 0; i < x - strlen(b); i++) {
        b[i] = '0';
    }

    // Initialize an empty string to store the result and a carry variable
    s[0] = '\0';
    c = 0;

    // Iterate over each digit from the least significant to the most significant
    for (i = x - 1; i >= 0; i--) {
        // Calculate the sum of the corresponding digits and the carry
        d = b[i] - '0' + a[i] - '0' + c;

        // Check if the sum exceeds 9, which requires a carry
        if (d > 9) {
            s[i] = d - 10 + '0';  // Append the last digit of the sum to the result
            c = 1;  // Set carry to 1 for the next iteration
        } else {
            s[i] = d + '0';  // Append the sum to the result
            c = 0;  // Reset carry to 0
        }
    }

    // If there's a carry left after the last addition, append '1' to the result
    if (c == 1) {
        s[0] = '1';
    }

    // Print the final result, reversing the string to get the correct order and converting to int to remove leading zeros
    printf("%d", atoi(s));

    return 0;
}

