
#include <stdio.h>

void get_nums(int num, int t, int *ans) {
    // Generate a list of numbers based on the distribution of t across num parts
    for (int i = 0; i < num; i++) {
        ans[i] = t / num + 1;
        if (i < t % num) {
            ans[i]++;
        }
    }
}

int main() {
    // Read input values for n, k, l, r, sa, and sk
    int n, k, l, r, sa, sk;
    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sa, &sk);

    // Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
    int ans[n];
    get_nums(k, sk, ans);
    get_nums(n - k, sa - sk, ans + k);

    // Print the result as a space-separated string
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}

