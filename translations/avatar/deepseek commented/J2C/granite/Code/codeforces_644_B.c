

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    int *ans = (int *)malloc(n * sizeof(int));
    int *q = (int *)malloc(b * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);

        while (front < rear && q[front] <= t) {
            front++;
        }

        if (rear - front <= b) {
            ans[i] = (front == 0? t : q[rear - 1]) + d;
            q[rear++] = ans[i];
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    free(ans);
    free(q);
    return 0;
}
