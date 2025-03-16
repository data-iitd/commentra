#include <stdio.h>
#include <string.h>

int main() {
    char n[10];  // Declare a character array to store the input string.
    char *a[] = {"10", "100", "1000", "10000", "100000"};  // Define an array of strings.
    int new = 0;  // Initialize a variable to store the sum of digits.

    // Taking an input from the user and storing it in the variable `n`.
    printf("Enter a number: ");
    scanf("%s", n);

    // Converting the input `n` to a list of its digits and summing them up.
    for (int i = 0; i < strlen(n); i++) {
        new += n[i] - '0';  // Convert character to integer and add to `new`.
    }

    // Checking if the input `n` is in the list `a`.
    int found = 0;  // Flag to check if `n` is found in `a`.
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {  // Compare strings.
            found = 1;  // Set flag if found.
            break;
        }
    }

    // If `n` is in `a`, print 10; otherwise, print the value of `new`.
    if (found) {
        printf("10\n");
    } else {
        printf("%d\n", new);
    }

    return 0;
}
