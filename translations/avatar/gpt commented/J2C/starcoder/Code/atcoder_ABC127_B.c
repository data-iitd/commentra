#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int r, d;
    long x;
    scanf("%d %d %ld", &r, &d, &x);
    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        printf("%ld\n", x);
    }
    return 0;
}
