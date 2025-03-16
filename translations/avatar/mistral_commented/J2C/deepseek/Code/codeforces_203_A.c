#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

void solve() {
    int x = nextInt();
    int t = nextInt();
    int a = nextInt();
    int b = nextInt();
    int da = nextInt();
    int db = nextInt();

    int first = 0;
    int second = 0;
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

    if (ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    solve();
    return 0;
}

