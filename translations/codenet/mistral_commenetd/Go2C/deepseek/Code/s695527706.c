#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100];

    // Read the input from the standard input
    scanf("%d %s", &n, s);

    // Declare a variable to count the number of occurrences of "ABC"
    int count = 0;

    // Use strstr to find occurrences of "ABC" in the string s
    char *ptr = s;
    while ((ptr = strstr(ptr, "ABC")) != NULL) {
        count++;
        ptr++; // Move to the next character to continue searching
    }

    // Print the result
    printf("%d\n", count);

    return 0;
}
