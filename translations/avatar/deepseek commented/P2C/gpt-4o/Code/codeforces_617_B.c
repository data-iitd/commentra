#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Take an input from the user and store it in variable 'a'
    char a[100]; // Assuming the input will not exceed 99 characters
    fgets(a, sizeof(a), stdin);

    // Remove trailing newline character from fgets
    a[strcspn(a, "\n")] = 0;

    // Count the number of '1's in the input
    int count_ones = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == '1') {
            count_ones++;
        }
    }

    // If there are no '1's, print 0
    if (count_ones == 0) {
        printf("0\n");
        return 0;
    }

    // Calculate the product of (count of '0's + 1) for each segment between '1's
    int product = 1;
    char *token = strtok(a, "1");
    while (token != NULL) {
        int count_zeros = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (token[i] == '0') {
                count_zeros++;
            }
        }
        product *= (count_zeros + 1);
        token = strtok(NULL, "1");
    }

    // Print the result
    printf("%d\n", product);
    return 0;
}

// <END-OF-CODE>
