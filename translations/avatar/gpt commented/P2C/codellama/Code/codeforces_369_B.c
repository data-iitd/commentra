#include <stdio.h>

int get_nums(int num, int t) {
    // Generate a list of numbers based on the distribution of t across num parts
    int i, ans[num];
    for (i = 0; i < num; i++) {
        if (i < t % num) {
            ans[i] = t / num + 1;
        } else {
            ans[i] = t / num;
        }
    }
    return ans[num];
}

int main() {
    // Read input values for n, k, l, r, sa, and sk
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);

    // Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
    int ans[k + n - k];
    for (int i = 0; i < k; i++) {
        ans[i] = get_nums(k, sk);
    }
    for (int i = k; i < k + n - k; i++) {
        ans[i] = get_nums(n - k, sa - sk);
    }

    // Print the result as a space-separated string
    for (int i = 0; i < k + n - k; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}

