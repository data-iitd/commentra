#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[100], b[100];
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);
    
    // Remove newline characters
    a[strcspn(a, "\n")] = 0;
    b[strcspn(b, "\n")] = 0;

    int len_a = strlen(a);
    int len_b = strlen(b);
    int x = len_a > len_b ? len_a : len_b;

    // Right justify a and left justify b with '0'
    char a_justified[100], b_justified[100];
    snprintf(a_justified, sizeof(a_justified), "%0*s", x, a);
    snprintf(b_justified, sizeof(b_justified), "%-*s", x, b);

    char s[101] = {0}; // To store the result
    int c = 0; // Carry
    for (int i = 0; i < x; i++) {
        int d = (b_justified[i] - '0') + (a_justified[x - i - 1] - '0') + c;
        if (d > 9) {
            s[i] = (d % 10) + '0'; // Store the last digit
            c = 1; // Set carry
        } else {
            s[i] = d + '0'; // Store the sum
            c = 0; // No carry
        }
    }
    if (c == 1) {
        s[x] = '1'; // If there's a carry at the end
        s[x + 1] = '\0'; // Null terminate the string
    } else {
        s[x] = '\0'; // Null terminate the string
    }

    // Reverse the result string
    int len_s = strlen(s);
    for (int i = 0; i < len_s / 2; i++) {
        char temp = s[i];
        s[i] = s[len_s - i - 1];
        s[len_s - i - 1] = temp;
    }

    // Print the result as an integer
    printf("%d\n", atoi(s));

    return 0;
}
// <END-OF-CODE>
