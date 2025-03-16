
#include <stdio.h>
#include <string.h>

int main() {
    // Declare two variables, n and s
    int n;
    char s[100];

    // Read the input from the standard input
    scanf("%d %s", &n, s);

    // Print the result of the strings.Count function
    printf("%d\n", (int)strstr(s, "ABC") - s + 1);

    return 0;
}

// This is the end of the code
