#include <stdio.h>
#include <string.h>

int main() {
    int a, b;
    char S[2];
    while (1) {
        scanf("%d %s %d", &a, S, &b);
        if (S[0] == '+') printf("%d\n", a + b);
        if (S[0] == '-') printf("%d\n", a - b);
        if (S[0] == '*') printf("%d\n", a * b);
        if (S[0] == '/') printf("%d\n", a / b);
        if (S[0] == '?') break;
    }
