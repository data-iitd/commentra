
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char u[100];
    int a, b;

    // Read a line of input and store it in the array'str'
    fgets(str, 100, stdin);

    // Read another line of input and store it in the array 'u'
    fgets(u, 100, stdin);

    // Read the next line of input and parse the first token as an integer and store it in variable 'a'
    scanf("%d", &a);

    // Read the next line of input and parse the second token as an integer and store it in variable 'b'
    scanf("%d", &b);

    // Compare the string 'u' with the first element of the array'str'
    // Print the result based on the comparison
    if (strcmp(u, str) == 0) {
        printf("%d %d\n", a - 1, b);
    } else {
        printf("%d %d\n", a, b - 1);
    }

    return 0;
}
// END-OF-CODE