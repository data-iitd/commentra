#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

int nextInt() {
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    return atoi(buffer);
}

char* next() {
    char* line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

void solve() {
    int x = nextInt();
    int t;
    int a, b, da, db;
    scanf("%d %d %d %d %d", &t, &a, &b, &da, &db);

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

    if (ok) printf("YES\n");
    else printf("NO\n");
}

int main() {
    solve();
    return 0;
}

