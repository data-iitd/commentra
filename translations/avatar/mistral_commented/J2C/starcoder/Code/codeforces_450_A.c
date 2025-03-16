
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int n, m, i, ans = 0;
    scanf("%d %d", &n, &m);
    int *q1 = (int *)malloc(n * sizeof(int));
    int *q2 = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &q1[i]);
        q2[i] = i + 1;
    }
    while (true) {
        if (q1[0] <= m) {
            ans = q2[0];
            for (i = 1; i < n; i++) {
                q1[i - 1] = q1[i];
                q2[i - 1] = q2[i];
            }
            n--;
        } else if (q1[0] > m) {
            int x = q1[0];
            q1[0] = x - m;
            int val = q2[0];
            q2[0] = val;
        }
        if (n == 0) {
            break;
        }
    }
    printf("%d", ans);
    return 0;
}

