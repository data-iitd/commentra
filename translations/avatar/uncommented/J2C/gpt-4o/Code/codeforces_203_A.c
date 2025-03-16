#include <stdio.h>

void solve() {
    int x, t, a, b, da, db;
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);
    int first, second;
    int ok = 0; // Using 0 for false, 1 for true

    for (int i = 0; i < t; i++) {
        first = a - (da * i);
        for (int j = 0; j < t; j++) {
            second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0) {
                ok = 1; // Set to true
                break;
            }
        }
        if (ok) break; // Break outer loop if found
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

// <END-OF-CODE>
