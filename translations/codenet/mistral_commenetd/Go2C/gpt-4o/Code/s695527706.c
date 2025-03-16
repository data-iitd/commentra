#include <stdio.h>
#include <string.h>

int main() {
    // Declare two variables, n and s
    int n;
    char s[100]; // Assuming the maximum length of s is 100

    // Read the input from the standard input
    scanf("%d %s", &n, s);

    // Count occurrences of "ABC" in the string s
    int count = 0;
    char *ptr = s;

    while ((ptr = strstr(ptr, "ABC")) != NULL) {
        count++;
        ptr++; // Move past the current occurrence
    }

    // Print the result
    printf("%d\n", count);

    return 0;
}

// <END-OF-CODE>
