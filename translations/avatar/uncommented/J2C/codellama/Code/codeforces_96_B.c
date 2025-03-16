#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long number;
    long ans = -1;
    long value = 0;
    int mask = 2;
    while (value < number) {
        char s[100];
        int zeros = 0;
        sprintf(s, "%d", mask++);
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') zeros++;
        }
        if (zeros != strlen(s) - zeros) continue;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') s[i] = '4';
            else s[i] = '7';
        }
        value = atol(s);
    }
    printf("%ld\n", value);
    return 0;
}

