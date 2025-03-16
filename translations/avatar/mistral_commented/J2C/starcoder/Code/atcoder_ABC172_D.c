#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;
    long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++) {
        ans += (long) i * (n / i) * ((n / i) + 1) / 2;
    }
    printf("%ld\n", ans);
    return EXIT_SUCCESS;
}

