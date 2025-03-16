
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int na(void) {
    int n, x;
    char *s;
    int *a;
    int i;

    scanf("%d", &n);
    s = malloc(n * sizeof(int));
    a = malloc(n * sizeof(int));
    scanf("%s", s);
    for (i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    free(s);
    scanf("%d", &x);
    return x;
}

int main(void) {
    int n, x;
    int *a;
    int i;
    int ans;

    n = na();
    x = na();
    a = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        a[i] = na();
    }
    qsort(a, n, sizeof(int), cmp);
    ans = 0;
    if (a[0] > x) {
        printf("0\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (a[i] > x) {
            x = 0;
            break;
        }
        x -= a[i];
        ans++;
    }
    if (x != 0) {
        ans--;
    }
    printf("%d\n", ans);
    return 0;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

