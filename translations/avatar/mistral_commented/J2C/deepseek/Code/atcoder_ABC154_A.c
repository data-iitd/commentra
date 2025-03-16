#include <stdio.h>
#include <string.h>

int main() {
    int a, b;
    char str[100][100], u[100];

    // Reading the first line of input as an array of strings
    fgets(str[0], sizeof(str[0]), stdin);

    // Reading the second line of input as separate tokens
    scanf("%d %d", &a, &b);

    // Reading the third line of input as a string
    fgets(u, sizeof(u), stdin);

    // Removing the newline character from the end of the string
    u[strcspn(u, "\n")] = 0;

    // Checking if the first string from the first line matches with the given string 'u'
    if (strcmp(u, str[0]) == 0) {
        // If the condition is true, then print the result as (a-1) and b
        printf("%d %d\n", a - 1, b);
    } else {
        // If the condition is false, then print the result as a and (b-1)
        printf("%d %d\n", a, b - 1);
    }

    return 0;
}
