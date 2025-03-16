#include <stdio.h>

int main() {
    int v1, v2, t, d;
    scanf("%d %d", &v1, &v2);
    scanf("%d %d", &t, &d);

    int a = 1;
    int v = v1;
    int distance = 0;

    for (int i = 0; i < t; i++) {
        if (v - v2 > (t - i - 1) * d) {
            a *= -1;
            v = (t - i - 1) * d + v2;
        }
        distance += v;
        v += a * d;
    }

    printf("%d\n", distance);
    return 0;
}
