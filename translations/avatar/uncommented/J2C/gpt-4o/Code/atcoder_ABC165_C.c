#include <stdio.h>
#include <stdlib.h>

int *a = NULL;
int *b = NULL;
int *c = NULL;
int *d = NULL;
int n = 0;
int m = 0;
int q = 0;
long ans = -100L;

void dfs(int *list, int size) {
    if (size == n) {
        long score = 0L;
        for (int i = 0; i < q; ++i) {
            score += (list[b[i]] - list[a[i]] == c[i]) ? d[i] : 0L;
        }
        if (score > ans) {
            ans = score;
        }
        return;
    }

    if (size > 0) {
        for (int num = list[size - 1]; num <= m; ++num) {
            list[size] = num;
            dfs(list, size + 1);
        }
    } else {
        for (int num = 1; num <= m; ++num) {
            list[size] = num;
            dfs(list, size + 1);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    a = (int *)malloc(q * sizeof(int));
    b = (int *)malloc(q * sizeof(int));
    c = (int *)malloc(q * sizeof(int));
    d = (int *)malloc(q * sizeof(int));
    
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i]--; // Convert to 0-based index
        b[i]--; // Convert to 0-based index
    }

    int *list = (int *)malloc(n * sizeof(int));
    dfs(list, 0);
    printf("%ld\n", ans);

    free(a);
    free(b);
    free(c);
    free(d);
    free(list);
    
    return 0;
}

// <END-OF-CODE>
