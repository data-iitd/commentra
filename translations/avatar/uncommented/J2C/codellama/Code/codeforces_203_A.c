
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x, t, a, b, da, db, first, second, ok;
    char line[100];

    fgets(line, 100, stdin);
    sscanf(line, "%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    for (int i = 0; i < t; i++) {
        first = a - (da * i);
        for (int j = 0; j < t; j++) {
            second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0) {
                ok = 1;
                break;
            }
        }
    }

    if (ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

