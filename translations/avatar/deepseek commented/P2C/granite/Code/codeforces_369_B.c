
#include <stdio.h>

// This function distributes the value t among num parts.
// It calculates the base number for each part by dividing t by num.
// It adds 1 to the base number for the first t % num parts.
int *get_nums(int num, int t) {
    int *ans = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++) {
        ans[i] = t / num + (i < t % num? 1 : 0);
    }
    return ans;
}

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sa, &sk);

    // Use the get_nums function to calculate the distribution of sk and sa - sk
    int *ans = get_nums(k, sk);
    for (int i = 0; i < k; i++) {
        printf("%d ", ans[i]);
    }
    free(ans);

    ans = get_nums(n - k, sa - sk);
    for (int i = 0; i < n - k; i++) {
        printf("%d ", ans[i]);
    }
    free(ans);

    printf("\n");

    return 0;
}

