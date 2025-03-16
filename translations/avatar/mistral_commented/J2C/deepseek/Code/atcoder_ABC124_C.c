#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    char x[100001];
    int a1 = 0, a2 = 0;

    // Read the input string
    scanf("%s", x);

    // Create two strings 'a' and 'b' with the same content as 'x'
    char a[100001], b[100001];
    strcpy(a, x);
    strcpy(b, x);

    // Loop through each character in string 'a' starting from index 1
    for (int i = 1; i < strlen(x); i++) {
        if (a[i] == a[i - 1]) {
            a[i] = a[i] == '1' ? '0' : '1';
            a1++;
        }
    }

    // Loop through each character in string 'b' starting from the last character
    for (int i = strlen(x) - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            b[i - 1] = b[i - 1] == '1' ? '0' : '1';
            a2++;
        }
    }

    // Print the minimum number of consecutive '1's in strings 'a' and 'b'
    printf("%d\n", min(a1, a2));

    return 0;
}

