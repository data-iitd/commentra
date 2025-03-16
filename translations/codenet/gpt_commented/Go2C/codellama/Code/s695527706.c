#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100];

    // Read input values for n and s from the standard input
    scanf("%d %s", &n, s);

    // Count and print the number of occurrences of the substring "ABC" in the string s
    printf("%d\n", count_substring(s, "ABC"));

    return 0;
}

int count_substring(char *s, char *substring) {
    int count = 0;
    int substring_length = strlen(substring);
    int s_length = strlen(s);

    for (int i = 0; i < s_length; i++) {
        if (strncmp(s + i, substring, substring_length) == 0) {
            count++;
        }
    }

    return count;
}

