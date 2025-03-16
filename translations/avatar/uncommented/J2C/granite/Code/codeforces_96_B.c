
#include <stdio.h>
#include <string.h>

int main() {
    long number;
    scanf("%ld", &number);
    long ans = -1, value = 0;
    int mask = 2;
    while (value < number) {
        char s[64];
        sprintf(s, "%d", mask++);
        int zeros = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '0') zeros++;
        }
        if (zeros!= strlen(s) - zeros) continue;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '0') s[i] = '4';
            else s[i] = '7';
        }
        sscanf(s, "%ld", &value);
    }
    printf("%ld\n", value);
    return 0;
}
// END-OF-CODE