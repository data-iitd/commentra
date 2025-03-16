

#include <stdio.h>
#include <string.h>

int main() {
    char n[100];  // Declaring a character array `n` to store the input from the user.
    int a[] = {10, 100, 1000, 10000, 100000};  // Defining an integer array `a` containing the numbers 10, 100, 1000, 10000, and 100000.
    int new = 0;  // Declaring an integer variable `new` to store the sum of the digits of the input `n`.
    int i;  // Declaring an integer variable `i` to be used in a loop.

    printf("Enter a number: ");  // Prompt the user to enter a number.
    scanf("%s", n);  // Read the input from the user and store it in the character array `n`.

    for (i = 0; n[i]!= '\0'; i++) {  // Iterate over each character in the input `n`.
        new += n[i] - '0';  // Convert the current character to an integer and add it to `new`.
    }

    if (strstr(n, "10")!= NULL || strstr(n, "100")!= NULL || strstr(n, "1000")!= NULL || strstr(n, "10000")!= NULL || strstr(n, "100000")!= NULL) {  // Check if the input `n` contains the strings "10", "100", "1000", "10000", or "100000".
        printf("10\n");  // If `n` contains one of these strings, print the number 10.
    } else {
        printf("%d\n", new);  // Otherwise, print the value of `new`.
    }

    return 0;
}

