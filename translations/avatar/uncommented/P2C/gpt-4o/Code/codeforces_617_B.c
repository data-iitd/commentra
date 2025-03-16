#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[100]; // Assuming the input string will not exceed 99 characters
    fgets(a, sizeof(a), stdin); // Read input

    // Remove trailing newline character if present
    size_t len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }

    // Count occurrences of '1'
    int count_one = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == '1') {
            count_one++;
        }
    }

    if (count_one == 0) {
        printf("0\n");
    } else {
        int product = 1;
        char *token = strtok(a, "1");
        while (token != NULL) {
            // Count '0's in the token
            int count_zero = 0;
            for (int i = 0; token[i] != '\0'; i++) {
                if (token[i] == '0') {
                    count_zero++;
                }
            }
            product *= (count_zero + 1);
            token = strtok(NULL, "1");
        }
        printf("%d\n", product);
    }

    return 0;
}

// <END-OF-CODE>
