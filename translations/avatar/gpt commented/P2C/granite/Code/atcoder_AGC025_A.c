
#include <stdio.h>
#include <string.h>

int main() {
    char n[100];
    int a[5] = {10, 100, 1000, 10000, 100000};
    int i, j, sum = 0;

    // Read input from the user
    scanf("%s", n);

    // Calculate the sum of the digits in the input string
    for (i = 0; i < strlen(n); i++) {
        sum += n[i] - '0';
    }

    // Check if the input is one of the predefined values in the array 'a'
    for (j = 0; j < 5; j++) {
        if (strcmp(n, a[j]) == 0) {
            // If the input matches one of the predefined values, print 10
            printf("10\n");
            break;
        }
    }

    // If the input does not match, print the calculated sum
    if (j == 5) {
        printf("%d\n", sum);
    }

    return 0;
}
