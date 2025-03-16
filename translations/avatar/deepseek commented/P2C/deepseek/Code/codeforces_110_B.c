#include <stdio.h>
#include <string.h>

int main() {
    char LUCKY[] = "abcd";
    int n;
    char s[1000]; // Assuming the maximum length of s will not exceed 1000
    int i;

    scanf("%d", &n);
    s[0] = '\0'; // Initialize the string s as empty

    for (i = 0; i < n; i++) {
        strncat(s, &LUCKY[i % 4], 1);
    }

    printf("%s\n", s);
    return 0;
}
