
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the input from the standard input
    char a[100001];
    fgets(a, 100001, stdin);

    // Check if the string contains any '1' character
    int has_one = 0;
    for (int i = 0; a[i]!= '\0'; i++) {
        if (a[i] == '1') {
            has_one = 1;
            break;
        }
    }

    // If it doesn't, print 0 and exit the program
    if (!has_one) {
        printf("0\n");
        return 0;
    }

    // If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
    int product_of_zeros = 1;
    int current_zeros = 0;
    for (int i = 0; a[i]!= '\0'; i++) {
        if (a[i] == '0') {
            current_zeros++;
        } else if (a[i] == '1') {
            product_of_zeros *= (current_zeros + 1);
            current_zeros = 0;
        }
    }

    // Finally, print the result
    printf("%d\n", product_of_zeros);

    return 0;
}
