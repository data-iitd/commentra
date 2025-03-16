#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char n[10];
    scanf("%s", n);
    
    char *a[] = { "10", "100", "1000", "10000", "100000" };
    int new = 0;

    // Calculate the sum of the digits in the input string
    for (int i = 0; n[i] != '\0'; i++) {
        new += n[i] - '0'; // Convert char to int
    }

    // Check if n is in the array a
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("10\n");
    } else {
        printf("%d\n", new);
    }

    return 0;
}
