#include <stdio.h>
#include <string.h>

int main() {
    char n[100];  // Declaring a character array `n` to store the input.
    fgets(n, sizeof(n), stdin);  // Reading the input from the user and storing it in `n`.
    char *a[] = {"10", "100", "1000", "10000", "100000"};  // Declaring an array of string pointers `a`.
    int new = 0;  // Declaring an integer `new` to store the sum of digits.
    int len = strlen(n);  // Getting the length of the input `n`.

    // Removing the newline character if present.
    if (n[len - 1] == '\n') {
        n[len - 1] = '\0';
        len--;
    }

    // Calculating the sum of digits.
    for (int i = 0; i < len; i++) {
        new += n[i] - '0';
    }

    // Checking if the input `n` is in the array `a`.
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            found = 1;
            break;
        }
    }

    // Printing the result based on the conditions.
    if (found) {
        printf("10\n");
    } else {
        printf("%d\n", new);
    }

    return 0;
}
