#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[1000], b[1000];
    char s[1001];
    int x, c = 0;

    // Read input and split into two strings a and b, removing the trailing newline
    scanf("%s %s", a, b);

    // Determine the maximum length of the two strings
    x = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);

    // Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 0; i < x - len_a; i++) {
        a[len_a + i] = '0';
    }
    a[len_a + x - len_a] = '\0';
    for (int i = 0; i < x - len_b; i++) {
        b[len_b + i] = '0';
    }
    b[len_b + x - len_b] = '\0';

    // Initialize an empty string to store the result and a carry variable
    s[x] = '\0';

    // Iterate over each digit from the least significant to the most significant
    for (int i = 0; i < x; i++) {
        // Calculate the sum of the corresponding digits and the carry
        int d = (b[x - i - 1] - '0') + (a[x - i - 1] - '0') + c;

        // Check if the sum exceeds 9, which requires a carry
        if (d > 9) {
            s[x - i - 1] = (d - 10) + '0';
            c = 1;  // Set carry to 1 for the next iteration
        } else {
            s[x - i - 1] = d + '0';
            c = 0;  // Reset carry to 0
        }
    }

    // If there's a carry left after the last addition, append '1' to the result
    if (c == 1) {
        printf("1%s\n", s);
    } else {
        printf("%s\n", s);
    }

    return 0;
}
