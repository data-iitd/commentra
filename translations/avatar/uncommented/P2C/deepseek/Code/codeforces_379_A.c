#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int s = 0;
    int restoSciolte = 0;
    while (a > 0 || restoSciolte >= b) {
        a += restoSciolte / b;
        restoSciolte %= b;
        s += a;
        restoSciolte += a % b;
        a /= b;
    }
    printf("%d\n", s);
    return 0;
}
