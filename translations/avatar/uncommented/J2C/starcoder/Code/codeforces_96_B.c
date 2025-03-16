#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long number;
    scanf("%ld", &number);
    long ans = -1, value = 0;
    int mask = 2;
    while (value < number) {
        char s[100];
        sprintf(s, "%d", mask++);
        int zeros = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') zeros++;
        }
        if (zeros!= strlen(s) - zeros) continue;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') s[i] = '4';
            else s[i] = '7';
        }
        value = atol(s);
    }
    printf("%ld\n", value);
    return 0;
}

