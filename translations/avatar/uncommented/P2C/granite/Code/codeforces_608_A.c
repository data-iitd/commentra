
#include <stdio.h>

int main() {
    int n, s, f, t, c = 0, x;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &f, &t);
        x = t - (s - f);
        if (x > c) {
            c = x;
        }
    }
    printf("%d\n", s + c);
    return 0;
}
// END-OF-CODE