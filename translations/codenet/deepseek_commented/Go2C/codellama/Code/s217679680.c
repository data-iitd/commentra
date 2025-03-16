#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a, b, tap = 0, consent = 1;
    scanf("%d %d", &a, &b);
    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }
    printf("%d\n", tap);
    return 0;
}
