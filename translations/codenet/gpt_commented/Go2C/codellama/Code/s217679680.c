#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, tap = 0, consent = 1;
    scanf("%d %d", &a, &b);
    while (consent < b) {
        consent += a - 1;
        tap++;
    }
    printf("%d\n", tap);
    return 0;
}
