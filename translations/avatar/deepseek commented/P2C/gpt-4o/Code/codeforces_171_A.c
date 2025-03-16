#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[100], b[100];
    
    // Read input and split into two strings, a and b
    scanf("%s %s", a, b);
    
    // Determine the maximum length of the two strings
    int len_a = strlen(a);
    int len_b = strlen(b);
    int x = len_a > len_b ? len_a : len_b;

    // Pad the shorter string with zeros on the left
    char padded_a[100] = {0};
    char padded_b[100] = {0};
    memset(padded_a, '0', x - len_a);
    strcpy(padded_a + (x - len_a), a);
    memset(padded_b, '0', x - len_b);
    strcpy(padded_b + (x - len_b), b);

    // Initialize an empty string to store the result
    char s[101] = {0}; // Result can be at most x + 1 in length
    int c = 0; // Initialize carry to 0

    // Loop through each digit from right to left
    for (int i = 0; i < x; i++) {
        // Add the corresponding digits from a and b along with the carry
        int d = (padded_b[i] - '0') + (padded_a[x - i - 1] - '0') + c;

        // If the sum is greater than 9, set carry to 1 and append the tens digit
        if (d > 9) {
            s[i] = (d % 10) + '0'; // Append the units digit
            c = 1; // Set carry to 1
        } else {
            s[i] = d + '0'; // Append the sum
            c = 0; // Set carry to 0
        }
    }

    // If there's a carry left after the final addition, append '1'
    if (c == 1) {
        s[x] = '1'; // Append carry
        s[x + 1] = '\0'; // Null-terminate the string
    } else {
        s[x] = '\0'; // Null-terminate the string
    }

    // Reverse the result string and print it as an integer
    int result_length = strlen(s);
    for (int i = result_length - 1; i >= 0; i--) {
        putchar(s[i]);
    }
    putchar('\n');

    return 0;
}

// <END-OF-CODE>
