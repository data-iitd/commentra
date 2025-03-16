#include <stdio.h>

int main() {
    long pandu, vundu, urdu, c = 0;
    scanf("%ld %ld %ld", &pandu, &vundu, &urdu);
    for (int i = 1; i <= urdu; i++) {
        c += i * pandu;
    }
    if (c < vundu) {
        printf("0\n");
    } else {
        printf("%ld\n", c - vundu);
    }
    return 0;
}
