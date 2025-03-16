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

    int* ans1 = get_nums(k, sk);
    int* ans2 = get_nums(n - k, sa - sk);

    for (int i = 0; i < k; i++) {
        printf("%d ", ans1[i]);
    }
    for (int i = 0; i < n - k; i++) {
        printf("%d ", ans2[i]);
    }
    printf("\n");

    free(ans1);
    free(ans2);

    return 0;
}
