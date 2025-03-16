#include <stdio.h>

int main() {
    int a, b;
    char S;
    while (1) {
        scanf("%d %c %d", &a, &S, &b);
        if (S == '+') printf("%d\n", a + b);
        if (S == '-') printf("%d\n", a - b);
        if (S == '*') printf("%d\n", a * b);
        if (S == '/') printf("%d\n", a / b);
        if (S == '?') break;
    }
    return 0;
}

// <END-OF-CODE>
