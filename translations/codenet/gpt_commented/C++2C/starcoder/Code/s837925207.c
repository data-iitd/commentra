#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, ans = 0;

    scanf("%d", &x);

    ans = x + x*x + x*x*x;

    printf("%d\n", ans);

    return 0;
}

