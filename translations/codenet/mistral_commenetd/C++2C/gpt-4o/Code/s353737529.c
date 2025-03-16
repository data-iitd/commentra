#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int main(void) {
    // Input the number of digits in binary representation
    ll n;
    scanf("%lld", &n);

    // Initialize an empty string 's' to store binary representation
    char s[65]; // Enough to hold binary representation of a 64-bit integer
    int index = 0;

    // Check if the number is zero and print '0' if it is
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    // Iterate through the number from the least significant bit to the most significant bit
    while (n != 0) {
        // If the number is even, add '0' to the binary representation
        if (n % 2 == 0) {
            s[index++] = '0';
        } else {
            // If the number is odd, add '1' to the binary representation
            s[index++] = '1';
        }

        // Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
        n -= abs(n % 2);

        // Update the number by dividing it by -2
        n /= -2;
    }

    // Reverse the binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = s[i];
        s[i] = s[index - 1 - i];
        s[index - 1 - i] = temp;
    }

    // Null-terminate the string
    s[index] = '\0';

    // Print the binary representation
    printf("%s\n", s);

    return 0;
}

// <END-OF-CODE>
