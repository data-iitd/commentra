#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    long long ans[n];
    long long* q = (long long*)malloc(n * sizeof(long long));
    int q_size = 0;

    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);

        while (q_size > 0 && q[0] <= t) {
            q_size--;
            for (int j = 0; j < q_size; j++) {
                q[j] = q[j + 1];
            }
        }

        if (q_size < b) {
            if (q_size == 0) {
                ans[i] = t + d;
            } else {
                ans[i] = q[q_size - 1] + d;
            }
            q[q_size++] = ans[i];
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }

    free(q);
    return 0;
}
