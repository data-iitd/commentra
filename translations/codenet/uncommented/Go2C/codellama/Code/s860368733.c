#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    int a, b;
    int counter[n];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (h[a-1] < h[b-1]) {
            counter[a] = 1;
        } else if (h[a-1] > h[b-1]) {
            counter[b] = 1;
        } else if (h[a-1] == h[b-1]) {
            counter[a] = 1;
            counter[b] = 1;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (counter[i] == 0) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

