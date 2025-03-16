#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input from the user
    char n[10];
    scanf("%s", n);

    // Define a list of string representations of powers of ten
    const char *a[] = {"10", "100", "1000", "10000", "100000"};
    int is_in_a = 0;

    // Check if the input is one of the predefined values in the list 'a'
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            is_in_a = 1;
            break;
        }
    }

    if (is_in_a) {
        // If the input matches one of the predefined values, print 10
        printf("10\n");
    } else {
        // Convert the input string into a list of integers and calculate the sum
        int sum = 0;
        for (int i = 0; n[i] != '\0'; i++) {
            sum += n[i] - '0'; // Convert char to int
        }
        // Print the calculated sum
        printf("%d\n", sum);
    }

    return 0;
}

// <END-OF-CODE>
