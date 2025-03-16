#include <stdio.h>
#include <string.h>

int main() {
    char a[1000], b[1000];
    char s[1001];
    int x, c = 0;

    // Reading input from stdin
    scanf("%s %s", a, b);

    // Finding the maximum length between 'a' and 'b'
    x = strlen(a) > strlen(b) ? strlen(a) : strlen(b);

    // Padding zeros to the shorter string
    for (int i = 0; i < x; i++) {
        if (i < strlen(a)) {
            a[i] = a[i];
        } else {
            a[i] = '0';
        }
        if (i < strlen(b)) {
            b[i] = b[i];
        } else {
            b[i] = '0';
        }
    }
    a[x] = '\0';
    b[x] = '\0';

    // Initializing the result string 's'
    s[x + 1] = '\0';

    // Iterating through each index 'i' in the range of the length of the padded strings 'x'
    for (int i = 0; i < x; i++) {
        // Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
        int d = (a[x - i - 1] - '0') + (b[x - i - 1] - '0') + c;

        // If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
        if (d > 9) {
            s[x - i] = (d - 10) + '0';
            c = 1;
        } else {
            // If the sum is less than or equal to 9, add the digit to the result string 's'
            s[x - i] = d + '0';
            c = 0;
        }
    }

    // If there is still a carry left, add it to the result string 's'
    if (c == 1) {
        s[0] = '1';
    } else {
        // Shift the result string to remove the leading zero if there is no carry
        for (int i = 0; i < x; i++) {
            s[i] = s[i + 1];
        }
    }

    // Printing the final result
    printf("%s\n", s);

    return 0;
}
