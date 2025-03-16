#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", 360 / gcd(360, x));
    return 0;
}

