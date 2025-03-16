#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *q1 = (int *)malloc(n * sizeof(int));
    int *q2 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &q1[i]);
        q2[i] = i + 1;
    }
    int ans = 0;
    while (n > 0) {
        if (q1[0] <= m) {
            ans = q2[0];
            for (int i = 1; i < n; i++) {
                q1[i - 1] = q1[i];
                q2[i - 1] = q2[i];
            }
            n--;
        } else if (q1[0] > m) {
            q1[0] -= m;
            int temp = q1[0];
            for (int i = 1; i < n; i++) {
                q1[i - 1] = q1[i];
            }
            q1[n - 1] = temp;
            int temp2 = q2[0];
            for (int i = 1; i < n; i++) {
                q2[i - 1] = q2[i];
            }
            q2[n - 1] = temp2;
        }
    }
    printf("%d\n", ans);
    free(q1);
    free(q2);
    return 0;
}
