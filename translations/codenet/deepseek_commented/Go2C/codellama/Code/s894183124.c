#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100];

    // Declare variables to store the input values.
    // `n` will store the integer input and `s` will store the string input.
    scanf("%d", &n);
    scanf("%s", &s);

    // Read an integer `n` and a string `s` from the standard input.
    // The format specifier "%d" is used to read an integer, and "%s" is used to read a string.

    // Print the number of occurrences of the substring "ABC" in the string `s`.
    // The `strstr` function is used to count the occurrences of the substring "ABC".
    printf("%d\n", strstr(s, "ABC"));

    return 0;
}

