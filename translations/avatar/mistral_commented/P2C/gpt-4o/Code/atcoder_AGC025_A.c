#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Take an input from the user and assign it to the variable 'n'
    char n[10];
    scanf("%s", n);

    // Initialize a list 'a' with some strings representing numbers
    const char *a[] = { "10", "100", "1000", "10000", "100000" };
    int isPresent = 0;

    // Check if the input 'n' is present in the list 'a'
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            isPresent = 1;
            break;
        }
    }

    // Convert each character of the input 'n' to an integer and sum them up
    int new = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        new += n[i] - '0'; // Convert char to int
    }

    // If the input 'n' is present in the list 'a', then print the number 10
    if (isPresent) {
        printf("10\n");
    } else {
        // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
        printf("%d\n", new);
    }

    return 0;
}

// <END-OF-CODE>
