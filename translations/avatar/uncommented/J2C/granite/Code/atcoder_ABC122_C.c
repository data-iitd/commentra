
#include <stdio.h>
#include <string.h>
#define mod 1000000007

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    char c[n];
    scanf("%s", c);
    int range[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &range[i][0], &range[i][1]);
    }
    int frag[n + 1];
    memset(frag, 0, sizeof(frag));
    for (int i = 2; i <= n; i++) {
        if (c[i - 2] == 'A' && c[i - 1] == 'C') {
            frag[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        frag[i] += frag[i - 1];
    }
    for (int i = 0; i < q; i++) {
        int left = range[i][0];
        int right = range[i][1];
        printf("%d\n", frag[right] - frag[left]);
    }
    return 0;
}
//END-OF-CODE