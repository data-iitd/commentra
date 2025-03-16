
#include <stdio.h>
#include <string.h>

int main() {
    // Declare and initialize two variables: n of type int and s of type string
    int n;
    char s[100];

    // Use the scanf function to read input from the standard input
    scanf("%d", &n);
    scanf("%s", s);

    // Use the printf function to compute and print the result
    printf("%d\n", (int)strstr(s, "ABC") - s + 1);

    // End of code
    return 0;
}

// End of code