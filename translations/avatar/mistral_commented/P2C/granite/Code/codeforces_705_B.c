
#include <stdio.h>

int main() {
    int n, c = 2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        if (w == 1) {
            printf("%d\n", c);
        } else if (w % 2 == 0) {
            c = 3 - c;
            printf("%d\n", c);
        } else {
            printf("%d\n", c);
        }
    }
    return 0;
}
