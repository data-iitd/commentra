
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    long long ans[n];
    int t, d;
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t, &d);
        while (front < rear && t >= ans[front]) {
            front++;
        }
        if (rear - front <= b) {
            ans[rear++] = t + d;
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}
//END-OF-CODE