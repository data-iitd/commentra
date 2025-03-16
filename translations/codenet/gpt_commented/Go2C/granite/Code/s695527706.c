
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100];

    // Read input values for n and s from the standard input
    scanf("%d %s", &n, s);

    // Count and print the number of occurrences of the substring "ABC" in the string s
    printf("%d\n", (int)strstr(s, "ABC") - s + 1);

    return 0;
}
