#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[1001], b[1001];
    char s[1002] = {0};
    int x, c = 0;

    // Read input and split into two strings, a and b
    scanf("%s %s", a, b);

    // Determine the maximum length of the two strings
    x = strlen(a) > strlen(b) ? strlen(a) : strlen(b);

    // Pad the shorter string with zeros on the left
    char *ap = a + strlen(a) - x;
    char *bp = b + strlen(b) - x;

    // Pad the shorter string with zeros on the right
    for (int i = 0; i < x; i++) {
        if (i < strlen(a) - x) {
            ap[i] = '0';
        } else {
            ap[i] = a[i];
        }
        if (i < strlen(b) - x) {
            bp[i] = '0';
        } else {
            bp[i] = b[i];
        }
    }

    // Loop through each digit from right to left
    for (int i = 0; i < x; i++) {
        // Add the corresponding digits from a and b along with the carry
        int d = bp[x - i - 1] - '0' + ap[x - i - 1] - '0' + c;

        // If the sum is greater than 9, set carry to 1 and append the tens digit
        if (d > 9) {
            s[x - i] = d - 10 + '0';
            c = 1;
        } else {
            // Otherwise, append the sum and set carry to 0
            s[x - i] = d + '0';
            c = 0;
        }
    }

    // If there's a carry left after the final addition, append '1'
    if (c == 1) {
        s[0] = '1';
    } else {
        // Shift the result to the left if there's no carry
        memmove(s, s + 1, x + 1);
    }

    // Print the result as an integer
    printf("%d\n", atoi(s));

    return 0;
}
