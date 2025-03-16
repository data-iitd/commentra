
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
    int *ls_rev = (int *)malloc(sizeof(int) * n);
    memcpy(ls_rev, ls, sizeof(int) * n);
    qsort(ls, n, sizeof(int), cmpfunc);
    qsort(ls_rev, n, sizeof(int), cmpfunc_rev);
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
            int l_rev = 0, r_rev = n - 1;
            while (l_rev < r_rev) {
                int mid = (l_rev + r_rev) / 2;
                if (ls_rev[mid] < y) {
                    l_rev = mid + 1;
                } else {
                    r_rev = mid;
                }
            }
            int sum = r_rev - l + 1;
            if (i >= l && i <= r) {
                sum--;
            }
            if (j >= l && j <= r) {
                sum--;
            }
            if (sum < 0) {
                sum = 0;
            }
            ans += sum;
        }
    }
    ans /= 3;
    printf("%d\n", ans);
    free(ls);
    free(ls_rev);
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int cmpfunc_rev(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// END-OF-CODE