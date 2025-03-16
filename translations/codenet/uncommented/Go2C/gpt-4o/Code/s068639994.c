#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *ls = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ls[i]);
    }

    int *lsRev = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        lsRev[i] = ls[i];
    }

    qsort(ls, n, sizeof(int), compare);
    qsort(lsRev, n, sizeof(int), compare);
    for (int i = 0; i < n / 2; i++) {
        int temp = lsRev[i];
        lsRev[i] = lsRev[n - 1 - i];
        lsRev[n - 1 - i] = temp;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            int x = q - p;
            int y = q + p;

            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (ls[mid] > x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int leftIndex = l;

            l = 0, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (lsRev[mid] < y) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            int rightIndex = n - l;

            long long sum = rightIndex - leftIndex;
            if (i >= leftIndex && i < rightIndex) {
                sum--;
            }
            if (j >= leftIndex && j < rightIndex) {
                sum--;
            }
            sum = max(0, sum);
            ans += sum;
        }
    }

    ans /= 3;
    printf("%lld\n", ans);

    free(ls);
    free(lsRev);
    return 0;
}

// <END-OF-CODE>
