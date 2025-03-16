#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int x = 1;

    while (log2(n) - (int)log2(n) != 0) {
        x += 1;
        n -= (int)pow(2, (int)log2(n));
    }

    printf("%d\n", x);
    return 0;
}

// <END-OF-CODE>
