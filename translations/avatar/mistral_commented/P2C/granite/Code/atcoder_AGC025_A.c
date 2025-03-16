
#include <stdio.h>
#include <string.h>

int main() {
    // Take an input from the user and assign it to the variable 'n'
    char n[100];
    scanf("%s", n);

    // Initialize a list 'a' with some strings representing numbers
    char *a[] = { "10", "100", "1000", "10000", "100000" };

    // Initialize a variable 'new' to store the sum of the integers in the input 'n'
    int new = 0;

    // Iterate over each character in the input 'n'
    for (int i = 0; i < strlen(n); i++) {
        // Convert the current character to an integer and add it to the variable 'new'
        new += n[i] - '0';
    }

    // Check if the input 'n' is present in the list 'a'
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            // If the input 'n' is present in the list 'a', then set the variable 'found' to 1
            found = 1;
            break;
        }
    }

    // If the input 'n' is present in the list 'a', then print the number 10
    if (found == 1) {
        printf("10\n");
    } else {
        // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
        printf("%d\n", new);
    }

    return 0;
}
