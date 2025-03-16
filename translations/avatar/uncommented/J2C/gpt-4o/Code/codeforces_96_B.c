#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long number;
    scanf("%ld", &number);
    long ans = -1, value = 0;
    int mask = 2;

    while (value < number) {
        char s[64]; // Buffer to hold the binary string
        itoa(mask++, s, 2); // Convert mask to binary string
        memmove(s, s + 1, strlen(s)); // Remove the first character

        int zeros = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') {
                zeros++;
            }
        }

        if (zeros != strlen(s) - zeros) continue;

        // Replace '0' with '4' and '1' with '7'
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') {
                s[i] = '4';
            } else if (s[i] == '1') {
                s[i] = '7';
            }
        }

        value = strtol(s, NULL, 10); // Convert the modified string to long
    }

    printf("%ld\n", value);
    return 0;
}

// <END-OF-CODE>
