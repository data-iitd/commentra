#include <stdio.h>

int main() {
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    int cookie = 0;
    int time = a;
    while (time <= t + 0.5) {
        cookie += b;
        time += a;
    }
    printf("%d\n", cookie);
    return 0;
}
