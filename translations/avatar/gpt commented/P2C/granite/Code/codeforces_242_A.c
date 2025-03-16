
#include <stdio.h>

int main() {
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);

    int games = 0;
    for (int i = a; i <= x; i++) {
        if (i <= b) {
            continue;
        }
        for (int j = b; j <= y; j++) {
            if (i > j) {
                games++;
            }
        }
    }

    printf("%d\n", games);

    for (int i = a; i <= x; i++) {
        if (i <= b) {
            continue;
        }
        for (int j = b; j <= y; j++) {
            if (i > j) {
                printf("%d %d\n", i, j);
            }
        }
    }

    return 0;
}
