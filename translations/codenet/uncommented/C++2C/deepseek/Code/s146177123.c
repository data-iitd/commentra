#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool seg[][7] = {
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
            for (int i = 0; i < 7; i++) {
                ans[i] = st[i] ^ seg[t][i] ? '1' : '0';
                st[i] = seg[t][i];
            }
            printf("%s\n", ans);
        }
    }
    return 0;
}
