
#include <stdio.h>

int main() {
    int N, d, x;
    scanf("%d %d %d", &N, &d, &x);

    int ret = 0;
    while (N) {
        ret += d + (N - 0.5) * x;

        d = d + (d / N) + (5 * x) / (2 * N);
        x += 2 * x / N;

        N--;
    }

    printf("%d\n", ret);
    return 0;
}
// END-OF-CODE