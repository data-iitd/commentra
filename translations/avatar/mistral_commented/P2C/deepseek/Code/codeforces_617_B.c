#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[1000];
    fgets(a, sizeof(a), stdin);

    // Remove newline character if present
    size_t len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }

    // Check if the string contains any '1' character
    if (strchr(a, '1') == NULL) {
        // If it doesn't, print 0 and exit the program
        printf("0\n");
        return 0;
    }

    // Split the string by '1' and calculate the product of the number of zeros in each segment
    char *token = strtok(a, "1");
    int product_of_zeros = 1;
    while (token != NULL) {
        int count_zeros = 0;
        for (int i = 0; i < strlen(token); i++) {
            if (token[i] == '0') {
                count_zeros++;
            }
        }
        product_of_zeros *= (count_zeros + 1);
        token = strtok(NULL, "1");
    }

    // Print the result
    printf("%d\n", product_of_zeros);

    return 0;
}
