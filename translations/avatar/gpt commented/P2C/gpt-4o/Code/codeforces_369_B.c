#include <stdio.h>
#include <stdlib.h>

void get_nums(int num, int t, int *result) {
    for (int i = 0; i < num; i++) {
        if (i < t % num) {
            result[i] = t / num + 1;
        } else {
            result[i] = t / num;
        }
    }
}

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);

    int *ans = (int *)malloc(n * sizeof(int));
    get_nums(k, sk, ans);
    get_nums(n - k, sa - sk, ans + k);

    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(ans);
    return 0;
}

// <END-OF-CODE>
