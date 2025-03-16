#include <stdio.h> // Including standard input-output library

int main() {
    int n; // Variable to store the input integer
    scanf("%d", &n); // Reading an integer input
    char s[32]; // Array to store binary representation (assuming 32 bits)
    int index = 0; // Index for the binary string

    // Converting the integer to binary representation
    while (n > 0) {
        int x = n % 2; // Getting the remainder when divided by 2
        s[index++] = x + '0'; // Appending the remainder to the string
        n /= 2; // Dividing the number by 2
    }

    // Since we built the binary string in reverse order, we need to reverse it
    for (int i = 0; i < index / 2; i++) {
        char temp = s[i];
        s[i] = s[index - i - 1];
        s[index - i - 1] = temp;
    }
    s[index] = '\0'; // Null-terminating the string

    int ans = 0; // Initializing a variable to count the number of '1's

    // Counting the number of '1's in the binary representation
    for (int i = 0; i < index; i++) {
        if (s[i] == '1') {
            ans++; // Incrementing the count if the character is '1'
        }
    }

    printf("%d\n", ans); // Printing the count of '1's
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
