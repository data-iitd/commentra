
#include <stdio.h>

int main() {
    int a, b, t, cookie = 0, time = 0;
    scanf("%d %d %d", &a, &b, &t);
    while (time <= t) {
        cookie += b;
        time += a;
    }
    printf("%d\n", cookie);
    return 0;
}
// END-OF-CODE