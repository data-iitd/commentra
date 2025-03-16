#include <stdio.h>
#include <stdlib.h>

int* get_nums(int num, int t) {
    int* result = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        result[i] = t / num + (i < t % num ? 1 : 0);
    }
    return result;
}

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);

    int* ans = (int*)malloc((n * sizeof(int)));
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
    }

    int* sk_list = get_nums(k, sk);
    for (int i = 0; i < k; i++) {
        ans[i] = sk_list[i];
    }

    int* sa_sk_list = get_nums(n - k, sa - sk);
    for (int i = 0; i < n - k; i++) {
        ans[k + i] = sa_sk_list[i];
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    printf("\n");

    free(sk_list);
    free(sa_sk_list);
    free(ans);

    return 0;
}
