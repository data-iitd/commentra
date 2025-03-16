#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    char c[n + 1];
    scanf("%s", c);
    int range[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &range[i][0], &range[i][1]);
    }
    int frag[n + 1];
    int rui[n + 1];
    memset(frag, 0, sizeof(frag));
    memset(rui, 0, sizeof(rui));
    for (int i = 2; i <= n; i++) {
        if (c[i - 2] == 'A' && c[i - 1] == 'C') {
            frag[i]++;
        }
        rui[i] = rui[i - 1] + frag[i];
    }
    for (int i = 0; i < q; i++) {
        int left = range[i][0];
        int right = range[i][1];
        printf("%d\n", rui[right] - rui[left]);
    }
    return 0;
}
