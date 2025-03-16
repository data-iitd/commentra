#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int *lst = (int *)malloc(N * sizeof(int));
    int *lst_p = (int *)malloc(N * sizeof(int));
    int *lst_m = (int *)malloc(N * sizeof(int));
    
    int count_p = 0, count_m = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
        if (lst[i] == 0) {
            K--;
        }
        if (lst[i] > 0) {
            lst_p[count_p++] = lst[i];
        } else if (lst[i] < 0) {
            lst_m[count_m++] = lst[i];
        }
    }
    
    // Sort the positive and negative lists
    qsort(lst_p, count_p, sizeof(int), compare);
    qsort(lst_m, count_m, sizeof(int), compare);
    
    int lastx = count_p;
    int lasty = count_m;

    int check(int k) {
        int ans = INT_MAX;
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {
                continue;
            } else {
                int p = (j == 0) ? 0 : lst_p[j - 1];
                int m = (k - j == 0) ? 0 : lst_m[lasty - (k - j)];
                ans = (ans < (2 * p + abs(m))) ? ans : (2 * p + abs(m));
                ans = (ans < (p + 2 * abs(m))) ? ans : (p + 2 * abs(m));
            }
        }
        return ans;
    }

    printf("%d\n", check(K));

    free(lst);
    free(lst_p);
    free(lst_m);
    
    return 0;
}

// <END-OF-CODE>
