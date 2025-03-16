
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int *ls = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ls[i]);
    }

    int *lsRev = (int *)malloc(sizeof(int) * n);
    memcpy(lsRev, ls, sizeof(int) * n);

    qsort(ls, n, sizeof(int), cmpfunc);
    qsort(lsRev, n, sizeof(int), cmpfunc_rev);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = ls[i] < ls[j]? ls[i] : ls[j];
            int q = ls[i] > ls[j]? ls[i] : ls[j];
            int x = q - p;
            int y = q + p;

            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (ls[mid] > x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int l_idx = l;

            l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (lsRev[mid] < y) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            int r_idx = r;

            int sum = r_idx - l_idx + 1;
            if (i >= l_idx && i <= r_idx) {
                sum--;
            }
            if (j >= l_idx && j <= r_idx) {
                sum--;
            }
            sum = sum < 0? 0 : sum;
            ans += sum;
        }
    }

    ans /= 3;
    printf("%d\n", ans);

    free(ls);
    free(lsRev);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int cmpfunc_rev(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

