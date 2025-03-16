
#include <stdio.h>

int main() {
    int x, t, a, b, da, db;
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    int first, second;
    int ok = 0;

    for (int i = 0; i < t; i++) {
        first = a - (da * i);
        for (int j = 0; j < t; j++) {
            second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0) {
                ok = 1;
                break;
            }
        }
        if (ok) break;
    }

    if (ok) printf("YES");
    else printf("NO");

    return 0;
}
