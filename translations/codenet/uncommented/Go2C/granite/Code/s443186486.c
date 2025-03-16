
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int combi(int n, int r) {
    int c = 1;
    for (int i = 1; i <= r; i++) {
        c = c * (n - i + 1) / i;
    }
    return c;
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *s = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    qsort(s, n + 1, sizeof(int), cmpfunc);

    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) {
            count++;
        } else if (count > 0) {
            ans += combi(count + 1, 2);
            count = 0;
        }
    }
    if (count > 0) {
        ans += combi(count + 1, 2);
    }

    printf("%d\n", ans);

    free(a);
    free(s);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

