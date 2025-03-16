#include <stdio.h>

int main() {
    int x, t, a, b, da, db;
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    if (x == 0) {
        printf("YES\n");
        return 0;
    }

    int a_time = (a / da < t - 1) ? a / da : t - 1;
    int b_time = (b / db < t - 1) ? b / db : t - 1;

    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            if (a - da * i == x || b - db * j == x) {
                printf("YES\n");
                return 0;
            }
            if ((a - da * i) + (b - db * j) == x) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
// <END-OF-CODE>
