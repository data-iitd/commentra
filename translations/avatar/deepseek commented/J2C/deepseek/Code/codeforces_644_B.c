#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    long long ans[n];
    int q[b];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);

        while (front != rear && q[front] <= t) {
            front++;
        }

        if (rear - front < b) {
            ans[i] = (front == rear ? t : q[rear - 1]) + d;
            q[rear++] = ans[i];
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }

    return 0;
}

