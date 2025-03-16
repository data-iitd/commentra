#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool seg[7][7] = {
    {0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 0},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 1},
    {0, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1}
};

int main() {
    int n, t;
    bool st[7];

    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < 7; i++) st[i] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            char ans[8] = {0};
            for (int j = 0; j < 7; j++) {
                ans[j] = st[j] ^ seg[t][j] ? '1' : '0';
                st[j] = seg[t][j];
            }
            printf("%s\n", ans);
        }
    }

    return 0;
}
