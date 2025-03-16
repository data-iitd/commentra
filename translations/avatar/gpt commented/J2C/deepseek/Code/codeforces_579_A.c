#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, ans = 0;
    char *s = (char *)malloc(32 * sizeof(char)); // Allocating memory for the binary string

    // Reading an integer input from the user
    scanf("%d", &n);

    // Initializing an empty string to store the binary representation
    // s = ""; // In C, we don't need to initialize s as it's already done in the malloc call

    // Converting the integer n to its binary representation
    int i = 0;
    while (n > 0) {
        x = n % 2; // Getting the least significant bit (0 or 1)
        n /= 2; // Dividing n by 2 to process the next bit
        s[i++] = x + '0'; // Appending the bit to the binary string
    }
    s[i] = '\0'; // Null-terminating the string

    // Iterating through the binary string to count '1's
    for (int j = 0; s[j] != '\0'; j++) {
        if (s[j] == '1') { // Checking if the current character is '1'
            ans++; // Incrementing the count of '1's
        }
    }

    // Printing the total count of '1's in the binary representation
    printf("%d\n", ans);

    // Freeing the allocated memory
    free(s);

    return 0;
}
