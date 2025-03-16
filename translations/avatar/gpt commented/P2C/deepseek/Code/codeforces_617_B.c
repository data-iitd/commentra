#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[1000];  // Define a character array to store the input string
    fgets(a, sizeof(a), stdin);  // Read a line of input from the user

    // Remove newline character if present
    size_t len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }

    // Check if the string contains any '1's
    // If there are no '1's, print 0
    // Otherwise, calculate the product of counts of '0's between '1's
    if (strchr(a, '1') == NULL) {
        printf("0\n");
    } else {
        // Split the input string by '1's, count '0's in each segment, add 1 to each count,
        // and calculate the product of these counts
        char *token = strtok(a, "1");
        int product = 1;
        while (token != NULL) {
            product *= (strspn(token, "0") + 1);
            token = strtok(NULL, "1");
        }
        printf("%d\n", product);
    }

    return 0;
}
