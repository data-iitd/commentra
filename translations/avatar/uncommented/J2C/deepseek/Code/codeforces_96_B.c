#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long number, ans = -1, value = 0;
    int mask = 2;
    char s[33];
    scanf("%ld", &number);
    while (value < number) {
        sprintf(s, "%b", mask++);
        int zeros = 0;
        for (int i = 1; s[i] != '\0'; i++) {
            if (s[i] == '0') zeros++;
        }
        if (zeros != strlen(s) - zeros - 1) continue;
        for (int i = 1; s[i] != '\0'; i++) {
            s[i] = (s[i] == '0') ? '4' : '7';
        }
        value = strtol(s, NULL, 10);
    }
    printf("%ld\n", value);
    return 0;
}
