#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char c[100];
    long k;
    int n;

    // Read the first line of input as a string
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    // Convert the string to a character array
    strcpy(c, str);

    // Read the second line of input as a long integer
    scanf("%ld", &k);

    // Find the length of the string
    n = strlen(str);

    // Iterate through the character array up to the given limit 'k'
    for (int i = 0; i < k; i++) {
        if (c[i] == '1') {
            if (i == k - 1) {
                printf("1\n");
                return 0;
            }
        } else {
            printf("%c\n", c[i]);
            return 0;
        }
    }
}
